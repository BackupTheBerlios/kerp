/***************************************************************************
 *   Copyright (C) 2003 by Arash Bijanzadeh                                *
 *   a.bijanzadeh@linuxiran.org                                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/
#include "tablekeyfilter.h"

#include <qtable.h>
#include <qevent.h>
#include <qmetaobject.h>

#include <kdebug.h>
bool TableKeys::eventFilter(QObject * object, QEvent * event)
{

	if (event->type()== QEvent::KeyPress)
	{

		if (object->isA("QTable"))
		{
			//QMetaObject *table = object->metaObject();
			QKeyEvent * key =(QKeyEvent *) event;
			QTable * table = (QTable*)object;
			kdDebug()<<"event filtered : "<<key->key()<<endl;
			kdDebug()<<table->currentRow() <<":"<<table->numRows()<<endl;
			switch (key->key()){
				case Key_Down:
					if ((table->currentRow()+1) == table->numRows() )
					{
						kdDebug()<<"going to set num rows"<<endl;
						table->setNumRows(table->numRows()+1);
						table->editCell(table->numRows()-1,0);
					} else{
						table->setCurrentCell(table->currentRow()+1, table->currentColumn());
					}
				break;
				case Key_Up:
						table->setCurrentCell(table->currentRow()-1, table->currentColumn());
				break;
				case Key_Delete:
				//if ( !table->isEditing())
					table->removeRow(table->currentRow());
				break;
			}

			key->ignore();
		}
		return TRUE;
	}else {
		return FALSE;


	}
}
