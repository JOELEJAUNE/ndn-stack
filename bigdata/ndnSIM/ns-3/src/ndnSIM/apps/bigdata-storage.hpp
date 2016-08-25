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

#ifndef NDN_BIGDATA_STORAGE_H
#define NDN_BIGDATA_STORAGE_H
namespace ns3 {
namespace ndn {
class Storage;
}
}
#include "ns3/ndnSIM/model/ndn-common.hpp"
#include "ndn-app.hpp"
#include "bigdata-dataconsumer.h"
#include "ns3/nstime.h"
#include "ns3/ptr.h"
#include "bigdata-storageinfo.hpp"
#include <list>

namespace ns3 {
namespace ndn {

/**
 * @ingroup ndn-apps
 * @brief A simple Interest-sink applia simple Interest-sink application
 *
 * A simple Interest-sink applia simple Interest-sink application,
 * which replying every incoming Interest with Data packet with a specified
 * size and name same as in Interest.cation, which replying every incoming Interest
 * with Data packet with a specified size and name same as in Interest.
 */
class Storage : public App {
public:
	static TypeId
	GetTypeId();

	/**
	 * \brief Default constructor
	 * Sets up randomizer function and packet sequence number
	 */
	Storage();
	virtual ~Storage();
	void SendInterest(std::string prefix) ;
	// (overridden from ndn::App) Callback that will be called when Interest arrives
	  virtual void
	  OnInterest(std::shared_ptr<const ndn::Interest> interest);
	  void OnInterestResponse(shared_ptr<const Interest> interest);

	  // (overridden from ndn::App) Callback that will be called when Data arrives
	  virtual void
	  OnData(std::shared_ptr<const ndn::Data> contentObject);
	virtual void OnDataRetrieved(DataConsumer* consumer);
	void setTransmittedInterests(shared_ptr<const Interest> interest) {
		m_transmittedInterests(interest,this,m_face);
	}
	TracedCallback<shared_ptr<const Interest>, Ptr<App>, shared_ptr<Face>> getTransmittedInterests() const {
		return m_transmittedInterests;
	}
	void setTransmittedDatas(shared_ptr<const Data> data) {
		m_transmittedDatas(data,this,m_face);
	}
	TracedCallback<shared_ptr<const Data>, Ptr<App>, shared_ptr<Face>> getTransmittedDatas() const {
		return m_transmittedDatas;
	}
	shared_ptr<AppFace> getFace() const {
		return m_face;
	}
	Ptr<Node> getNode() const;

	Name getPrefixCommand() const {
		return m_prefix_command;
	}
	void pushConsumer(DataConsumer* dc) {
			consumers.push_back(dc);
	}
protected:
	// inherited from Application base class.
	virtual void
	StartApplication(); // Called at time specified by Start

	virtual void
	StopApplication(); // Called at time specified by Stop

protected:

	Name m_prefix_command;
	Name m_prefix_data= Name("NO_DATA");

protected:


	uint32_t m_virtualPayloadSize = 1024;
	Time m_freshness;
	uint32_t m_signature = 100;
	Name m_keyLocator = Name("/unique/key/locator");
	//std::map<std::string, DataConsumer*> consumers;
	std::list<DataConsumer*> consumers;
};


} // namespace ndn
} // namespace ns3

#endif // NDN_Storage_H
