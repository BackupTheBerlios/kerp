/*
 * Copyright (C) 2003 Arash Bijanzadeh <a.bijanzadeh@linuxiran.org>
 */

#ifndef _KERPPREF_H_
#define _KERPPREF_H_

#include <kdialogbase.h>
#include <qframe.h>

class kerpPrefPageOne;
class kerpPrefPageTwo;

class kerpPreferences : public KDialogBase
{
    Q_OBJECT
public:
    kerpPreferences();

private:
    kerpPrefPageOne *m_pageOne;
    kerpPrefPageTwo *m_pageTwo;
};

class kerpPrefPageOne : public QFrame
{
    Q_OBJECT
public:
    kerpPrefPageOne(QWidget *parent = 0);
};

class kerpPrefPageTwo : public QFrame
{
    Q_OBJECT
public:
    kerpPrefPageTwo(QWidget *parent = 0);
};

#endif // _KERPPREF_H_
