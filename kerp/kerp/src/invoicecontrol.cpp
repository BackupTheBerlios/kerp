/***************************************************************************
 *   Copyright (C) 2003 by Arash Bijanzadeh                                *
 *   a.bijanzadeh@linuxiran.org                                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/
 #include "invoicecontrol.h"
#include <qsqlquery.h>
//#include <kdebug.h>
//void InvoiceControl::test1(int * q){
//	*q = 8;
//	kdDebug()<<"qu is : "<<*q<<endl;
//	}

 InvoiceControl::InvoiceControl()
 {
 	int ids;

 	QSqlQuery q;
	//kdDebug()<<"instantiating invoicecontrol"<<endl;
//	int *v;
//	*v=7;
	//kdDebug()<<"going to call test1"<<endl;
//	test1(v);
	//kdDebug()<<"vi is  : "<<endl;
	q.exec("select id from invoice order by id");
//	kdDebug()<<"vi is  : "<<endl;
	int i=0;

	while (q.next())
	{
		ids=q.value(0).toInt();
		//kdDebug()<<"Invoice going to be added"<<endl;
		Invoice *invoice= new Invoice(ids);
		invoices[i++] = invoice;
		//kdDebug()<<"Invoice created"<<endl;
		//invoices[i++]= invoice;

		//kdDebug()<<"Invoice added invoice:"+invoice->getCustomer_id()<<endl;
	}


	iterator = invoices.begin();
//	kdDebug()<<"iterator created"<<endl;
	//iterator++;
	//kdDebug()<<"Iterattor's key is:"<<iterator.data()->getCustomer_id()<<endl;
}
InvoiceControl::~ InvoiceControl()
{}
Invoice * InvoiceControl::getCurrentInvoice(){
	return iterator.data();
}

void InvoiceControl::invoiceNext(Invoice * inv)
{
	iterator++;
//	kdDebug()<<"SLOT invoked!"<<endl;
	*inv = *iterator.data();
//	kdDebug()<<"inv is : "<<inv->getCustomer_id()<<endl;

}
void InvoiceControl::invoiceDelete(){}
void InvoiceControl::invoiceEdit(){}
void InvoiceControl::invoiceFirst(){}
void InvoiceControl::invoiceLast(){}
void InvoiceControl::invoiceNew(){}
void InvoiceControl::invoicePrev(){}

