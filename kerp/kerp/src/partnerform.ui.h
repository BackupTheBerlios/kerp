
void PartnerForm::init()
{
    /*
    QSqlQuery query("SELECT name, id FROM province ORDER BY name;");    
    while ( query.next() ) {
	kComboBoxProvince->insertItem( query.value( 0 ).toString()); 
	int id = query.value( 1 ).toInt();
	mapProvince( query.value( 0 ).toString(), id, TRUE );
	
    
    }
    */
    dataBrowser4->last();
}

void PartnerForm::mapProvince( const QString & name, int & id, bool populate )
{
    if ( populate ) 
	provinceMap[ name ] = id;
    else
	id = provinceMap[ name ];
}

void PartnerForm::mapCity( const QString & name, int & id, bool populate )
{
    if ( populate ) 
	cityMap[ name ] = id;
    else
	id = cityMap[ name ];
}

void PartnerForm::insertPrimePartner( QSqlRecord * buffer)
{
    kdDebug()<<(*buffer).toString()<<endl;
    kdDebug()<<"going to insert"<<endl;

        QSqlQuery query;
        query.exec( "select nextval('partner_id_seq');" );
        if ( query.next() ) {          
	 buffer->setValue( "id", query.value( 0 ) );
        }
	int city;
	mapCity(kComboBoxCity->currentText(),city,false);
	buffer->setValue("city",city);
	kdDebug()<<(*buffer).toString()<<endl;
	enableEditing(false);
}

void PartnerForm::primeUpdate( QSqlRecord * buffer )
{
    QSqlQuery q;
    kComboBoxProvince->removeItem (0);
    kComboBoxCity->removeItem(0);
    q.exec("select name from city where id = "+buffer->value("city").toString()+";");
    if ( q.next() )
    {
	    kdDebug()<<q.value(0).toString()<<endl;
	kComboBoxCity->insertItem(q.value(0).toString());
	kComboBoxCity->setCurrentItem(0);
    }
    
    q.exec("select name from province where id =(select province_id from city where id="+buffer->value("city").toString()+");");
    if ( q.next() )
    {
	kComboBoxProvince->insertItem(q.value(0).toString());
	kComboBoxProvince->setCurrentItem(0);
    }
    
    kdDebug()<<"province is "+q.value(0).toString()<<endl;

    
    }
    


void PartnerForm::newRequested()
{
    kdDebug()<<"New requested"<<endl;
    kComboBoxProvince->removeItem(0);
    kComboBoxCity->removeItem(0);
 QSqlQuery query("SELECT name, id FROM province ORDER BY name;");    
    while ( query.next() ) {
	kComboBoxProvince->insertItem( query.value( 0 ).toString()); 
	int id = query.value( 1 ).toInt();
	mapProvince( query.value( 0 ).toString(), id, TRUE );
    }   
    kComboBoxProvince->setCurrentItem(0);
    populateComboCity();
    enableEditing(true);
}


void PartnerForm::populateComboCity( )
{
    kdDebug()<<"City Combo Populating"<<endl;
    
 while(kComboBoxCity->count()!=0)
	kComboBoxCity->removeItem(0);
    QSqlQuery query("select name, id from city where province_id=(select id from province where name='"+kComboBoxProvince->currentText()+"');");
    while ( query.next() ) {
	kComboBoxCity->insertItem( query.value( 0 ).toString()); 
	int id = query.value( 1 ).toInt();
	mapCity( query.value( 0 ).toString(), id, TRUE );
    }   
}


void PartnerForm::enableEditing( bool flag )
{
QLineEditName->setEnabled(flag);
QLineEditSurename->setEnabled(flag);
QLineEditAccountno->setEnabled(flag);
QSpinBoxCredit->setEnabled(flag);
kComboBoxProvince->setEnabled(flag);
kComboBoxCity->setEnabled(flag);
PushButtonUpdate->setEnabled(flag);
PushButtonInsert->setEnabled(!flag);
PushButtonFirst->setEnabled(!flag);
PushButtonPrev->setEnabled(!flag);
PushButtonNext->setEnabled(!flag);
PushButtonLast->setEnabled(!flag);
PushButtonDelete->setEnabled(!flag);
PushButtonEdit->setEnabled(!flag);

}


void PartnerForm::editRequested()
{
    enableEditing(true);
}
