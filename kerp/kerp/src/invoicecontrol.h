/***************************************************************************
 *   Copyright (C) 2003 by Arash Bijanzadeh                                *
 *   a.bijanzadeh@linuxiran.org                                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

 #ifndef _INVOICECONTROL_H_
 #define _INVOICECONTROL_H_

 #include <qobject.h>
 #include <qmap.h>

#include "Invoice.h"

 class InvoiceControl: public QObject
 {
 	Q_OBJECT
typedef  QMap<int ,Invoice *>  InvoiceMap;

public:
	InvoiceControl();
	virtual ~InvoiceControl();
	Invoice getCurrentInvoice();
public slots:
	void invoiceNext(Invoice*);
	void invoicePrev(Invoice*);
	void invoiceFirst(Invoice*);
	void invoiceLast(Invoice*);
	void invoiceNew();
	void invoiceDelete();
	void invoiceEdit();
private :
	InvoiceMap invoices;
	InvoiceMap::Iterator iterator;
	void test1(int*);
};
#endif
