#include <klocale.h>
/****************************************************************************
** Form implementation generated from reading ui file '/home/ab/projecs/kerp/kerp/src/formcity.ui'
**
** Created: Tue Jun 3 16:42:18 2003
**      by: The User Interface Compiler ($Id: formcity.cpp,v 1.1 2003/06/07 12:21:03 arashb Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "formcity.h"

#include <qvariant.h>
#include <kpushbutton.h>
#include <qdatatable.h>
#include <qsplitter.h>
#include <qsqlcursor.h>
#include <qsqldatabase.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "/home/ab/projecs/kerp/kerp/src/formcity.ui.h"
/* 
 *  Constructs a FormCity as a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
FormCity::FormCity( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )

{
    if ( !name )
	setName( "FormCity" );
    setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 2, 3, sizePolicy().hasHeightForWidth() ) );
    setSizeGripEnabled( FALSE );
    FormCityLayout = new QVBoxLayout( this, 9, 6, "FormCityLayout"); 

    splitter3 = new QSplitter( this, "splitter3" );
    splitter3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, splitter3->sizePolicy().hasHeightForWidth() ) );
    splitter3->setOrientation( QSplitter::Vertical );

    dataTableProvince = new QDataTable( splitter3, "dataTableProvince" );
    dataTableProvince->addColumn( "name", tr2i18n( "Province" ) );
    dataTableProvince->setSorting( TRUE );
    dataTableProvince->setConfirmInsert( TRUE );
    dataTableProvince->setConfirmUpdate( TRUE );
    dataTableProvince->setConfirmDelete( TRUE );
    dataTableProvince->setConfirmCancels( TRUE );
    QStringList dataTableProvince_stringlist;
    dataTableProvince_stringlist << "name ASC";
    dataTableProvince->setSort( dataTableProvince_stringlist );
    QStringList dataTableProvince_stringlist_2;
    dataTableProvince_stringlist_2 << "(default)";
    dataTableProvince_stringlist_2 << "province";
    dataTableProvince->setProperty( "database", dataTableProvince_stringlist_2 );

    dataTableCity = new QDataTable( splitter3, "dataTableCity" );
    dataTableCity->addColumn( "name", tr2i18n( "City" ) );
    dataTableCity->setSorting( TRUE );
    dataTableCity->setConfirmInsert( TRUE );
    dataTableCity->setConfirmUpdate( TRUE );
    dataTableCity->setConfirmDelete( TRUE );
    dataTableCity->setConfirmCancels( TRUE );
    QStringList dataTableCity_stringlist;
    dataTableCity_stringlist << "name ASC";
    dataTableCity->setSort( dataTableCity_stringlist );
    QStringList dataTableCity_stringlist_2;
    dataTableCity_stringlist_2 << "(default)";
    dataTableCity_stringlist_2 << "city";
    dataTableCity->setProperty( "database", dataTableCity_stringlist_2 );
    FormCityLayout->addWidget( splitter3 );

    kPushButton1 = new KPushButton( this, "kPushButton1" );
    FormCityLayout->addWidget( kPushButton1 );

    // database support
    languageChange();
    resize( QSize(280, 244).expandedTo(minimumSizeHint()) );

    // signals and slots connections
    connect( dataTableProvince, SIGNAL( currentChanged(QSqlRecord*) ), this, SLOT( provinceChanged(QSqlRecord*) ) );
    connect( dataTableProvince, SIGNAL( primeInsert(QSqlRecord*) ), this, SLOT( primeInsertProvince(QSqlRecord*) ) );
    connect( dataTableCity, SIGNAL( primeInsert(QSqlRecord*) ), this, SLOT( primeInsertCity(QSqlRecord*) ) );
    connect( kPushButton1, SIGNAL( clicked() ), this, SLOT( close() ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
FormCity::~FormCity()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Widget polish.  Reimplemented to handle
 *  default data table initialization
 */
void FormCity::polish()
{
    if ( dataTableProvince ) {
        QSqlCursor* cursor = dataTableProvince->sqlCursor();
        if ( !cursor ) {
            cursor = new QSqlCursor( "province" );
            dataTableProvince->setSqlCursor( cursor, FALSE, TRUE );
        }
        if ( !cursor->isActive() )
            dataTableProvince->refresh( QDataTable::RefreshAll );
    }
    if ( dataTableCity ) {
        QSqlCursor* cursor = dataTableCity->sqlCursor();
        if ( !cursor ) {
            cursor = new QSqlCursor( "city" );
            dataTableCity->setSqlCursor( cursor, FALSE, TRUE );
        }
        if ( !cursor->isActive() )
            dataTableCity->refresh( QDataTable::RefreshAll );
    }
    QDialog::polish();
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void FormCity::languageChange()
{
    setCaption( tr2i18n( "City" ) );
    kPushButton1->setText( tr2i18n( "&Quit" ) );
}

#include "formcity.moc"
