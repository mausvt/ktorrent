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
#ifndef BTPEERMANAGER_H
#define BTPEERMANAGER_H

#include <qsocket.h> 
#include <qvaluelist.h>
#include <qptrlist.h>
#include "globals.h"
#include "peerid.h"

namespace bt
{
	class Peer;
	class ChunkManager;
	class Torrent;
	class Authenticate;

	struct PotentialPeer
	{
		PeerID id;
		QString ip;
		Uint16 port;
	};

	/**
	 * @author Joris Guisson
	 * @brief Manages all the Peers
	 * 
	 * This class manages all Peer objects.
	 * It can also open connections to other peers.
	 */
	class PeerManager : public QObject
	{
		Q_OBJECT
	public:
		/**
		 * Constructor.
		 * @param tor The Torrent
		 */
		PeerManager(Torrent & tor);
		virtual ~PeerManager();
		

		/**
		 * Check for new connections, update down and upload speed of each Peer.
		 * Initiate new connections. 
		 */
		void update();
		
		/**
		 * Remove dead peers.
		 */
		void clearDeadPeers();

		Peer* getPeer(Uint32 index) {return peers.at(index);}
		
		/**
		 * Try to connect to some peers
		 */
		void connectToPeers();
		
		/**
		 * Close all Peer connections.
		 */
		void closeAllConnections();
		
		/**
		 * Start listening to incoming requests.
		 */
		void start();
		
		/**
		 * Stop listening to incoming requests.
		 */
		void stop();

		/**
		 * Kill all peers who have been choked longer then @a older_then time.
		 * @param older_then Time in milliseconds
		 */
		void killChokedPeers(Uint32 older_then);
		
		Uint32 getNumConnectedPeers() const {return peers.count();}
		Uint32 getNumPending() const {return num_pending;}
		
		static void setMaxConnections(Uint32 max);
		static Uint32 getMaxConnections() {return max_connections;}

		/// Get the Torrent
		Torrent & getTorrent() {return tor;}

		/**
		 * A new connection is ready for this PeerManager.
		 * @param sock The socket
		 * @param peer_id The Peer's ID
		 */
		void newConnection(QSocket* sock,const PeerID & peer_id);

		/**
		 * Add a potential peer
		 * @param pp The PotentialPeer
		 */
		void addPotentialPeer(const PotentialPeer & pp);
	private:
		bool connectedTo(const PeerID & peer_id);	
		void peerAuthenticated(Authenticate* auth,bool ok);
		
	signals:
		void newPeer(Peer* p);
		void peerKilled(Peer* p);
		
	private:
		QPtrList<Peer> peers,killed;
		QPtrList<Authenticate> pending;
		Uint32 num_seeders,num_leechers,num_pending;
		QValueList<PotentialPeer> potential_peers;
		Torrent & tor;
		bool started;
		
		static Uint32 max_connections;
	};

}

#endif
