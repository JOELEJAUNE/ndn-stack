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

#ifndef NDN_BIGDATA_ADMIN_H
#define NDN_BIGDATA_ADMIN_H
namespace ns3 {
namespace ndn {
class Admin;
}
}
#include "ndn-app.hpp"
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/tag.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>
#include "bigdata-dataconsumer.h"
#include "ns3/ndnSIM/model/ndn-common.hpp"
#include "ns3/nstime.h"
#include "ns3/ptr.h"
#include <list>

namespace ns3 {
namespace ndn {

/**
 * @ingroup ndn-apps
 * @brief Ndn application for sending out Interest packets at a "constant" rate (Poisson process)
 */
class Admin: public App {
public:
	static TypeId
	GetTypeId();

	/**
	 * \brief Default constructor
	 * Sets up randomizer function and packet sequence number
	 */
	Admin();
	virtual ~Admin();
	// inherited from NdnApp
	virtual void
	OnInterest(shared_ptr<const Interest> interest);
	// From App
	virtual void
	OnData(shared_ptr<const Data> contentObject);
	virtual void OnDataRetrieved(DataConsumer* consumer);
	int getLastSegment() const {
		return m_last_segment;
	}

	int getRepFactor() const {
		return m_rep_factor;
	}
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
	void setFace(shared_ptr<AppFace> face) {
		m_face = face;
	}
	shared_ptr<AppFace> getFace() const {
		return m_face;
	}
	void SendInterest(std::string prefix) ;
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
	uint32_t m_rep_factor;
	uint32_t m_last_segment;
	Name m_prefix_command;
	Name m_prefix_data;
protected:
	uint32_t m_virtualPayloadSize = 1024;
	Time m_freshness;
	uint32_t m_signature = 100;
	Name m_keyLocator= Name("/unique/key/locator");
	std::list<DataConsumer*> consumers;

};

} // namespace ndn
} // namespace ns3

#endif
