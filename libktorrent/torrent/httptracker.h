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
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.             *
 ***************************************************************************/
#ifndef BTHTTPTRACKER_H
#define BTHTTPTRACKER_H

#include <qtimer.h>
#include "tracker.h"

namespace KIO
{
	class Job;
}

namespace bt
{
	

	/**
	 * @author Joris Guisson
	 * @brief Communicates with the tracker
	 *
	 * This class uses the HTTP protocol to communicate with the tracker.
	 */
	class HTTPTracker : public Tracker
	{
		Q_OBJECT
	public:
		HTTPTracker(const KURL & url,kt::TorrentInterface* tor,const PeerID & id,int tier);
		virtual ~HTTPTracker();
		
		virtual void start();
		virtual void stop();
		virtual void completed();
		virtual void manualUpdate();
		virtual Uint32 failureCount() const {return failures;}
		virtual void scrape();
		
	private slots:
		void onAnnounceResult(KIO::Job* j);
		void onScrapeResult(KIO::Job* j);
		void onTimeout();

	private:
		void doRequest();
		bool updateData(const QByteArray & data);
		
	private:
		QTimer timer;
		KIO::Job* active_job;
		KIO::Job* active_scrape_job;
		QString event;
		Uint32 failures;
	};

}

#endif
