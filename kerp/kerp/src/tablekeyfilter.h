/***************************************************************************
 *   Copyright (C) 2003 by Arash Bijanzadeh                                *
 *   a.bijanzadeh@linuxiran.org                                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef _TABLEKEYFILTER_H_
 #include <qobject.h>

 class TableKeys : public QObject
 {
 	Q_OBJECT
	public :
		TableKeys() {};
		~TableKeys() {};
	protected :
		bool eventFilter(QObject *,QEvent * e);
};

#endif

