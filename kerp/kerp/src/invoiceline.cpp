
#include <qsqlquery.h>
#include <kdebug.h>
#include <strings.h>
#include "invoiceline.h"
#include "global.h"

InvoiceLine::InvoiceLine()
{
	id=0;
	productId=0;
	invoiceId=0;
	quantity=0;
	price=0;
	discount = 0;
	tax = 0 ;
	product=QString::QString();//tobefixed
	productName=QString::QString();
}
InvoiceLine::InvoiceLine(int id)
{
	QSqlQuery q;
	InvoiceLine();
	q.exec("select invoice_line.id,invoice_line.invoice_id,invoice_line.product_id,invoice_line.price,invoice_line.quantity,invoice_line.discount,invoice_line.tax,product.product_id,product.name from invoice_line,product where product.id=invoice_line.product_id and invoice_line.id= "+Global::toString(id)+";");
	if (q.next())
	{
		kdDebug()<<"in the if "<<endl;
		id=q.value(0).toInt();
		invoiceId=q.value(1).toInt();
		productId=q.value(2).toInt();
		price =q.value(3).toInt();
		quantity=q.value(4).toInt();
		kdDebug()<<"in the if 2"<<endl;
		discount = q.value(5).toInt();

		tax = q.value(6).toInt();
		product=q.value(7).toString();
		productName = q.value(8).toString();
  	}
}
InvoiceLine::InvoiceLine(int aPrice, int aQuantity,float aDiscount,float aTax,  QString aProduct="", int aInvoiceId=0, int aProductId=0)
{
	QSqlQuery q;
	InvoiceLine();
	price = aPrice;
	quantity=aQuantity;
	discount= aDiscount;
	product = aProduct;
	q.exec("select id from product where product_id = '"+aProduct+"';");
	if (q.next())
		productId=q.value(0).toInt();
}

InvoiceLine::~InvoiceLine() {}


void InvoiceLine::setProductId(int i)
{
	productId=i;
}

void InvoiceLine::setInvoiceId(int i)
{
	invoiceId=i;
}

void InvoiceLine::setPrice(int i)
{
	price=i;
}

void InvoiceLine::setQuantity(int i)
{
	quantity = i;
}

void InvoiceLine::setDiscount(float f)
{
	discount = f ;
}

void InvoiceLine::setTax(float f)
{
	tax = f;
}
void InvoiceLine::setProduct(QString c)
{
	product = c;
}
