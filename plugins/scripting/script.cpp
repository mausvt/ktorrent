/***************************************************************************
 *   Copyright (C) 2008 by Joris Guisson and Ivan Vasic                    *
 *   joris.guisson@gmail.com                                               *
 *   ivasic@gmail.com                                                      *
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
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
 ***************************************************************************/
#include <kmimetype.h>
#include <kross/core/manager.h>
#include <kross/core/actioncollection.h>
#include <util/fileops.h>
#include "script.h"

namespace kt
{

	Script::Script(const QString & file,QObject* parent) : QObject(parent),file(file),action(0),executing(false)
	{
	}


	Script::~Script()
	{
		stop();
	}

	bool Script::execute()
	{
		if (!bt::Exists(file) || action)
			return false;
		
		KMimeType::Ptr mt = KMimeType::findByPath(file);
		QString name = QFileInfo(file).fileName();
		action = new Kross::Action(this,name);
		action->setText(name);
		action->setDescription(name);
		action->setFile(file);
		action->setIconName(mt->iconName());
		QString interpreter = Kross::Manager::self().interpreternameForFile(file);
		if (interpreter.isNull())
		{
			delete action;
			action = 0;
			return false;
		}
		else
		{
			action->setInterpreter(interpreter);
			Kross::Manager::self().actionCollection()->addAction(file,action);
			action->trigger();
			executing = true;
			return true;
		}
	}
		
	void Script::stop()
	{
		if (!executing)
			return;
		
		Kross::ActionCollection* col = Kross::Manager::self().actionCollection();
		col->removeAction(action->file());
		action->deleteLater();
		action = 0;
		executing = false;
	}
	
	QString Script::name() const
	{
		if (action)
			return action->name();
		else
			return QFileInfo(file).fileName();
	}
		
	QString Script::iconName() const
	{
		if (action)
			return action->iconName();
		else
			return KMimeType::findByPath(file)->iconName();
	}
	
}