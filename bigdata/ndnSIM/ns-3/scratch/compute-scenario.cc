/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */ /**
 * Copyright (c) 2011-2015 Regents of the University of California.
 *
 * This file is part of ndnSIM. See AUTHORS for complete list of ndnSIM authors and
 * contributors.
 *
 * ndnSIM is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * ndnSIM is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * ndnSIM, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 **/
#include "ns3/core-module.h" 
#include "ns3/network-module.h" 
#include "ns3/point-to-point-module.h" 
#include "ns3/point-to-point-layout-module.h" 
#include "ns3/ndnSIM-module.h" 
#include "ns3/node-container.h" 
#include "ns3/ndnSIM/apps/bigdata-strategy.hpp" 
#include "ns3/ndnSIM/apps/bigdata-default-strategy.hpp" 
#include "ns3/ndnSIM/helper/ndn-link-control-helper.hpp" 
#include <iostream> 
#include <random> 
#include <algorithm> 
#include <chrono>
namespace ns3 { 


 //implement function for node distribution(Admin, Storage, User)
 bool contains(std::vector<int>& vec, int value){
    bool res = true;
     if(std::find(vec.begin(), vec.end(), value) != vec.end()) {
        /* vec contains value */
            res = true;
        } else {
            res = false;
        }
    return res ;
}
int main(int argc, char* argv[]) { 

  uint32_t dimension = 10;
	uint32_t nbCompute = 8;
	uint32_t nbSegments = 2;
  uint32_t exec = 2;
	/* uint32_t replication = 2;*/
	uint32_t cs = 100;
	/* uint32_t nCapacity = 100;*/
	uint32_t mtbf = 100;
	uint32_t mfd = 100;
	 uint32_t nbClient = 1;
	/* uint32_t nbUser = 10;*/
	/* uint32_t nbFile = 1;*/
	uint32_t nbFailure = 10;
	uint32_t speed =10;
	uint32_t delay = 1;
	string policy="Fifo";
	/* string consumerRequests="Uniform";*/
	uint32_t runNumber = 1;

	// Read optional command-line parameters (e.g., enable visualizer with ./waf --run=<> --visualize
	CommandLine cmd;
	cmd.AddValue ("dimension", "Grid dimension", dimension);
	cmd.AddValue ("nbCompute", "Number of ComputeNode", nbCompute);
	cmd.AddValue ("segments", "Number of segments per data file", nbSegments);
	cmd.AddValue ("exec", "Code execution time", exec);
	cmd.AddValue ("cs", "Content Store size", cs);
	cmd.AddValue ("mtbf", "MeanTime BetweenFailure", mtbf);
	cmd.AddValue ("mfd", "MeanFailureDuration", mfd);
	cmd.AddValue ("nbClient", "Number of client nodes", nbClient);
	/*cmd.AddValue ("nbUser", "Number of user nodes", nbUser);*/
	/*cmd.AddValue ("nbFile", "Number of simultaneous files", nbFile);*/
	cmd.AddValue ("nbFailure", "Number of failed nodes", nbFailure);
	cmd.AddValue ("speed", "Speed of the links", speed);
	cmd.AddValue ("delay", "Delay over the links", delay);
  cmd.AddValue ("policy", "Cache replacement policy", policy);
  /*cmd.AddValue ("consumerRequests", "Consumer Requests Distribution", consumerRequests);*/
	cmd.AddValue ("runNumber", "Run number", runNumber);
	cmd.Parse(argc, argv);





//set the dumpfile location;
    //GlobalValue location("fileName","toto",replication);
      static GlobalValue g_myGlobal =
  GlobalValue ("myGlobal", "Value for the dump file",
               StringValue (std::string("../../bigdata/dump-trace-")
    +std::to_string(runNumber)+std::string(".txt")),
               MakeStringChecker ());
    //set header
    ns3::StringValue stringValue;
    ns3::GlobalValue::GetValueByName ("myGlobal", stringValue);

    string file = stringValue.Get ();
    std::ofstream outfile;
    outfile.open(file, std::ios_base::app);
    outfile << "Time;Node;Type;Name;Hop" << std::endl;
    outfile.close();
    

    //the execution time is constant for the code
    /* static GlobalValue g_myExec=
  GlobalValue ("myExec", "My global value for the code execution time",
               IntegerValue (12)); */

    static GlobalValue g_myExec =
  GlobalValue ("myGlobalExec", "Value for the code execution time",
               StringValue (std::to_string(exec)),
               MakeStringChecker ());
  ns3::StringValue stringVal;
    ns3::GlobalValue::GetValueByName ("myGlobalExec", stringVal);


    
	const int max = (const int) dimension;
  std::string speedValue = std::to_string(speed)+std::string("Mbps");
  std::string delayValue = std::to_string(delay)+std::string("ms");

     // Setting default parameters for PointToPoint links and channels
  Config::SetDefault("ns3::PointToPointNetDevice::DataRate", StringValue(speedValue));
  Config::SetDefault("ns3::PointToPointChannel::Delay", StringValue(delayValue));


	 // Setting default parameters for PointToPoint links and channels
 	// Creating 3x3 topology
	PointToPointHelper p2p;
	PointToPointGridHelper grid(max, max, p2p);
	grid.BoundingBox(100, 100, 200, 200);
	NodeContainer nodes;
	for (int i = 0; i < max; ++i) {
		for (int j = 0; j < max; ++j) {
			nodes.Add(grid.GetNode(i, j));
		}
	}


    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
      std::default_random_engine generator (seed);
     // std::default_random_engine generator;
      std::uniform_int_distribution<int> distribution(0,dimension*dimension-1);

  //node repartition
  std::vector<int> idCompute(nbCompute+2);
  std::vector<int> idClient(nbClient);

  //Storage nodes
       for (uint32_t j=0; j<nbCompute; ++j) {
        int number = distribution(generator);
         if(contains(idCompute,number)){
            idCompute.at(j) = 10000000;
            j--;
        }else{
            idCompute.at(j) = number;
        }
      }

//Client nodes
       for (uint32_t i=0; i<nbClient; ++i) {
        int number = distribution(generator);
         if(contains(idClient,number)||contains(idCompute,number)){
            idClient.at(i) = 10000000;
            i--;
        }else{
            idClient.at(i) = number;
        }
      }

	// Install NDN stack on all nodes
	ndn::StackHelper ndnHelper;
	
    ndnHelper.SetOldContentStore("ns3::ndn::cs::" + policy, "MaxSize",
      std::to_string(cs));
	ndnHelper.InstallAll();
	// Set BigData strategy
	ndn::GlobalRoutingHelper ndnGlobalRoutingHelper;
	ndnGlobalRoutingHelper.InstallAll();
 
std::vector<ApplicationContainer> container; //prepare for node failure simulation;

	//Install client application on ClientNode

  double stime = 0.0; //use to specify the start time for the admin
    ndn::AppHelper clientHelper("ns3::ndn::Client");
  for (std::vector<int>::iterator it=idClient.begin(); it != idClient.end(); ++it){
        std::string prefCom = std::string("/lacl")+std::to_string(*it)+std::string("/compute");
        std::string prefData = std::string("/lacl")+std::to_string(*it)+std::string("/data");
        std::string prefCode = std::string("/lacl")+std::to_string(*it)+std::string("/code");
        ndn::StrategyChoiceHelper::InstallAll(prefCom, "/localhost/nfd/strategy/bigdata"); //install bigdata Strategy for all the storage stuff
        ndn::StrategyChoiceHelper::InstallAll(prefData, "/localhost/nfd/strategy/bigdatadefault"); //use the customized default which is best route + dump stuff
        ndn::StrategyChoiceHelper::InstallAll(prefCode, "/localhost/nfd/strategy/bigdatadefault");

        clientHelper.SetAttribute("PrefixCommand",StringValue(prefCom));
        clientHelper.SetAttribute("PrefixData",StringValue(prefData));
        clientHelper.SetAttribute("PrefixCode",StringValue(prefCode));
        clientHelper.SetAttribute("LastSegment",StringValue(std::to_string(nbSegments)));
        ApplicationContainer app = clientHelper.Install(nodes.Get(*it));
  app.Start(Seconds(stime));
        container.push_back(app);
  stime = stime + 10.0;
    }

/*
        ndn::AppHelper clientHelper("ns3::ndn::Client");

        std::string prefCom = std::string("/lacl/compute");
        std::string prefData = std::string("/lacl/data");
        std::string prefCode = std::string("/lacl/code");
        ndn::StrategyChoiceHelper::InstallAll(prefCom, "/localhost/nfd/strategy/bigdata"); //install bigdata Strategy for all the storage stuff
        ndn::StrategyChoiceHelper::InstallAll(prefData, "/localhost/nfd/strategy/bigdatadefault"); //use the customized default which is best route + dump stuff
        clientHelper.SetAttribute("PrefixCommand",StringValue(prefCom));
        clientHelper.SetAttribute("PrefixData",StringValue(prefData));
        clientHelper.SetAttribute("PrefixCode",StringValue(prefCode));
        clientHelper.SetAttribute("LastSegment",StringValue(std::to_string(nbSegments)));
       
        clientHelper.Install(nodes.Get(0));

  
        ndn::StrategyChoiceHelper::InstallAll("/lacl/code", "/localhost/nfd/strategy/bigdatadefault");
*/
      //Install compute application on ComputeNode


        //ndn::AppHelper computeHelper("ns3::ndn::Compute");
/*
        for (std::vector<int>::iterator it=idCompute.begin(); it != idCompute.end(); ++it){
            std::string prefCom= std::string("/lacl/compute");
            computeHelper.SetAttribute("PrefixCommand", StringValue(prefCom));
            ApplicationContainer app = computeHelper.Install(nodes.Get(*it));
            container.push_back(app);
        }
 */   
        ndn::AppHelper computeHelper("ns3::ndn::Compute");
        for (std::vector<int>::iterator it=idCompute.begin(); it != idCompute.end(); ++it){
              for (std::vector<int>::iterator i=idClient.begin(); i != idClient.end(); ++i){
                  std::string prefCom= std::string("/lacl")+std::to_string(*i)+std::string("/compute");
                  computeHelper.SetAttribute("PrefixCommand", StringValue(prefCom));
                  ApplicationContainer app = computeHelper.Install(nodes.Get(*it));
                  container.push_back(app);
              }
          }


//code and data; 
    std::uniform_int_distribution<int> dist(0,idCompute.size()-1); 
    
int number = dist(generator);

        for (std::vector<int>::iterator it=idClient.begin(); it != idClient.end(); ++it){

            std::string prefCom= std::string("/lacl")+std::to_string(*it)+std::string("/code");
            computeHelper.SetAttribute("PrefixCommand", StringValue(prefCom));
            ApplicationContainer app = computeHelper.Install(nodes.Get(number));
            container.push_back(app);
        }

number = dist(generator);

        for (std::vector<int>::iterator it=idClient.begin(); it != idClient.end(); ++it){

            std::string prefCom= std::string("/lacl")+std::to_string(*it)+std::string("/data");
            computeHelper.SetAttribute("PrefixCommand", StringValue(prefCom));
            ApplicationContainer app = computeHelper.Install(nodes.Get(number));
            container.push_back(app);
        }



      /*
        //std::string prefCom = std::string("/lacl/compute");
        computeHelper.SetAttribute("PrefixCommand",StringValue(prefCom));
        computeHelper.Install(nodes.Get(5));

         computeHelper.Install(nodes.Get(10));
         computeHelper.Install(nodes.Get(15));
         computeHelper.SetAttribute("PrefixCommand",StringValue("/lacl/data"));
         computeHelper.Install(nodes.Get(3));
        //std::string prefCom = std::string("/lacl/compute");
      */

/*
        computeHelper.SetAttribute("PrefixCommand",StringValue("/lacl/data"));
         computeHelper.Install(nodes.Get(23));


        computeHelper.SetAttribute("PrefixCommand",StringValue("/lacl/code"));
        computeHelper.Install(nodes.Get(8));
*/
    
    //Simulate node failure
    std::uniform_int_distribution<int> distrib(0,container.size()-1);
    std::vector<int> failed(nbFailure); //Keep track of already failed ...
    std::poisson_distribution<> timeFailureDistribution(mtbf); //for the failure;
    std::poisson_distribution<> failureDistribution(mfd);
    for(uint32_t i=0; i<nbFailure; i++){
        int failureTime = timeFailureDistribution(generator);
        int failureDuration = failureDistribution(generator);
        int element = distrib(generator);
        container.at(element).Stop(Seconds(failureTime)); //failure
        container.at(element).Start(Seconds(failureTime+failureDuration)); //restore
        
    }



      ndn::GlobalRoutingHelper::CalculateAllPossibleRoutes();


  Simulator::Stop(Seconds(100.0));

  ndn::L3RateTracer::InstallAll(std::string("../../bigdata/rate-trace-")
    //+std::to_string(replication)+std::string("_")
    //+std::to_string(nbStorages)+std::string("_")
    //+std::to_string(dimension)+std::string("_")
    +std::to_string(runNumber)+std::string(".txt"), Seconds(0.5));
  
  ndn::CsTracer::InstallAll(std::string("../../bigdata/cs-trace-")
    //+std::to_string(replication)+std::string("_")
    //+std::to_string(nbStorages)+std::string("_")
    //+std::to_string(dimension)+std::string("_")
    +std::to_string(runNumber)+std::string(".txt"), Seconds(0.5)); // 
  //ndn::AppDelayTracer::InstallAll(std::string("/home/dpdk/data/app-delays-trace.txt") // +std::to_string(runNumber)+std::string(".txt"), Seconds(0.5)); //  
  //ndn::AppDelayTracer::InstallAll("app-delays-trace.txt");

	Simulator::Run();
	Simulator::Destroy();
	return 0;
}
} // namespace ns3
int main(int argc, char* argv[]) {
	return ns3::main(argc, argv);
}
