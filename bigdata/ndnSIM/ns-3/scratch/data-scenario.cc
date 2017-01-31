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



namespace ns3 {

/**
 * To run scenario and see what is happening, use the following command:
 * ./waf --run="ndn-bigdata --replication=9 --nbStorages=9 --dimension=5 --segments=3 "
 *
 *     NS_LOG=ndn.Admin:ndn.Storage:ndn.DataConsumer ./waf --run=ndn-bigdata --command-template="gdb --args %s ./build/scratch/ndn-bigdata"
 */

 //implement function for node distribution(Admin, Storage, User)

int nextPrime(int a)
{
	int i, j, count;
	for (i = a + 1; 1; i++)
	{
		count = 0;
		for (j = 2;j < i; j++)
		{
			if (i%j == 0) // found a divisor
			{
				count++;
				break;  // break for (j = 2,j < i; j++) loop
				// this will speed up a bit
			}
		}
		if (count == 0)
		{
			return i;
			//break; // break for (i = a + 1; 1; i++) loop
			// break is not needed because return will stop execution of this function
		}
	}
}


int
main(int argc, char* argv[])
{



/*

Network Size                                --> OK dimension
Number Of Storage Nodes                     --> OK nbStorage
Size Of File (Gb)                           --> OK segments
Number Of Replication                       --> OK replication
Content Store Size                          --> KO cs
Node Capacity (Tb)                          --> KO
Probability Of Node Failure                 --> KO
Probability Of Node Component Failure       --> KO
Number Of Producer (Admin)                  --> KO nbAdmin
Number Of Consumer Users                    --> KO nbUser
Number Of Simultaneous Input File           --> KO nbFile
Number Of Failure Node                      --> KO nbFailure
Links Speed                                 --> KO speed
Links Delay                                 --> KO delay
Node Distribution                           --> KO
Cache Policy
Consumer Request Distribution



*/



	uint32_t replication = 2;
	uint32_t nbStorages = 80;
	uint32_t dimension = 10;
	uint32_t nbSegments = 200;

	uint32_t cs = 100;
	uint32_t nbAdmin = 1;
	uint32_t nbUser = 10;
	uint32_t nbFile = 1;
	uint32_t nbFailure = 10;
	uint32_t speed =10;
	uint32_t delay  = 1;

	// Read optional command-line parameters (e.g., enable visualizer with ./waf --run=<> --visualize
	CommandLine cmd;
	cmd.AddValue ("replication", "Replication factor", replication);
	cmd.AddValue ("nbStorages", "Number of Storages", nbStorages);
	cmd.AddValue ("dimension", "Grid dimension", dimension);
	cmd.AddValue ("segments", "Number of segments per data file", nbSegments);

	cmd.AddValue ("cs", "Content Store size", cs);
	cmd.AddValue ("nbAdmin", "Number of admin nodes", nbAdmin);
	cmd.AddValue ("nbUser", "Number of user nodes", nbUser);
	cmd.AddValue ("nbFile", "Number of simultaneous files", nbFile);
	cmd.AddValue ("nbFailure", "Number of failed nodes", nbFailure);
	cmd.AddValue ("speed", "Speed of the links", speed);
	cmd.AddValue ("delay", "Delay over the links", delay);

	cmd.Parse(argc, argv);

   //set the dumpfile location;
    //GlobalValue location("fileName","toto",replication);
    	static GlobalValue g_myGlobal =
  GlobalValue ("myGlobal", "Value for the dump file",
               StringValue (std::string("../../bigdata/dump-trace-")
		+std::to_string(replication)+std::string("_")
		+std::to_string(nbStorages)+std::string("_")
		+std::to_string(dimension)+std::string("_")
		+std::to_string(nbSegments)+std::string(".txt")),
               MakeStringChecker ());


   std::string speedValue = std::to_string(speed)+std::string("Mbps");
   std::string delayValue = std::to_string(delay)+std::string("ms");


	const int max = (const int) dimension;


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
			std::to_string(cs)); // default ContentStore parameters
	//	ndnHelper.SetOldContentStore("ns3::ndn::cs::Nocache");
    //ndnHelper.SetDefaultRoutes(true);
	ndnHelper.InstallAll();

	// Set BestRoute strategy

	//topologyReader.ApplyOspfMetric();

	ndn::GlobalRoutingHelper ndnGlobalRoutingHelper;
	ndnGlobalRoutingHelper.InstallAll();

	//ndn::StrategyChoiceHelper::InstallAll("/lacl/storage", "/localhost/nfd/strategy/bigdata");
	ndn::StrategyChoiceHelper::InstallAll("/lacl/storage", "/localhost/nfd/strategy/multicast");
	//ndn::StrategyChoiceHelper::InstallAll("/lacl/data", "/localhost/nfd/strategy/bigdata");
	//ndn::StrategyChoiceHelper::InstallAll("/lacl/data/heartbeat", "/localhost/nfd/strategy/multicast");
//    ndn::StrategyChoiceHelper::InstallAll("/lacl/data", "/localhost/nfd/strategy/bigdatadefault");
//ndn::StrategyChoiceHelper::InstallAll("/lacl/data", "/localhost/nfd/strategy/multicast");

	// Getting containers for the consumer/producer
	//Ptr<Node> producer = Names::Find<Node>("Node8");
	//NodeContainer nodes;
	//consumerNodes.Add(Names::Find<Node>("Node0"));

	ndn::AppHelper adminHelper("ns3::ndn::Admin");
	// Consumer will request /prefix/0, /prefix/1, ...
	adminHelper.SetAttribute("PrefixCommand",StringValue("/lacl/storage"));// /3/lacl/data/0/9
	adminHelper.SetAttribute("PrefixData",StringValue("/lacl/data"));
	adminHelper.SetAttribute("ReplicationFactor",StringValue(std::to_string(replication)));
	adminHelper.SetAttribute("LastSegment",StringValue(std::to_string(nbSegments)));
	adminHelper.Install(grid.GetNode(0, 0));//Names::Find<Node>("Node8"));                        // first node


	int lastPrime = 2;
	uint32_t countStorage = 0; //get the number of storage initialized
	// Storage A
	for (int i = 1; i < (int)dimension * (int)dimension; ++i) {
		if(i == lastPrime){
			lastPrime = nextPrime(lastPrime);
			continue;
		}
		ndn::AppHelper storageHelperA("ns3::ndn::Storage");
		storageHelperA.SetAttribute("PrefixCommand", StringValue("/lacl/storage"));
		storageHelperA.Install(nodes.Get(i));

        countStorage++;

		if(countStorage == nbStorages){
            break;      //break when we have the exact number of needed storages
		}

	}


        ndn::AppHelper userHelperA("ns3::ndn::User");
		//userHelperA.SetAttribute("Frequency", StringValue("10"));
		userHelperA.SetAttribute("Randomize", StringValue("exponential"));
		//userHelperA.SetAttribute("Randomize", StringValue("uniform"));
		userHelperA.SetPrefix("/lacl/data");
        userHelperA.Install(nodes.Get(5));
                userHelperA.Install(nodes.Get(8));
                userHelperA.Install(nodes.Get(2));

Simulator::Schedule(Seconds(1), ndn::LinkControlHelper::FailLink, nodes.Get(0), nodes.Get(1));


//ndn::GlobalRoutingHelper::CalculateRoutes();
ndn::GlobalRoutingHelper::CalculateAllPossibleRoutes();

//Simulator::Schedule(Seconds(9), ndn::LinkControlHelper::UpLink, nodes.Get(0), nodes.Get(1));
 /*  Simulator::Schedule (Seconds (15), ndn::LinkControlHelper::FailLink, nodes.Get (6), nodes.Get (1));
    Simulator::Schedule (Seconds (15), ndn::LinkControlHelper::FailLink, nodes.Get (6), nodes.Get (5));
    Simulator::Schedule (Seconds (15), ndn::LinkControlHelper::FailLink, nodes.Get (6), nodes.Get (7));
    Simulator::Schedule (Seconds (15), ndn::LinkControlHelper::FailLink, nodes.Get (6), nodes.Get (11));
*/
	Simulator::Stop(Seconds(1000.0));
	//ns3::Config::SetGlobal 	("toto", "../../bigdata/rate-trace-");



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

		ndn::AppDelayTracer::InstallAll(std::string("../../bigdata/delay-trace-")
		+std::to_string(replication)+std::string("_")
		+std::to_string(nbStorages)+std::string("_")
		+std::to_string(dimension)+std::string("_")
		+std::to_string(nbSegments)+std::string(".txt"));
	//  L2RateTracer::InstallAll("drop-trace.txt", Seconds(0.5));


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

