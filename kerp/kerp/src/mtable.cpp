#include "mtable.h"
#include <kdebug.h>
MTable::MTable(QWidget * parent, const char * name) : QTable(parent, name){
kdDebug()<<"salam"<<endl;

}
void MTable::keyPressEvent(QKeyEvent * keyEvent)
{
	kdDebug()<<"key pressed"<<endl;
	keyEvent->accept();
}
