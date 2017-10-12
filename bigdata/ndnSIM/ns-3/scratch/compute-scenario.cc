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
namespace ns3 { /**
 * To run scenario and see what is happening, use the following command:
 * ./waf --run="ndn-bigdata --replication=9 --nbStorages=9 --dimension=5 --segments=3 "
 *
 * NS_LOG=ndn.Admin:ndn.Storage:ndn.DataConsumer ./waf --run=ndn-bigdata --command-template="gdb --args %s ./build/scratch/ndn-bigdata"
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
int main(int argc, char* argv[]) { 

  uint32_t dimension = 10;
	uint32_t nbStorages = 8;
	uint32_t nbSegments = 2;
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
	uint32_t delay = 1;
	string policy;
	string consumerRequests="Uniform";
	uint32_t runNumber = 1;

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
  cmd.AddValue ("policy", "Cache replacement policy", policy);
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
    //set header
    ns3::StringValue stringValue;
    ns3::GlobalValue::GetValueByName ("myGlobal", stringValue);




    
	const int max = (const int) dimension;
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
	// Install NDN stack on all nodes
	ndn::StackHelper ndnHelper;
	
	//	ndnHelper.SetOldContentStore("ns3::ndn::cs::Nocache");
    //ndnHelper.SetDefaultRoutes(true);
	ndnHelper.InstallAll();
	// Set BigData strategy
	ndn::GlobalRoutingHelper ndnGlobalRoutingHelper;
	ndnGlobalRoutingHelper.InstallAll();
 

   
	//Install client application on ClientNode


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

  


      //Install compute application on ComputeNode


        ndn::AppHelper computeHelper("ns3::ndn::Compute");

        //std::string prefCom = std::string("/lacl/compute");
        computeHelper.SetAttribute("PrefixCommand",StringValue(prefCom));
         computeHelper.Install(nodes.Get(5));

         computeHelper.Install(nodes.Get(10));
         computeHelper.Install(nodes.Get(15));
        //std::string prefCom = std::string("/lacl/compute");
        computeHelper.SetAttribute("PrefixCommand",StringValue("/lacl/code"));
         computeHelper.Install(nodes.Get(8));

         computeHelper.SetAttribute("PrefixCommand",StringValue("/lacl/data"));
         computeHelper.Install(nodes.Get(3));

  Simulator::Stop(Seconds(50.0));

	Simulator::Run();
	Simulator::Destroy();
	return 0;
}
} // namespace ns3
int main(int argc, char* argv[]) {
	return ns3::main(argc, argv);
}
