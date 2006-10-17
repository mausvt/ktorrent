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
#ifndef BTCONSTANTS_H
#define BTCONSTANTS_H

namespace bt
{
	typedef unsigned long long Uint64;
	typedef unsigned int Uint32;
	typedef unsigned short Uint16;
	typedef unsigned char Uint8;

	typedef long long Int64;
	typedef int Int32;
	typedef short Int16;
	typedef char Int8;
	
	typedef enum 
	{
		/* These are the old values, for compatability reasons with old chunk_info files we leave them here :
		PREVIEW_PRIORITY = 4,
		FIRST_PRIORITY = 3,
		NORMAL_PRIORITY = 2,
		LAST_PRIORITY = 1,
		EXCLUDED = 0,
		ONLY_SEED_PRIORITY = -1
		*/
		// make sure new values are different from old values
		// also leave some room if we want to add new priorities in the future
		PREVIEW_PRIORITY = 60,
		FIRST_PRIORITY = 50,
		NORMAL_PRIORITY = 40,
		LAST_PRIORITY = 30,
		ONLY_SEED_PRIORITY = 20,
		EXCLUDED = 10,
	}Priority;
	
	enum ConfirmationResult
	{
		KEEP_DATA,
		THROW_AWAY_DATA,
		CANCELED
	};
	
	const Uint32 MAX_MSGLEN = 9 + 131072;
	const Uint16 MIN_PORT = 6881;
	const Uint16 MAX_PORT = 6889;
	const Uint32 MAX_PIECE_LEN = 16384;
	
	const Uint8 CHOKE = 0;
	const Uint8 UNCHOKE = 1;
	const Uint8 INTERESTED = 2;
	const Uint8 NOT_INTERESTED = 3;
	const Uint8 HAVE = 4;
	const Uint8 BITFIELD = 5;
	const Uint8 REQUEST = 6;
	const Uint8 PIECE = 7;
	const Uint8 CANCEL = 8;
	const Uint8 PORT = 9;
	const Uint8 SUGGEST_PIECE = 13;
	const Uint8 HAVE_ALL = 14;
	const Uint8 HAVE_NONE = 15;
	const Uint8 REJECT_REQUEST = 16;
	const Uint8 ALLOWED_FAST = 17;
	
	
	// flags for things which a peer supports
	const Uint32 DHT_SUPPORT = 0x01;
	const Uint32 FAST_EXT_SUPPORT = 0x04;
}


#endif
