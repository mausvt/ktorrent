/***************************************************************************
 *   Copyright (C) 2005 by Joris Guisson                                   *
 *   joris.guisson@gmail.com                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Steet, Fifth Floor, Boston, MA 02110-1301, USA.             *
 ***************************************************************************/
#ifndef BTUDPTRACKER_H
#define BTUDPTRACKER_H

#include <kurl.h>
#include <qhostaddress.h>
#include <qtimer.h>
#include "tracker.h"
#include "globals.h"

class QSocketDevice;
class QSocketNotifier;

namespace bt
{

	/**
	 * @author Joris Guisson
	 * @brief Communicates with an UDP tracker
	 *
	 * This class is able to communicate with an UDP tracker.
	 * This is an implementation of the protocol described in
	 * http://xbtt.sourceforge.net/udp_tracker_protocol.html
	 */
	class UDPTracker : public Tracker
	{
		Q_OBJECT
	public:
		UDPTracker();
		virtual ~UDPTracker();

		virtual void doRequest(const KURL & url);
		virtual void updateData(TorrentControl* tc,PeerManager* pman);

		static void setPort(Uint16 p);

	private slots:
		void dataRecieved(int s);
		void onConnTimeout();

	private:
		void sendConnect();
		void sendAnnounce();
		void announceRecieved();
		void connectRecieved();

	private:
		QHostAddress addr;
		Uint16 udp_port;
		QSocketDevice* sock;
		Int32 transaction_id;
		Int64 connection_id;
		QSocketNotifier* sn;
		KURL old_url;

		Uint32 leechers,seeders,interval,data_read;
		Uint8* peer_buf;
		int n;
		QTimer conn_timer;

		static Uint16 port;
	};

}

#endif
