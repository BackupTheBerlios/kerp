
#ifndef _MTABLE_H
#define _MTABLE_H
#include <qtable.h>
#include <qwidget.h>
#include <qevent.h>

class  MTable : public QTable
{
	Q_OBJECT
	public :
	 	MTable(QWidget * parent=0 , const char *name=0);
		~MTable(){};
	signals :
		void keyClicked();

	 protected:
		void keyPressEvent(QKeyEvent * e);

};
#endif
