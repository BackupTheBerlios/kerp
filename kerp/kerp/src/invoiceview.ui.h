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
    kLEInvoiceId->setEnabled(false);
    kLEPartnerId->setEnabled(false);
 //  table->setEnabled(false);
    invoice = new Invoice();
    TableKeys *keyFilter= new TableKeys();
    table->installEventFilter(keyFilter);

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
		table->editCell(row,3);
	    }
	    break;
	default:
	    
	    break;
   }

}


void InvoiceView::invoiceChanged( Invoice * invoice )
{

}


void InvoiceView::setInvoice( Invoice inv )
{
    *invoice =  inv;   
    setInvoice();
}


void InvoiceView::nextClicked()
{
 
 //   kdDebug()<<"going to emit"<<endl;
   //Invoice * inv=new Invoice();
    emit NextRequested(invoice);
   //  kdDebug()<<"signal emited ! "<<endl;     
    //kdDebug()<<"signal emited the invoice is "<<inv->getCustomer_id()<<endl;
    setInvoice ();

	
}



void InvoiceView::prevClicked()
{
    kdDebug()<<"emiting prevClicked"<<endl;
    emit PrevRequested(invoice);
    kdDebug()<<"invoice returned is :"<<invoice->getCustomer_id()<<endl;
    setInvoice();
}


void InvoiceView::firstClicked()
{
    emit FirstRequested(invoice);
    setInvoice();
}


void InvoiceView::lastClicked()
{
    emit LastRequested(invoice);
    setInvoice();
}


void InvoiceView::setInvoice()
{
    kLEPartnerId->setText(invoice->getCustomer_id());
    kLEInvoiceId->setText(invoice->getInvoice_id());  
    table->setNumRows(0);
    //populate table
    lines = invoice->getLines();
    kdDebug()<<"get lines done"<<endl;
    iterator=lines.begin();
    int i = 0;
    InvoiceLine il;
    while (iterator != lines.end())
    {
	il = iterator.data();
	kdDebug()<<il.getProduct()<<endl;
	table->setNumRows(table->numRows()+1);
	table->setText(i,0,il.getProduct());
	table->setText(i,1,il.getProductName());
	table->setText(i,2,Global::toString(il.getPrice()));
	table->setText(i,3,Global::toString(il.getQuantity()));
	table->setText(i,4,Global::toString(table->text(i,3).toInt() *  table->text(i,2).toInt()));
		       
	iterator++;
	i++;
    }
    
}

void InvoiceView::enableEditing( bool b )
{
kLEPartnerId->setEnabled(b);
table->setEnabled(b);
kPBGoFirst->setEnabled(!b);
kPBGoLast->setEnabled(!b);
kPBGoNext->setEnabled(!b);
kPBGoPrev->setEnabled(!b);
kPBDelete->setEnabled(!b);
kPBSave->setEnabled(b);
}
void InvoiceView::newClicked()
{
    enableEditing(true);
    invoice=new Invoice();
    setInvoice();
}


void InvoiceView::saveClicked()
{
    kdDebug()<<"save action"<<endl;
    invoice->setCustomer_id(kLEPartnerId->text());
    invoice->setInvoice_id(Global::toString(0));
    invoice->setDate(kRLEDate->text());
    for (int i =0; i< table->numRows();i++)
    {

	InvoiceLine * il = new InvoiceLine (table->text(i,2).toInt() , table->text(i,3).toInt(), table->text(i,5).toFloat(), table->text(i,6).toFloat(), table->text(i,0) );
	kdDebug()<<"line added"<<endl;

	invoice->addInvoiceLine(il);
    }
    invoice->save();
}
