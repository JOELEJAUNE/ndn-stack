#include "bigdata-compute.hpp"

#include "ns3/ptr.h"
#include "ns3/log.h"
#include "ns3/simulator.h"
#include "ns3/packet.h"
#include "ns3/callback.h"
#include "ns3/string.h"
#include "ns3/boolean.h"
#include "ns3/uinteger.h"
#include "ns3/integer.h"
#include "ns3/double.h"

#include "helper/ndn-fib-helper.hpp"
//#include "model/ndn-app-face.hpp"
#include "model/ndn-app-link-service.hpp"

#include "model/ndn-ns3.hpp"
#include "ns3/node.h"
#include "model/ndn-l3-protocol.hpp"
#include "helper/ndn-fib-helper.hpp"
#include <sstream>
#include <memory>

#include "ns3/log.h"
#include "ns3/simulator.h"

//#include "helper/ndn-global-routing-helper.hpp"
#include "ns3/ndnSIM-module.h"

#include <string>

#include <vector>
#include <iterator>
#include <iostream>
    #include <boost/algorithm/string.hpp>


NS_LOG_COMPONENT_DEFINE("ndn.Compute");



namespace ns3 {
namespace ndn {

NS_OBJECT_ENSURE_REGISTERED(Compute);

TypeId
Compute::GetTypeId(void)
{
	static TypeId tid =
			TypeId("ns3::ndn::Compute")
			.SetGroupName("Ndn")
			.SetParent<App>()
			.AddConstructor<Compute>()

			.AddAttribute("PrefixCommand", "Prefix, for which the Compute has the data", StringValue("/"),
					MakeNameAccessor(&Compute::m_prefix_command), MakeNameChecker())
					// .AddAttribute("PrefixData", "Prefix, for which producer has the data", StringValue("/"),
					//              MakeNameAccessor(&Compute::m_prefix_data), MakeNameChecker())
					;

	return tid;
}

Compute::Compute()
{
}

Compute::~Compute()
{
}

Ptr<Node> Compute::getNode() const {
	return GetNode();
}
// inherited from Application base class.
void
Compute::StartApplication()
{
	NS_LOG_FUNCTION_NOARGS();
	App::StartApplication();

	
	NS_LOG_INFO("COMPUTE node(" << GetNode()->GetId() << ") Advertizing prefix " << m_prefix_command );
	FibHelper::AddRoute(GetNode(), m_prefix_command, m_face, 0);
	ndn::GlobalRoutingHelper ndnGlobalRoutingHelper;
	NodeContainer nodes;
	nodes.Add(GetNode());
	ndnGlobalRoutingHelper.AddOrigins(m_prefix_command.toUri(),nodes );
	ndn::GlobalRoutingHelper::CalculateRoutes();
	m_freshness = Seconds (10.0);
	NS_LOG_INFO("COMPUTE node(" << GetNode()->GetId() << ") Compute application started ");
}

void
Compute::StopApplication()
{
	NS_LOG_FUNCTION_NOARGS();

	NS_LOG_INFO("COMPUTE node(" << GetNode()->GetId() << ") Compute application Stopping "  );

	for (std::list<DataConsumer*>::iterator it=consumers.begin(); it!=consumers.end(); ++it){
		delete (*it);
		consumers.erase(it);
	}
	App::StopApplication();
	NS_LOG_INFO("COMPUTE node(" << GetNode()->GetId() << ") Compute application stopped "  );
}

void Compute::OnDataRetrieved(DataConsumer* consumer){
	NS_LOG_INFO("COMPUTE node(" << GetNode()->GetId() << ") Data packet received " << consumer->getInterestName().toUri() );
	if (!m_active){
		NS_LOG_INFO("COMPUTE node(" << GetNode()->GetId() << ") Compute NOT active ignoring the packet " << consumer->getInterestName().toUri() );
		return;
	}

	if(!consumer->isCommand()){
		// consumer->getInterestName()  /lacl/data ?
		NS_LOG_DEBUG("COMPUTE node(" << GetNode()->GetId() << ") Data file " << consumer->getInterestName().toUri() <<" advertised and stored on the local storage" );
		FibHelper::AddRoute(GetNode(), consumer->getInterestName(), m_face , 0);
		ndn::GlobalRoutingHelper ndnGlobalRoutingHelper;
		NodeContainer nodes;
		nodes.Add(GetNode());
		ndnGlobalRoutingHelper.AddOrigins(consumer->getInterestName().toUri(), nodes);
		ndn::GlobalRoutingHelper::CalculateRoutes();

	}else {

	}

	if (consumer->isNeedsAction()) {
        if(consumer->isStopInterestDone()==false){
            consumer->setStopInterestDone(true); //use to avoid sending stop interest by more than one node storage
            std::string stop	= consumer->getInterestName().toUri()+"/stop/0/"+std::to_string(consumer->getSeqMax() - 1);
            NS_LOG_INFO("COMPUTE node(" << GetNode()->GetId() << ") Creating a Stop command Consumer " << stop );
            DataConsumer* dataConsumer = new DataConsumer(new  AppWrapperTemplate<Compute*> (this), stop);
            dataConsumer->processCommand();
		//Simulator::Schedule(Seconds(0.0), &Compute::SendInterest, this, dataprefix);
		}

	}


	NS_LOG_DEBUG("COMPUTE node(" << GetNode()->GetId() << ") Cleaning the Consumer "<< consumer->getInterestName().toUri() );
	consumers.remove(consumer);
	delete consumer;



}

void
Compute::OnTimeout(DataConsumer* consumer)
{

	NS_LOG_DEBUG("COMPUTE node(" << GetNode()->GetId() << ") timeout for: "<< consumer->getInterestName().toUri() );


	//check the interest timed out; if reduce, declare the node as a reducer

	if(consumer->getInterestName().toUri().find("reduce") != std::string::npos){

		
		std::string reduce = consumer->getInterestName().toUri();


		FibHelper::AddRoute(GetNode(), reduce, m_face , 0);
		ndn::GlobalRoutingHelper ndnGlobalRoutingHelper;
		NodeContainer nodes;
		nodes.Add(GetNode());
		ndnGlobalRoutingHelper.AddOrigins(reduce, nodes);
		ndn::GlobalRoutingHelper::CalculateRoutes();

		NS_LOG_DEBUG("COMPUTE node(" << GetNode()->GetId() << ") advertizing "<< reduce );

		// add advertized name to the advertized name
		adList.push_front(reduce);

		//retrieve the initial command
		std::string suffix = "/heartbeat/reduce";
		std::string val = reduce.erase(reduce.find(suffix));


	    std::string code;
	    std::string data;
	   	std::vector<std::string> part;
	   	
	    boost::split(part, val, boost::is_any_of("/"));

	    code = "/" + part[1] + "/" + part[2];
	    data = "/" + part[3] + "/" + part[4];

	    //lookup to find a way to retrieve the command
	    std::string cmd;

	    for (std::list<string>::iterator it=requestList.begin(); it!=requestList.end(); ++it){

			std::string command = *it;
			std::size_t place = command.find(data);
			
			
			if (place!=std::string::npos) {
					NS_LOG_INFO("The command to deal with is : " << command);
					cmd = command;

					//std::string res = cmd.erase(cmd.find("/%FE%00"));

					std::vector<std::string> vec = nameSplit(cmd);

					std::string minSeg = vec[4];
					std::string maxSeg = vec[5];
					
					for(int i=stoi(minSeg); i <= stoi(maxSeg); i++){

						std::string toSend = code + data + "/" + to_string(i) + "/" + maxSeg + "/map/" + to_string(i);

						//prepare to send an interest to retrieve the data

						DataConsumer* dataConsumer = new DataConsumer(new  AppWrapperTemplate<Compute*> (this), toSend);
						dataConsumer->setSeqMax(1);
						consumers.push_front (dataConsumer);
						Simulator::Schedule(Seconds(0.0), &DataConsumer::SendPacket, dataConsumer); 
					}
					
			}
		}

		



		//call the reduce function; ; ; 
		//reduceFunction();



		consumers.remove(consumer);
        delete consumer;
	}
    /*
    //if heartbeat send the replication request
    if(consumer->getInterestName().toUri().find("heartbeat") != std::string::npos){

        NS_LOG_INFO("COMPUTE node(" << GetNode()->GetId() << ") heartbeat timeout for " << consumer->getInterestName().toUri() );

        //string heartbeatFactor(1, consumer->getInterestName().toUri().at( consumer->getInterestName().toUri().length() - 1 ));
            string heartbeatFactor(consumer->getInterestName().toUri().substr(consumer->getInterestName().toUri().find_last_of("/")+1));                                   //get the replication factor from the InterestName

        string dataPrefix = consumer->getInterestName().toUri().substr(0, consumer->getInterestName().toUri().find("heartbeat") - 1); //get the dataPrefix from the heartbeat interest

        std::string replicationPrefix(m_prefix_command.toUri()+"/"+std::to_string(m_rep_factor)+"/"+heartbeatFactor+dataPrefix+"/0/"+std::to_string(m_last_segment));


        NS_LOG_INFO("COMPUTE node(" << GetNode()->GetId() << ") Forwarding the replication command " << replicationPrefix );

        DataConsumer* repConsumer = new DataConsumer(new  AppWrapperTemplate<Compute*> (this), replicationPrefix);
        repConsumer->processCommand();
        consumers.remove(consumer);
        delete consumer;


    }else{

        //if storage request; check the heartbeat related to; when this interest will timeout, the replication will be sent
        if(consumer->getInterestName().toUri().find("storage") != std::string::npos){

            string suffix ="/%FE%00";

            ComputeInfo storageInfo(consumer->getInterestName().toUri() + suffix, m_prefix_command.toUri());

            std::string heartbeatPrefix(storageInfo.getDataPrefix()+"/heartbeat/"+storageInfo.getReplication());

            NS_LOG_INFO("COMPUTE node(" << GetNode()->GetId() << ") check for the replication using heatbeat interest " << heartbeatPrefix << " before sending replication");

            DataConsumer* heatConsumer = new DataConsumer(new  AppWrapperTemplate<Compute*> (this), heartbeatPrefix);
            heatConsumer->processCommand();
            consumers.remove(consumer);
            delete consumer;

        }
    }
*/

}

void
Compute::OnData(shared_ptr<const Data> data)
{
	NS_LOG_DEBUG("COMPUTE node(" << GetNode()->GetId() << ") Data packet received " << data->getName().toUri() );
	if (!m_active){
		NS_LOG_INFO("COMPUTE node(" << GetNode()->GetId() << ") Compute NOT active ignoring the packet " << data->getName().toUri() );
		return;
	}
	App::OnData(data); // tracing inside



	bool consumed = false;
	for (std::list<DataConsumer*>::iterator it=consumers.begin(); it!=consumers.end(); ++it){
		if((*it)->OnData(data) == 1){
			NS_LOG_DEBUG("COMPUTE node(" << GetNode()->GetId() << ") Data consumed by  " << (*it)->getInterestName().toUri() );
			consumed = true;
			break;
		}
	}
	//check if it's the code ,apply the timer

	for (std::list<string>::iterator it=requestList.begin(); it!=requestList.end(); ++it){

		std::string command = *it;
		std::size_t place = command.find(data->getName().toUri());
		
		
		if (place!=std::string::npos) {
				NS_LOG_INFO("Code received. Start computation for: " << command);

				//call compute;
				makeCompute(command);
		}
	}

	
	if(!consumed){
		NS_LOG_INFO("COMPUTE node(" << GetNode()->GetId() << ") No consumer for data packet  " << data->getName().toUri() );
	}else{
		
			//manage the computation for the reduce
		if (boost::algorithm::contains(data->getName().toUri(),"/map")) {

			reduceComputation(data->getName().toUri());

		}
	}


}
void Compute::SendInterest(std::string prefix) {
	NS_LOG_DEBUG("COMPUTE node(" << GetNode()->GetId() << ") Request for sending Interest " << prefix );
	if (!m_active){
		NS_LOG_INFO("COMPUTE node(" << GetNode()->GetId() << ") Compute NOT active ignoring the request " << prefix );
		return;
	}
	/////////////////////////////////////
	// Sending one Interest packet out //
	/////////////////////////////////////

	// Create and configure ndn::Interest
	auto interest = std::make_shared<ndn::Interest>(prefix);
	Ptr<UniformRandomVariable> rand = CreateObject<UniformRandomVariable>();
	interest->setNonce(rand->GetValue(0, std::numeric_limits<uint32_t>::max()));
	interest->setInterestLifetime(ndn::time::seconds(10));


	//set the mustbeFresh to true if the Interest is a storage, heartbeat or stop

	/*if((prefix.find("heartbeat") != std::string::npos)||(prefix.find("storage") != std::string::npos)||(prefix.find("stop") != std::string::npos)){

        interest->setMustBeFresh(true);

	}
*/
	NS_LOG_DEBUG("COMPUTE node(" << GetNode()->GetId() << ") Sending Interest packet for " << *interest);

	// Call trace (for logging purposes)
	m_transmittedInterests(interest, this, m_face);

//	m_face->onReceiveInterest(*interest);
	m_appLink->onReceiveInterest(*interest);

}


void Compute::OnInterest(shared_ptr<const Interest> interest) {
	NS_LOG_INFO("COMPUTE node(" << GetNode()->GetId() << ") Interest packet received " << interest->getName().toUri() );
	if (!m_active){
		NS_LOG_INFO("COMPUTE node(" << GetNode()->GetId() << ") Compute NOT active ignoring the packet " << interest->getName().toUri() );
		return;
	}

	App::OnInterest(interest); // tracing inside



	//check interest for reduce; the interest needs to be in the list
	bool inside=false;
	//check the list

		for (std::list<string>::iterator it=adList.begin(); it!=adList.end(); ++it){

			std::string inte = *it;

			std::size_t place = interest->getName().toUri().find(inte);
			
			//NS_LOG_DEBUG(inte);
			//NS_LOG_DEBUG(interest->getName().toUri());
			
			if (place!=std::string::npos) {

				inside = true;
				//NS_LOG_DEBUG("reduce interest");

			}
		}

		if(interest->getName().toUri().find("reduce")!=std::string::npos){

			if(!inside){

				NS_LOG_DEBUG("COMPUTE node(" << GetNode()->GetId() << ") Ignoring reduce interest " << interest->getName().toUri());
				return ;
			}
		
		}

		if ((!inside)&&(interest->getName().toUri().find(m_prefix_command.toUri()) != 0)) {
			// case3: /autre/chose
			NS_LOG_INFO("COMPUTE node(" << GetNode()->GetId() << ") Ignoring unrecognized interest " << interest->getName().toUri()
					<< " against " << m_prefix_data.toUri());
			return ;
		}
	/*	if(!inside){

			NS_LOG_DEBUG("COMPUTE node(" << GetNode()->GetId() << ") Ignoring interest " << interest->getName().toUri());
			return ;
		}
*/
/*	if(interest->getName().toUri().find("reduce")!=std::string::npos){

		return ;
		
	}*/

	/*else if (interest->getName().toUri().find(m_prefix_data.toUri()) != 0
			&& interest->getName().toUri().find(m_prefix_command.toUri()) != 0) {
		// case3: /autre/chose
		NS_LOG_INFO("COMPUTE node(" << GetNode()->GetId() << ") Ignoring unrecognized interest " << interest->getName().toUri()
				<< " against " << m_prefix_data.toUri());
		return ;
	}
		*/
	OnInterestResponse(interest);

	std::string prefix = m_prefix_command.toUri();
	std::size_t place = interest->getName().toUri().find("compute"); //interest->getName().toUri().find(prefix); can't be applied for all prefixes, but only for compute
	//check if the request is a compute command, send interest for the code; compute and send the next compute request interest; 
	NS_LOG_INFO("COMPUTE info interestName :" << interest->getName().toUri()) ;
	
	if (place!=std::string::npos) {

        NS_LOG_DEBUG("COMPUTE node(" << GetNode()->GetId() << ") Interest is a compute command " << interest->getName().toUri() );
       
       // Save the command in the list for management purpose, we will use a table in future

        requestList.push_front(interest->getName().toUri());


        //call nameComponent to split the name; 

        std::vector<std::string> comp;
        std::string name = interest->getName().toUri();

		

        //extract the code name to prepare the interest to send let's call the function
        comp = nameSplit(name);
        
        // comp[1] ="/";
		// comp[2] ="/";
		//comp[3] ="/";

        std::string code;
        std::string dataN;
        std::string pref;
        std::string dataIndex;

        pref = comp[1];
		dataN = comp[2] ;
		code = comp[3];
		dataIndex = comp[6];

		//send the code request; 
		//NS_LOG_DEBUG("code " << code);
		//NS_LOG_DEBUG("DataN " << dataN);

		//prepare to send an interest for the code

		DataConsumer* dataConsumer = new DataConsumer(new  AppWrapperTemplate<Compute*> (this), code);
		dataConsumer->setSeqMax(1);
		consumers.push_front (dataConsumer);
		Simulator::Schedule(Seconds(0.0), &DataConsumer::SendPacket, dataConsumer);  //Need a blocking method to be able to exploit the code in order to make the computation

		//prepare to send the next compute request if minSeg < maxSeg

		int minSeg = stoi(comp[4]);
		int maxSeg = stoi(comp[5]);

		if (minSeg<maxSeg)
		{
		
			std::string nextRequest;
			minSeg = minSeg+1;
			//nextRequest = prefix + "/" + part[3] + "/" + part[4] + "/" + std::to_string(minSeg) + "/" + part[6] + "/" + part[7] + "/" + part[8];//code;
			nextRequest = pref + dataIndex + "/" + std::to_string(minSeg) + "/" + comp[5] + code ;//part[7] + "/" + part[8];//code;

			//NS_LOG_DEBUG("nextRequest " << nextRequest);

			DataConsumer* dataConsumer1 = new DataConsumer(new  AppWrapperTemplate<Compute*> (this), nextRequest);
			dataConsumer1->setSeqMax(1);
			consumers.push_front (dataConsumer1);
			Simulator::Schedule(Seconds(0.0), &DataConsumer::SendPacket, dataConsumer1);
		}

		//Send request to retrieve data if necessary

		//std::string dataN = part[3] + "/" + part[4] + "/" + std::to_string(minSeg) + "/" + part[6];
		
		DataConsumer* dataConsumer2 = new DataConsumer(new  AppWrapperTemplate<Compute*> (this), dataN);
		dataConsumer2->setSeqMax(1);
		consumers.push_front (dataConsumer2);
		Simulator::Schedule(Seconds(0.0), &DataConsumer::SendPacket, dataConsumer2);


	}

}



void Compute::OnInterestResponse(shared_ptr<const Interest> interest) {
	//verifier si entre 0 et lastSegment

	//si /stop/0/lastSegment remove advertise and return null
	Name dataName(interest->getName());
	// dataName.append(m_postfix);
	// dataName.appendVersion();

	auto data = make_shared<Data>();
	data->setName(dataName);
	data->setFreshnessPeriod(
			::ndn::time::milliseconds(m_freshness.GetMilliSeconds()));

    //set the freshnessPeriod to 1ms if the data is a storage, heartbeat or stop

	if((interest->getName().toUri().find("heartbeat") != std::string::npos)||(interest->getName().toUri().find("storage") != std::string::npos)||(interest->getName().toUri().find("stop") != std::string::npos)){

	data->setFreshnessPeriod(::ndn::time::milliseconds(1));

	}



	data->setContent(make_shared < ::ndn::Buffer > (m_virtualPayloadSize));
	NS_LOG_DEBUG("COMPUTE node(" << GetNode()->GetId() << ") Preparing the data packet to serve "<< data->getName().toUri());

	Signature signature;
	SignatureInfo signatureInfo(
			static_cast<::ndn::tlv::SignatureTypeValue>(255));

	if (m_keyLocator.size() > 0) {
		signatureInfo.setKeyLocator(m_keyLocator);
	}

	signature.setInfo(signatureInfo);
	signature.setValue(
			::ndn::nonNegativeIntegerBlock(::ndn::tlv::SignatureValue,
					m_signature));

	data->setSignature(signature);

	//

	// to create real wire encoding
	data->wireEncode();

	setTransmittedDatas(data);
//	m_face->onReceiveData(*data);
	m_appLink->onReceiveData(*data);
	//state = &(state->OnInterest(interest));
	NS_LOG_DEBUG("COMPUTE node(" << GetNode()->GetId() << ") responding with Data: " << data->getName());
}

void
Compute::ScheduleNextHeartBeat(string name)
{

  if (m_firstTime) {
    m_sendEvent = Simulator::Schedule(Seconds(0.0), &Compute::sendHeartBeat, this, name);
    m_firstTime = false;
  }
  else if (!m_sendEvent.IsRunning())
    m_sendEvent = Simulator::Schedule(Seconds(10),  &Compute::sendHeartBeat, this, name);
}

void
Compute::sendHeartBeat(string name)
{

    NS_LOG_INFO("COMPUTE node(" << GetNode()->GetId() << ") check for the next replication using heatbeat interest " << name );

    DataConsumer* heatConsumer = new DataConsumer(new  AppWrapperTemplate<Compute*> (this), name);
    heatConsumer->processCommand();

    ScheduleNextHeartBeat(name);

}


void
Compute::makeCompute(string name)
{

    NS_LOG_INFO("COMPUTE node(" << GetNode()->GetId() << ") start computation " << name);

    //simulation for the computation

    
    NS_LOG_INFO("COMPUTE node(" << GetNode()->GetId() << ") computation done" << name);


     //extract the code name to prepare the interest to send let's call the function

	std::vector<std::string> comp;
    std::string dataName;
    std::string code;
    std::string seg;
    std::string dataIndex;

   	comp = nameSplit(name);

   	dataName = comp[2];
   	code = comp[3];
	seg = comp[4];
	dataIndex = comp[6];
	//Advertise the result using the name: /domain/code/name/domain/data/map/1
	std::string result = code + dataName + "/" + "map" + "/" + seg;

	NS_LOG_DEBUG("COMPUTE node(" << GetNode()->GetId() << ") advertise map result:  " << result);
	FibHelper::AddRoute(GetNode(), result, m_face , 0);
	ndn::GlobalRoutingHelper ndnGlobalRoutingHelper;
	NodeContainer nodes;
	nodes.Add(GetNode());
	ndnGlobalRoutingHelper.AddOrigins(result, nodes);
	ndn::GlobalRoutingHelper::CalculateRoutes();

	// add advertized name to the advertized name
	adList.push_front(result);

	 //check for the heartbeat computation
     //		/domain/code/domain/data/heartbeat/reduce/


	std::string heart = code + dataIndex + "/heartbeat/reduce";

	NS_LOG_DEBUG("COMPUTE node(" << GetNode()->GetId() << ") sending interest for the reduce heartbeat:  " << heart);

	DataConsumer* dataConsumer = new DataConsumer(new  AppWrapperTemplate<Compute*> (this), heart);
	dataConsumer->setSeqMax(1);
	consumers.push_front (dataConsumer);
	Simulator::Schedule(Seconds(0.0), &DataConsumer::SendPacket, dataConsumer);


}

std::vector<std::string> Compute::nameSplit(std::string name){

	std::vector<std::string> val(10);
    std::string code;
    
   	std::vector<std::string> part;
   	std::string rest = name;
    


    boost::split(part, rest, boost::is_any_of("/"));
    //vector contains:
    //5 segBegin; 6 segLast

	size_t found = rest.find_last_of("/");
	size_t t;
	if(part[5]!=part[6]){
	   t =rest.find(part[6]);
	   
	   std::string tmp = rest.substr(t+part[6].size(), found);
	   //std::cout << "value :" << tmp;
	   code = tmp.erase(tmp.find_first_of("%"));
	   code = code.erase(code.find_last_of("/"));
	   
	}else
	{
	     t = rest.find(part[6]);
	     std::string inter = rest.substr(t, found);
	     size_t a = inter.find("/"+part[6]);
	    // std::cout << "value :" <<  <<std::endl;
	     
	     std::string tmp = inter.substr(a+part[6].size()+1);
	   //std::cout << "value :" << tmp;
	   code = tmp.erase(tmp.find_first_of("%"));
	   code = code.erase(code.find_last_of("/"));
	}

	std::string dataN = "/" + part[3] + "/" + part[4] + "/" + part[5] + "/" + part[6];

	std::string prefix = "/" + part[1] + "/" + part[2];
	std::string dataIndex = "/" + part[3] + "/" + part[4];

	//prefix is at 1; data name at 2; 4 minSeg; 5 maxSeg;
	val.at(1) = prefix;
	val.at(2) = dataN;
	val.at(3) = code;
	val.at(4) = part[5];
	val.at(5) = part[6];
	val.at(6) = dataIndex;


	return val;
}

void
Compute::reduceComputation(std::string name){


	NS_LOG_DEBUG("COMPUTE node(" << GetNode()->GetId() << ") reduce in progress");

	//split the map
	std::vector<std::string> part;
   	std::string rest = name;
    boost::split(part, rest, boost::is_any_of("/"));

    int total = stoi(part[6]);


    if(mapList.size()==total){

    	NS_LOG_DEBUG("COMPUTE node(" << GetNode()->GetId() << ") reduce complete;");

    	//prepare to advertise
    	// /domain/code/domain/data/reduce/

    	std::string ntd = "" + part[1] + "/" + part[2] + "/" + part[3] + "/" + part[4] + "/reduce";



    	NS_LOG_DEBUG("COMPUTE node(" << GetNode()->GetId() << ") advertize : " << ntd);

	    FibHelper::AddRoute(GetNode(), ntd, m_face , 0);
		ndn::GlobalRoutingHelper ndnGlobalRoutingHelper;
		NodeContainer nodes;
		nodes.Add(GetNode());
		ndnGlobalRoutingHelper.AddOrigins(ntd, nodes);
		ndn::GlobalRoutingHelper::CalculateRoutes();

    	mapList.push_back("complete");


    }else if(mapList.size()<total) {

    	mapList.push_front(name);

    }




}


/*

template<typename Out>
void spliting(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> spliting(const std::string &s, char delim) {
    std::vector<std::string> elems;
    spliting(s, delim, std::back_inserter(elems));
    return elems;
}

*/


} // namespace ndn
} // namespace ns3
