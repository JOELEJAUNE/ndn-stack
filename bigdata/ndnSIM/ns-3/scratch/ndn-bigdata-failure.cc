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

// ndn-simple.cpp

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/ndnSIM-module.h"

#include "ns3/ndnSIM/helper/ndn-link-control-helper.hpp"
//#include "ns3/ndnSIM/apps/bigdata-consumer.hpp"
//#include "ns3/ndnSIM/apps/bigdata-dataconsumer.h"
//#include "ns3/ndnSIM/examples/random-load-balancer-strategy.hpp"

//#include "ns3/ndnSIM/examples/ndn-load-balancer/random-load-balancer-strategy.hpp"
//#include <ns3/src/ndnSIM/example/ndn-load-balancer/random-load-balancer-strategy.hpp>


namespace ns3 {

/**
 * This scenario simulates a very simple network topology:
 *
 *
 *      +----------+     1Mbps      +--------+     1Mbps      +----------+
 *      | consumer | <------------> | router | <------------> | producer |
 *      +----------+         10ms   +--------+          10ms  +----------+
 *
 *
 * Consumer requests data from producer with frequency 10 interests per second
 * (interests contain constantly increasing sequence number).
 *
 * For every received interest, producer replies with a data packet, containing
 * 1024 bytes of virtual payload.
 *
 * To run scenario and see what is happening, use the following command:
 *
 *     NS_LOG=ndn.Consumer:ndn.Producer ./waf --run=ndn-simple
 */

int
main(int argc, char* argv[])
{
    uint32_t replication = 2;
	uint32_t nbStorages = 2;
	uint32_t dimension = 3;
	uint32_t nbSegments = 1;



	// Read optional command-line parameters (e.g., enable visualizer with ./waf --run=<> --visualize
	CommandLine cmd;
	cmd.AddValue ("replication", "Replication factor", replication);
	cmd.AddValue ("nbStorages", "Number of Storages", nbStorages);
	cmd.AddValue ("dimension", "Grid dimension", dimension);
	cmd.AddValue ("segments", "Number of segments per data file", nbSegments);
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


  // setting default parameters for PointToPoint links and channels
  Config::SetDefault("ns3::PointToPointNetDevice::DataRate", StringValue("1Mbps"));
  Config::SetDefault("ns3::PointToPointChannel::Delay", StringValue("10ms"));
  Config::SetDefault("ns3::DropTailQueue::MaxPackets", StringValue("20"));



  // Creating nodes
  NodeContainer nodes;
  nodes.Create(9);

  // Connecting nodes using two links
  PointToPointHelper p2p;
  p2p.Install(nodes.Get(0), nodes.Get(1));
  p2p.Install(nodes.Get(0), nodes.Get(3));
  p2p.Install(nodes.Get(1), nodes.Get(2));
  p2p.Install(nodes.Get(1), nodes.Get(4));
  p2p.Install(nodes.Get(2), nodes.Get(5));
  p2p.Install(nodes.Get(3), nodes.Get(4));
   p2p.Install(nodes.Get(3), nodes.Get(6));
    p2p.Install(nodes.Get(4), nodes.Get(5));
     p2p.Install(nodes.Get(4), nodes.Get(7));
      p2p.Install(nodes.Get(5), nodes.Get(8));
  p2p.Install(nodes.Get(6), nodes.Get(7));
  p2p.Install(nodes.Get(7), nodes.Get(8));

  // Install NDN stack on all nodes
  ndn::StackHelper ndnHelper;
  ndnHelper.SetDefaultRoutes(true);
  ndnHelper.InstallAll();

  // Choosing forwarding strategy
  //ndn::StrategyChoiceHelper::InstallAll("/prefix", "/localhost/nfd/strategy/multicast");
	//ndn::StrategyChoiceHelper::InstallAll("/lacl/storage", "/localhost/nfd/strategy/random-load-balancer");
    ndn::StrategyChoiceHelper::InstallAll("/lacl/storage", "/localhost/nfd/strategy/bigdata");
//std::string prefix = "/lacl/storage";
//	ndn::StrategyChoiceHelper::Install<nfd::fw::RandomLoadBalancerStrategy>(nodes,
  //                                                                   prefix);


  ndn::GlobalRoutingHelper ndnGlobalRoutingHelper;
	ndnGlobalRoutingHelper.InstallAll();


	//for a node - the router (node 1)
 //    Ptr<ns3::ndn::L3Protocol> l3 =
 //                       ns3::ndn::L3Protocol::getL3Protocol(nodes.Get(0));

     //get the content store for the node
  //   nfd::Cs& myContentStore = l3->getForwarder()->getCs();

  // Installing applications


  ndn::AppHelper adminHelper("ns3::ndn::Admin");
	// Consumer will request /prefix/0, /prefix/1, ...
	adminHelper.SetAttribute("PrefixCommand",StringValue("/lacl/storage"));// /3/lacl/data/0/9
	adminHelper.SetAttribute("PrefixData",StringValue("/lacl/data"));
	adminHelper.SetAttribute("ReplicationFactor",StringValue(std::to_string(replication)));
	adminHelper.SetAttribute("LastSegment",StringValue(std::to_string(nbSegments)));
	adminHelper.Install(nodes.Get(0));//Names::Find<Node>("Node8"));                      // first node


        ndn::AppHelper storageHelperA("ns3::ndn::Storage");
		storageHelperA.SetAttribute("PrefixCommand", StringValue("/lacl/storage"));


		ndn::AppHelper userHelperA("ns3::ndn::User");
		//userHelperA.SetAttribute("Frequency", StringValue("10"));
		userHelperA.SetAttribute("Randomize", StringValue("exponential"));
		//userHelperA.SetAttribute("Randomize", StringValue("uniform"));
		userHelperA.SetPrefix("/lacl/data");
       userHelperA.Install(nodes.Get(2));
        //userHelperA.Install(nodes.Get(8));

	ApplicationContainer app =  storageHelperA.Install(nodes.Get(1));

	std::vector<ApplicationContainer> cont;
		storageHelperA.Install(nodes.Get(4));
		storageHelperA.Install(nodes.Get(6));
		//storageHelperA.Install(nodes.Get(8));


//Simulator::Schedule(Seconds(1), ndn::LinkControlHelper::FailLink, nodes.Get(0), nodes.Get(1));

//Simulator::Schedule(Seconds(3),ns3::ndn::App::StopApplication,nodes.Get(2));
app.Start(Seconds(0));
app.Stop(Seconds(1));


//Simulator::Schedule(Seconds(1), ndn::LinkControlHelper::UpLink, nodes.Get(0), nodes.Get(1));
//Simulator::Schedule(Seconds(1), ndn::LinkControlHelper::FailLink, nodes.Get(0), nodes.Get(1));

 ndn::GlobalRoutingHelper::CalculateRoutes();
ndn::GlobalRoutingHelper::CalculateAllPossibleRoutes();

//Simulator::Schedule(Seconds(12.0315), ndn::LinkControlHelper::FailLink, nodes.Get(0), nodes.Get(4));
//Simulator::Schedule(Seconds(18), ndn::LinkControlHelper::FailLink, nodes.Get(1), nodes.Get(2));


  Simulator::Stop(Seconds(30.0));

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
