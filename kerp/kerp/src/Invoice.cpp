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

 #include <stdio.h>

 #include <qsqlquery.h>
 Invoice::Invoice()
 {
 }
 Invoice::Invoice(int id)
 {
 	QSqlQuery q;
	char * idstr ;
	sprintf(idstr,"%d",id);
	q.exec("select id,invoice_id,  customer_id from invoice where id = "+ QString::fromLatin1(idstr));;
	if(q.next())
	{
		setId(id);
		setCustomer_id(q.value(2).toString());
		setInvoice_id(q.value(1).toString());
	}
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
