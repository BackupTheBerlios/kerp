/***************************************************************************
 *   Copyright (C) 2003 by Arash Bijanzadeh                                *
 *   a.bijanzadeh@linuxiran.org                                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

 #include <qstring.h>
#include   <qobject.h>

 class Invoice :public QObject
 {
 	Q_OBJECT
	public :
		Invoice(int);
		virtual ~Invoice();

		QString getCustomer_id() const;
		void setCustomer_id(QString);
		void setId(int);
		QString getInvoice_id() const;
		void setInvoice_id(QString);

		int getId() const;
private:
	QString customer_id;
	QString invoice_id;
	int id;

};
