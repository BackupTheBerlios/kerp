/*
 * Copyright (C) 2003 Arash Bijanzadeh <a.bijanzadeh@linuxiran.org>
 */

#ifndef _KERPVIEW_H_
#define _KERPVIEW_H_

#include <qwidget.h>
#include <kparts/part.h>
#include <kerpiface.h>

class QPainter;
class KURL;

/**
 * This is the main view class for kerp.  Most of the non-menu,
 * non-toolbar, and non-statusbar (e.g., non frame) GUI code should go
 * here.
 *
 * This kerp uses an HTML component as an example.
 *
 * @short Main view
 * @author Arash Bijanzadeh <a.bijanzadeh@linuxiran.org>
 * @version 0.1
 */
class kerpView : public QWidget, public kerpIface
{
    Q_OBJECT
public:
	/**
	 * Default constructor
	 */
    kerpView(QWidget *parent);

	/**
	 * Destructor
	 */
    virtual ~kerpView();

    /**
     * Random 'get' function
     */
   // QString currentURL();

    /**
     * Random 'set' function accessed by DCOP
     */
  //  virtual void openURL(QString url);

    /**
     * Random 'set' function
     */
    //virtual void openURL(const KURL& url);

    /**
     * Print this view to any medium -- paper or not
     */
    void print(QPainter *, int height, int width);

signals:
    /**
     * Use this signal to change the content of the statusbar
     */
    void signalChangeStatusbar(const QString& text);

    /**
     * Use this signal to change the content of the caption
     */
    void signalChangeCaption(const QString& text);

private slots:
    //void slotOnURL(const QString& url);
    void slotSetTitle(const QString& title);

private:
    KParts::ReadOnlyPart *m_html;
};

#endif // _KERPVIEW_H_
