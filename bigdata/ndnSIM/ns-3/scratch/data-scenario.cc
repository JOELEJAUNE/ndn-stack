/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2011-2015  Regents of the University of California.
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

/**
 * To run scenario and see what is happening, use the following command:
 * ./waf --run="ndn-bigdata --replication=9 --nbStorages=9 --dimension=5 --segments=3 "
 *
 *     NS_LOG=ndn.Admin:ndn.Storage:ndn.DataConsumer ./waf --run=ndn-bigdata --command-template="gdb --args %s ./build/scratch/ndn-bigdata"
 */

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


int
main(int argc, char* argv[])
{


/*

Network Size                                --> OK dimension
Number Of Storage Nodes                     --> OK nbStorage
Size Of File (Gb)                           --> OK segments
Number Of Replication                       --> OK replication
Content Store Size                          --> OK cs
Node Capacity (Tb)                          --> KO nCapacity
MeanTime Between Failure                    --> OK mtbf
MeanFailureDuration                         --> OK mfd
Number Of Producer (Admin)                  --> OK nbAdmin
Number Of Consumer Users                    --> OK nbUser
Number Of Simultaneous Input File           --> KO nbFile
Number Of Failure Node                      --> OK nbFailure
Links Speed                                 --> OK speed
Links Delay                                 --> OK delay
Node Distribution                           --> OK
Cache Policy
Consumer Requests Distribution               --> OK consumerRequests



*/


    uint32_t dimension = 10;
	uint32_t nbStorages = 80;
	uint32_t nbSegments = 200;
	uint32_t replication = 2;
	uint32_t cs = 100;
	uint32_t nCapacity = 100;
	uint32_t mtbf = 100;
	uint32_t mfd = 100;
	uint32_t nbAdmin = 1;
	uint32_t nbUser = 10;
	uint32_t nbFile = 1;
	uint32_t nbFailure = 10;
	uint32_t speed =10;
	uint32_t delay  = 1;
	string consumerRequests="Uniform";
	uint32_t runNumber  = 1;

	// Read optional command-line parameters (e.g., enable visualizer with ./waf --run=<> --visualize
	CommandLine cmd;
	cmd.AddValue ("dimension", "Grid dimension", dimension);
	cmd.AddValue ("nbStorages", "Number of Storages", nbStorages);
	cmd.AddValue ("segments", "Number of segments per data file", nbSegments);
	cmd.AddValue ("replication", "Replication factor", replication);
	cmd.AddValue ("cs", "Content Store size", cs);
	cmd.AddValue ("nCapacity", "Node Capacity", nCapacity);
	cmd.AddValue ("mtbf", "MeanTime BetweenFailure", mtbf);
	cmd.AddValue ("mfd", "MeanFailureDuration", mfd);
	cmd.AddValue ("nbAdmin", "Number of admin nodes", nbAdmin);
	cmd.AddValue ("nbUser", "Number of user nodes", nbUser);
	cmd.AddValue ("nbFile", "Number of simultaneous files", nbFile);
	cmd.AddValue ("nbFailure", "Number of failed nodes", nbFailure);
	cmd.AddValue ("speed", "Speed of the links", speed);
	cmd.AddValue ("delay", "Delay over the links", delay);
	cmd.AddValue ("consumerRequests", "Consumer Requests Distribution", consumerRequests);
	cmd.AddValue ("runNumber", "Run number", runNumber);

	cmd.Parse(argc, argv);

   //set the dumpfile location;
    //GlobalValue location("fileName","toto",replication);
    	static GlobalValue g_myGlobal =
  GlobalValue ("myGlobal", "Value for the dump file",
               StringValue (std::string("../../bigdata/dump-trace-")
		//+std::to_string(replication)+std::string("_")
		//+std::to_string(nbStorages)+std::string("_")
		//+std::to_string(dimension)+std::string("_")
		+std::to_string(runNumber)+std::string(".txt")),
               MakeStringChecker ());


   std::string speedValue = std::to_string(speed)+std::string("Mbps");
   std::string delayValue = std::to_string(delay)+std::string("ms");


	const int max = (const int) dimension * dimension;


	 // Setting default parameters for PointToPoint links and channels
  Config::SetDefault("ns3::PointToPointNetDevice::DataRate", StringValue(speedValue));
  Config::SetDefault("ns3::PointToPointChannel::Delay", StringValue(delayValue));
  //Config::SetDefault("ns3::DropTailQueue::MaxPackets", StringValue("10"));



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



	// Install NDN stack on all nodes
	ndn::StackHelper ndnHelper;
	ndnHelper.SetOldContentStore("ns3::ndn::cs::Lru", "MaxSize",
			std::to_string(cs)); // ContentStore parameters
	//	ndnHelper.SetOldContentStore("ns3::ndn::cs::Nocache");
    //ndnHelper.SetDefaultRoutes(true);
	ndnHelper.InstallAll();

	// Set BigData strategy

	ndn::GlobalRoutingHelper ndnGlobalRoutingHelper;
	ndnGlobalRoutingHelper.InstallAll();

    //ndn::StrategyChoiceHelper::InstallAll("/lacl/storage", "/localhost/nfd/strategy/bigdata");
	//ndn::StrategyChoiceHelper::InstallAll("/lacl/storage", "/localhost/nfd/strategy/multicast");
	//ndn::StrategyChoiceHelper::InstallAll("/lacl/data", "/localhost/nfd/strategy/bigdata");
	//ndn::StrategyChoiceHelper::InstallAll("/lacl/data/heartbeat", "/localhost/nfd/strategy/multicast");
    //ndn::StrategyChoiceHelper::InstallAll("/lacl/data", "/localhost/nfd/strategy/bigdatadefault");
    //ndn::StrategyChoiceHelper::InstallAll("/lacl/data", "/localhost/nfd/strategy/multicast");


    //generate arrays for nodes id
    /* Start random node distribution */
        //const int dimension = 10; // number of nodes


      unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
      std::default_random_engine generator (seed);
     // std::default_random_engine generator;
      std::uniform_int_distribution<int> distribution(0,dimension*dimension);
      //std::binomial_distribution<int> distribution(dimension*dimension, 0.3);
      //std::negative_binomial_distribution<int> distribution(dimension*dimension,0.7);


      //int nbAdmin = 5;
      //int nbStorages = 10;
      //int nbUser = 25;
     std::vector<int> idAdmin(nbAdmin);
     std::vector<int> idStorage(nbStorages);
     std::vector<int> idUser(nbUser);

    // admin nodes
      for (uint32_t i=0; i<nbAdmin; ++i) {
        int number = distribution(generator);
        if(contains(idAdmin,number)){
            idAdmin.at(i) = 1000000000;
            i--;
        }else{
            idAdmin.at(i) = number;
        }

      }

    //Storage nodes

       for (uint32_t j=0; j<nbStorages; ++j) {
        int number = distribution(generator);
         if(contains(idAdmin,number)||contains(idStorage,number)){
            idStorage.at(j) = 10000000;
            j--;

        }else{
            idStorage.at(j) = number;

        }

      }

      //User nodes

      for (uint32_t j=0; j<nbUser; ++j) {
        int number = distribution(generator);
         if(contains(idAdmin,number)||contains(idStorage,number)||contains(idUser,number)){
            idUser.at(j) = 100000000;
            j--;

        }else{
            idUser.at(j) = number;

        }

      }

    /* End random node distribution */

    std::vector<ApplicationContainer> container; //prepare for node failure simulation;

	//Install admin application on AdminNodes
    ndn::AppHelper adminHelper("ns3::ndn::Admin");
	for (std::vector<int>::iterator it=idAdmin.begin(); it != idAdmin.end(); ++it){

        std::string prefCom = std::string("/lacl")+std::to_string(*it)+std::string("/storage");
        std::string prefData = std::string("/lacl")+std::to_string(*it)+std::string("/data");

        ndn::StrategyChoiceHelper::InstallAll(prefCom, "/localhost/nfd/strategy/bigdata"); //install bigdata Strategy for all the storage stuff
        ndn::StrategyChoiceHelper::InstallAll(prefData, "/localhost/nfd/strategy/bigdatadefault"); //use the customized default which is best route + dump stuff
        adminHelper.SetAttribute("PrefixCommand",StringValue(prefCom));
        adminHelper.SetAttribute("PrefixData",StringValue(prefData));
        adminHelper.SetAttribute("ReplicationFactor",StringValue(std::to_string(replication)));
        adminHelper.SetAttribute("LastSegment",StringValue(std::to_string(nbSegments)));
        ApplicationContainer app = adminHelper.Install(nodes.Get(*it));
        container.push_back(app);


    }

	//install Storage application on Nodes
    ndn::AppHelper storageHelperA("ns3::ndn::Storage");
	for (std::vector<int>::iterator it=idStorage.begin(); it != idStorage.end(); ++it){

        for (std::vector<int>::iterator i=idAdmin.begin(); i != idAdmin.end(); ++i){
            std::string prefCom= std::string("/lacl")+std::to_string(*i)+std::string("/storage");
            storageHelperA.SetAttribute("PrefixCommand", StringValue(prefCom));
            ApplicationContainer app = storageHelperA.Install(nodes.Get(*it));
            container.push_back(app);
        }

    }



    //install User application on Nodes
    std::uniform_int_distribution<int> dist(0,idAdmin.size()-1); //randomly select the prefix to request data

    ndn::AppHelper userHelperA("ns3::ndn::User");
    for (std::vector<int>::iterator it=idUser.begin(); it != idUser.end(); ++it){


        int number = dist(generator);
        std::string pref = std::string("/lacl")+std::to_string(idAdmin.at(number))+std::string("/data");
		userHelperA.SetAttribute("Randomize", StringValue(consumerRequests));
		userHelperA.SetPrefix(pref);
        ApplicationContainer app = userHelperA.Install(nodes.Get(*it));
        container.push_back(app);
    }


    //Simulate node failure
    std::uniform_int_distribution<int> distrib(0,container.size()-1);
    std::vector<int> failed(nbFailure); //Keep track of already failed ...
    std::poisson_distribution<> timeFailureDistribution(mtbf); //for the failure;
    std::poisson_distribution<> failureDistribution(mfd);

    for(uint32_t i=0; i<nbFailure; i++){


        int failureTime = timeFailureDistribution(generator);
        int failureDuration = failureDistribution(generator);
        int element = distrib(generator);
      //  if(contains(failed,element)){
        //    failed.at(i) = 10000;
          //  i--;
        //}else{
          //  failed.at(i) = element;
            container.at(element).Stop(Seconds(failureTime)); //failure
            container.at(element).Start(Seconds(failureTime+failureDuration)); //restore
        //}



    }

    ndn::GlobalRoutingHelper::CalculateAllPossibleRoutes();


	Simulator::Stop(Seconds(30.0));


	ndn::L3RateTracer::InstallAll(std::string("../../bigdata/rate-trace-")
		+std::to_string(replication)+std::string("_")
		+std::to_string(nbStorages)+std::string("_")
		+std::to_string(dimension)+std::string("_")
		+std::to_string(nbSegments)+std::string(".txt"), Seconds(0.5));
	ndn::CsTracer::InstallAll(std::string("../../bigdata/cs-trace-")
		+std::to_string(replication)+std::string("_")
		+std::to_string(nbStorages)+std::string("_")
		+std::to_string(dimension)+std::string("_")
		+std::to_string(nbSegments)+std::string(".txt"), Seconds(0.5));


	Simulator::Run();
	Simulator::Destroy();

	return 0;
}


} // namespace ns3

int
main(int argc, char* argv[])
{
	return ns3::main(argc, argv);
}

