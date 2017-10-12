#include "bigdata-client.hpp"
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

//#include "model/ndn-app-face.hpp"
#include "model/ndn-app-link-service.hpp"
#include "helper/ndn-fib-helper.hpp"

//#include "helper/ndn-global-routing-helper.hpp"
#include "ns3/ndnSIM-module.h"
NS_LOG_COMPONENT_DEFINE("ndn.Client");

namespace ns3 {
namespace ndn {

NS_OBJECT_ENSURE_REGISTERED(Client);

TypeId
Client::GetTypeId(void)
{
	static TypeId tid =
			TypeId("ns3::ndn::Client")
			.SetGroupName("Ndn")
			.SetParent<App>()
			.AddConstructor<Client>()
//We need to know : .The code to apply; the data on which the code will be applied;  
		/*	.AddAttribute("ReplicationFactor", "Replication factor of the command", IntegerValue(3),
					MakeIntegerAccessor(&Client::m_rep_factor), MakeIntegerChecker<uint32_t>())*/

					.AddAttribute("LastSegment", "Last segment of the data", IntegerValue(9),
							MakeIntegerAccessor(&Client::m_last_segment), MakeIntegerChecker<uint32_t>())

							.AddAttribute("PrefixCommand", "This represent the command to be executed", StringValue("/"),
									MakeNameAccessor(&Client::m_prefix_command), MakeNameChecker())
							.AddAttribute("PrefixCode", "This represent the code for the computation", StringValue("/"),
									MakeNameAccessor(&Client::m_prefix_code), MakeNameChecker())
									.AddAttribute("PrefixData", "Prefix, the client will request the computation", StringValue("/"),
											MakeNameAccessor(&Client::m_prefix_data), MakeNameChecker())
											;

	return tid;
}

Client::Client()
{

}

Client::~Client()
{

}
Ptr<Node> Client::getNode() const {
	return GetNode();
}
// inherited from Application base class.
void
Client::StartApplication()
{
	NS_LOG_FUNCTION_NOARGS();
	App::StartApplication();
	//std::string prefix(m_prefix_command.toUri()+"/"+std::to_string(m_rep_factor)+m_prefix_data.toUri()+"/0/"+std::to_string(m_last_segment));

	//    std::string heartbeatName(m_prefix_data.toUri()+"/heartbeat/"+std::to_string(m_rep_factor)); //heartbeat

	//    NS_LOG_INFO("CLIENT node(" << GetNode()->GetId() << ") Advertizing prefix " << m_prefix_data );
	//    Name stop(m_prefix_data.toUri()+"/stop/0/"+std::to_string(m_last_segment));
	//this->state = new ClientFirstState(*this, GetNode(), cmd, m_prefix_data);
	/* FibHelper::AddRoute(GetNode(), m_prefix_data, m_face , 0);
	FibHelper::AddRoute(GetNode(), stop, m_face , 0);
	ndn::GlobalRoutingHelper ndnGlobalRoutingHelper; */
	/* NodeContainer nodes;
		nodes.Add(GetNode());
		ndnGlobalRoutingHelper.AddOrigins(m_prefix_data.toUri(), nodes);
		ndnGlobalRoutingHelper.AddOrigins(stop.toUri(), nodes);
		ndn::GlobalRoutingHelper::CalculateRoutes(); */
	m_freshness = Seconds (10.0);

	/* NS_LOG_DEBUG("CLIENT node(" << GetNode()->GetId() << ") Creating a Data Consumer " << heartbeatName );
	DataConsumer* dataConsumer = new DataConsumer(new  AppWrapperTemplate<Client*> (this), heartbeatName);
	dataConsumer->setSeqMax(1);
	consumers.push_front (dataConsumer);
	Simulator::Schedule(Seconds(0.0), &DataConsumer::SendPacket, dataConsumer);
	//Simulator::Schedule(Seconds(0.0), &Storage::SendInterest, this, dataprefix);
	*/
	NS_LOG_INFO("node(" << GetNode()->GetId() << ") Client application started ");
	this->StartComputeRequest();

}

void
Client::StartComputeRequest()
{
	//	/domain/compute /domain/data/1/2/domain/code

	NS_LOG_INFO("node(" << GetNode()->GetId() << ") Client starting computation request");

	std::string requestName(m_prefix_command.toUri()+m_prefix_data.toUri()+"/0/"+std::to_string(m_last_segment)+m_prefix_code.toUri());

	NS_LOG_DEBUG("CLIENT node(" << GetNode()->GetId() << ") sending computation: " << requestName);

	NS_LOG_DEBUG("CLIENT node(" << GetNode()->GetId() << ") Creating a Data Consumer " << requestName);

	DataConsumer* dataConsumer = new DataConsumer(new  AppWrapperTemplate<Client*> (this), requestName);
	dataConsumer->setSeqMax(1);
	consumers.push_front (dataConsumer);
	Simulator::Schedule(Seconds(0.0), &DataConsumer::SendPacket, dataConsumer);
}


void
Client::StopApplication()
{
	NS_LOG_FUNCTION_NOARGS();
	NS_LOG_INFO("node(" << GetNode()->GetId() << ") Client application Stopping "  );
	App::StopApplication();
	for (std::list<DataConsumer*>::iterator it=consumers.begin(); it!=consumers.end(); ++it){
		delete (*it);
		consumers.erase(it);
	}
	NS_LOG_INFO("node(" << GetNode()->GetId() << ") Client application stopped "  );



}

void Client::OnDataRetrieved(DataConsumer* consumer){
	NS_LOG_INFO("CLIENT node(" << GetNode()->GetId() << ") Data packet received " << consumer->getInterestName().toUri() );
	if (!m_active){
		NS_LOG_INFO("CLIENT node(" << GetNode()->GetId() << ") Client NOT active ignoring the packet " << consumer->getInterestName().toUri() );
		return;
	}
	NS_LOG_DEBUG("CLIENT node(" << GetNode()->GetId() << ") Command executed succesfully " << consumer->getInterestName().toUri() );
	consumers.remove(consumer);
	delete consumer;
}


void Client::OnTimeout(DataConsumer* consumer){

	NS_LOG_INFO("CLIENT node(" << GetNode()->GetId() << ") request timeouted out " << consumer->getInterestName().toUri() );

     string heartbeatFactor(consumer->getInterestName().toUri().substr(consumer->getInterestName().toUri().find_last_of("/") +1, consumer->getInterestName().toUri().size() )); //get the replication factor from the InterestName

    consumers.remove(consumer);
    delete consumer;
}



void 
Client::SendInterest(std::string prefix) {

	NS_LOG_DEBUG("CLIENT node(" << GetNode()->GetId() << ") Request for sending Interest " << prefix );
	if (!m_active){
		NS_LOG_DEBUG("CLIENT node(" << GetNode()->GetId() << ") Client NOT active ignoring the request " << prefix );
		return;
	}
	/////////////////////////////////////
	// Sending one Interest packet out //
	/////////////////////////////////////

	// Create and configure ndn::Interest
	auto interest = std::make_shared<ndn::Interest>(prefix);
	Ptr<UniformRandomVariable> rand = CreateObject<UniformRandomVariable>();
	interest->setNonce(rand->GetValue(0, std::numeric_limits<uint32_t>::max()));
	interest->setInterestLifetime(ndn::time::seconds(1));
	
	NS_LOG_DEBUG("CLIENT node(" << GetNode()->GetId() << ") Sending Interest packet for " << *interest);

	// Call trace (for logging purposes)
	m_transmittedInterests(interest, this, m_face);

	//m_face->onReceiveInterest(*interest);
	m_appLink->onReceiveInterest(*interest);
}

void
Client::OnData(shared_ptr<const Data> data)
{
	NS_LOG_INFO("CLIENT node(" << GetNode()->GetId() << ") Data packet received " << data->getName().toUri() );
	if (!m_active){
		NS_LOG_INFO("CLIENT node(" << GetNode()->GetId() << ") Client NOT active ignoring the packet " << data->getName().toUri() );
		return;
	}


	App::OnData(data); // tracing inside



	bool consumed = false;
	for (std::list<DataConsumer*>::iterator it=consumers.begin(); it!=consumers.end(); ++it){
		if((*it)->OnData(data) == 1){
			NS_LOG_DEBUG("node(" << GetNode()->GetId() << ") Data packet ACK received and consumed by  " << (*it)->getInterestName().toUri() );
			consumed = true;
			break;
		}
	}
	if(!consumed){
		NS_LOG_INFO("node(" << GetNode()->GetId() << ") No consumer for data packet  " << data->getName().toUri() );
	}

}


void Client::OnInterest(shared_ptr<const Interest> interest) {

    NS_LOG_INFO("CLIENT node(" << GetNode()->GetId() << ") Interest packet received  " << interest->getName().toUri() );
	if (!m_active){
		NS_LOG_INFO("CLIENT node(" << GetNode()->GetId() << ") Client NOT active ignoring the packet " << interest->getName().toUri() );
		return;
	}

	//Client doesn't have to respond to heartbeat Interest
	if(interest->getName().toUri().find("heartbeat") != std::string::npos){

        NS_LOG_INFO("CLIENT node(" << GetNode()->GetId() << ") Client ignoring heartbeat packet " << interest->getName().toUri() );
        return;

	}
	App::OnInterest(interest); // tracing inside
	//NS_LOG_FUNCTION(this << interest);

	//NS_LOG_FUNCTION(this << interest);

	NS_LOG_DEBUG("CLIENT node(" << GetNode()->GetId() << ") Checking interest type " << interest->getName().toUri() << " against " << m_prefix_data.toUri());

	std::string prefix = interest->getName().toUri();
	std::size_t place	= prefix.find(m_prefix_data.toUri());
	if (place == 0) {

		// case1: /lacl/data/3
		// cnp ce qui il y a en dessous
		// case2: /lacl/data/stop/0/9
		std::string suffix = std::string("/stop/0/")+std::to_string(m_last_segment);
		if (prefix.find(m_prefix_data.toUri()+suffix) == 0) {
			NS_LOG_INFO("CLIENT node(" << GetNode()->GetId() << ") Interest is a stop command request " << interest->getName().toUri() );


			OnInterestResponse(interest);   //respond to the stop interest before the stop of the process

			FibHelper::RemoveRoute(GetNode(), m_prefix_data, m_face );
			m_active = false;
			NS_LOG_DEBUG("CLIENT node(" << GetNode()->GetId() << ") removed prefix " << m_prefix_data << " from the FIB and Client disabled" );
			return ;
		}else{
			NS_LOG_INFO("CLIENT node(" << GetNode()->GetId() << ") Interest is a data request " << interest->getName().toUri() );
		}
	} else {
		// case3: /autre/chose
		NS_LOG_INFO("CLIENT node(" << GetNode()->GetId() << ") Ignoring unrecognized interest " << interest->getName().toUri() );
		return ;
	}
	//verifier si entre 0 et lastSegment

	//si /stop/0/lastSegment remove advertise and return null
	OnInterestResponse(interest);


}

void Client::OnInterestResponse(shared_ptr<const Interest> interest) {


	Name dataName(interest->getName());
	// dataName.append(m_postfix);
	// dataName.appendVersion();

	auto data = make_shared<Data>();
	data->setName(dataName);
	data->setFreshnessPeriod(::ndn::time::milliseconds(m_freshness.GetMilliSeconds()));

	//set the freshnessPeriod to 1ms if the data is a storage, heartbeat or stop

	if((interest->getName().toUri().find("heartbeat") != std::string::npos)||(interest->getName().toUri().find("storage") != std::string::npos)||(interest->getName().toUri().find("stop") != std::string::npos)){

	data->setFreshnessPeriod(::ndn::time::milliseconds(1));

	}

	data->setContent(make_shared< ::ndn::Buffer>(m_virtualPayloadSize));
	NS_LOG_DEBUG("CLIENT node(" << GetNode()->GetId() << ") Preparing the data packet to serve "<< data->getName().toUri());

	Signature signature;
	SignatureInfo signatureInfo(static_cast< ::ndn::tlv::SignatureTypeValue>(255));

	if (m_keyLocator.size() > 0) {
		signatureInfo.setKeyLocator(m_keyLocator);
	}

	signature.setInfo(signatureInfo);
	signature.setValue(::ndn::nonNegativeIntegerBlock(::ndn::tlv::SignatureValue, m_signature));

	data->setSignature(signature);

	NS_LOG_DEBUG("CLIENT node(" << GetNode()->GetId() << ") responding with Data: " << data->getName());

	// to create real wire encoding
	data->wireEncode();

	setTransmittedDatas(data);
	//m_face->onReceiveData(*data);
	m_appLink->onReceiveData(*data);
	NS_LOG_DEBUG("CLIENT node(" << GetNode()->GetId() << ") Data packet transmitted to the NFD "<< data->getName().toUri());



}

} // namespace ndn
} // namespace ns3
