/***************************************************************************
 *   Copyright (C) 2003 by Arash Bijanzadeh                                *
 *   a.bijanzadeh@linuxiran.org                                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef _INVOICELINE_H_
#define _INVOICELINE_H_

#include <qstring.h>
class InvoiceLine
{
	private :
	int id;
	int productId;
	int invoiceId;
	int price;
	int quantity;
	float discount;
	float tax;
	QString product;
	QString productName;

	public:
	InvoiceLine();
	InvoiceLine(int price, int quantity,float discount,float tax,  QString product="", int invoiceId=0, int productId=0);
	InvoiceLine(int id);
	~InvoiceLine();

	int getId() const { return id;};
	int getProductId() const {return productId;};
	int getInvoiceId() const {return invoiceId;};
	int getPrice() const {return price;};
	int getQuantity() const {return quantity;};
	float getDiscount() const {return discount;};
	float getTax() const {return tax;};
	QString getProduct() {return product;};
	QString getProductName() {return productName;};

	void setProductId(int);
	void setInvoiceId(int);
	void setPrice(int);
	void setQuantity(int);
	void setDiscount(float);
	void setTax(float);
	void setProduct(QString);
};

#endif //_INVOICELINE_H_
