/****************************************************************************
** Form interface generated from reading ui file '/home/ab/projecs/kerp/kerp/src/formcity.ui'
**
** Created: Tue Jun 3 16:41:52 2003
**      by: The User Interface Compiler ($Id: formcity.h,v 1.1 2003/06/07 12:21:03 arashb Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FORMCITY_H
#define FORMCITY_H

#include <qvariant.h>
#include <qdialog.h>
#include <qsqlrecord.h>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class KPushButton;
class QDataTable;
class QSplitter;
class QSqlCursor;
class QSqlDatabase;
class QSqlRecord;

class FormCity : public QDialog
{
    Q_OBJECT

public:
    FormCity( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~FormCity();

    QSplitter* splitter3;
    QDataTable* dataTableProvince;
    QDataTable* dataTableCity;
    KPushButton* kPushButton1;

public slots:
    virtual void polish();

    virtual void provinceChanged( QSqlRecord * buffer );
    virtual void primeInsertProvince( QSqlRecord * buffer );
    virtual void primeInsertCity( QSqlRecord * buffer );

protected:
    QVBoxLayout* FormCityLayout;

protected slots:
    virtual void languageChange();
private:
    QVariant province_id;

};

#endif // FORMCITY_H
