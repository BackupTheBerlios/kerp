/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you wish to add, delete or rename functions or slots use
** Qt Designer which will update this file, preserving your code. Create an
** init() function in place of a constructor, and a destroy() function in
** place of a destructor.
*****************************************************************************/
void InvoiceView::init()
{
    int width = table->width();
 table->setColumnWidth(0,width/4);
 table->setColumnWidth(1,width/2);
table->setColumnReadOnly(1,true);
}




void InvoiceView::PartnerIdChanged( const QString &string )
{
    QSqlQuery q;
    q.exec("select name,surename from partner where id="+string);
    if(q.next())
	textLabelPartner->setText(q.value(0).toString()+"-"+q.value(1).toString());


}




void InvoiceView::tableValueChanged( int row, int col )
{
    QSqlQuery tmpQ;
 
    kdDebug()<<"salam from table changed"<<endl;
    
    switch (col)
    {
	//product id changed
	case 0:
	    tmpQ.exec("select name, price from product where product_id= "+ table->text(row,col) + ";");
	    kdDebug()<<"salam"<<endl;
	    if (tmpQ.next())
	    {
		table->setText(row,1,tmpQ.value(0).toString());
		table->setText(row,2,tmpQ.value(1).toString());
	    }
	    break;
	default:
	    
	    break;
   }

}


void InvoiceView::invoiceChanged( Invoice * invoice )
{

}


void InvoiceView::setInvoice( Invoice *inv )
{
    invoice =  inv;   
    kLEPartnerId->setText(inv->getCustomer_id());
    kLEInvoiceId->setText(inv->getInvoice_id());
    
}
