/***************************************************************************
 *   Copyright (C) 2003 by Arash Bijanzadeh                                *
 *   a.bijanzadeh@linuxiran.org                                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

 #include "Invoice.h"
#include "global.h"
 #include <stdio.h>
#include <kdebug.h>
 #include <qsqlquery.h>
 Invoice::Invoice(int id)
 {
 	QSqlQuery q;
	char * idstr=new char ;

	Invoice();

	sprintf(idstr,"%d",id);
	q.exec("select id,invoice_id,  customer_id from invoice where id = "+ QString::fromLatin1(idstr));
	if(q.next())
	{
		setId(id);
		setCustomer_id(q.value(2).toString());
		setInvoice_id(q.value(1).toString());
	}
	q.exec("select id from invoice_line where invoice_id= " +QString::fromLatin1(idstr) + " order by id;");	int i=0;
	while (q.next())
	{
		lines[i++]= *(new InvoiceLine(q.value(0).toInt()));
	}
}
Invoice::Invoice()
 {
 customer_id =QString::QString();
 invoice_id =QString::QString();
 lines[0]= *(new InvoiceLine());
 }

//Invoice::~Invoice()
//{}
void Invoice::setCustomer_id(QString aCustomer_id)
{
	customer_id=aCustomer_id;
}
void Invoice::setInvoice_id(QString anInvoice_id)
{
	invoice_id=anInvoice_id;
}
int Invoice::getId() const
{
	return id;
}
QString Invoice::getInvoice_id() const
{
	return invoice_id;
}
QString Invoice::getCustomer_id() const
{
	return customer_id;
}
void Invoice::setId(int anId)
{
	id=anId;
}
QMap< int,InvoiceLine > Invoice::getLines()
{
	return lines;
}

void Invoice::addInvoiceLine(InvoiceLine *il)
{
	lines[lines.count()+1]=*il;
}
void Invoice::save()
{
	kdDebug()<<" in the save"<<endl;
	QSqlQuery q;
	if (invoice_id.toInt()==0) //This is a new invoice
	{
		int realid, id ;
		q.exec("select nextval('invoice_id_seq');");
		if (q.next())
			realid = q.value(0).toInt();

		q.exec("select seq from manualids where tablename='invoice';");
		if (q.next())
			id=q.value(0).toInt();
		q.exec("BEGIN;");
		kdDebug()<<" in transaction begin :"+realid<<endl;
		 if( !q.exec("insert into invoice (id,invoice_id,customer_id,invoice_date) values ("+Global::toString(realid)+","+Global::toString(id)+",'"+customer_id+"','"+invoice_date+"');"))
			kdDebug()<<"insert into invoice (id,invoice_id,customer_id,invoice_date) values ("+Global::toString(realid)+","+Global::toString(id)+",'"+customer_id+"','"+invoice_date+"');"<<endl;
		InvoiceLineMap::Iterator iterator;
		iterator=lines.begin();
		iterator++;
		for(iterator;iterator!=lines.end(); iterator++)	{
			kdDebug()<<"iterator is:" << iterator.data().getProduct()<<endl;
			kdDebug()<<"insert into invoice_line (invoice_id,product_id, price, quantity, discount,tax) values ("+ Global::toString(realid) + "," + 		Global::toString(iterator.data().getProductId()) +","+ Global::toString(iterator.data().getPrice())+","+ 				Global::toString(iterator.data().getQuantity())+","+ Global::toString(iterator.data().getDiscount())+","+ Global::toString(iterator.data().getTax())+");"<<endl;
			q.exec("insert into invoice_line (invoice_id,product_id, price, quantity, discount,tax) values ("+ Global::toString(realid) + "," + 		Global::toString(iterator.data().getProductId()) +","+ Global::toString(iterator.data().getPrice())+","+ 				Global::toString(iterator.data().getQuantity())+","+ Global::toString(iterator.data().getDiscount())+","+ Global::toString(iterator.data().getTax())+");");
			q.exec("update manualids set seq="+Global::toString(id+1)+"  where tablename='invoice';");
		}
		kdDebug()<<"goin to commit"<<endl;
		q.exec("commit;");
		kdDebug()<<"comitted"<<endl;
	}
}
void Invoice::setDate(QString date)
{
	invoice_date= date;
}

QString Invoice::getDate()
{
	return invoice_date;
}
