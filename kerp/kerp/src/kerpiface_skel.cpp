/****************************************************************************
**
** DCOP Skeleton created by dcopidl2cpp from kerpiface.kidl
**
** WARNING! All changes made in this file will be lost!
**
*****************************************************************************/

#include "/home/ab/kerp/src/kerpiface.h"

#include <kdatastream.h>


static const char* const kerpIface_ftable[1][3] = {
    { 0, 0, 0 }
};

bool kerpIface::process(const QCString &fun, const QByteArray &data, QCString& replyType, QByteArray &replyData)
{
	return DCOPObject::process( fun, data, replyType, replyData );
}

QCStringList kerpIface::interfaces()
{
    QCStringList ifaces = DCOPObject::interfaces();
    ifaces += "kerpIface";
    return ifaces;
}

QCStringList kerpIface::functions()
{
    QCStringList funcs = DCOPObject::functions();
    for ( int i = 0; kerpIface_ftable[i][2]; i++ ) {
	QCString func = kerpIface_ftable[i][0];
	func += ' ';
	func += kerpIface_ftable[i][2];
	funcs << func;
    }
    return funcs;
}


