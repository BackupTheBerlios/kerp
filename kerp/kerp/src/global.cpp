#include "global.h"
#include <stdio.h>
QString Global::toString(int i)
{
	char *id=new char;
	sprintf(id,"%d",i);
	return QString::fromLatin1(id);
}
QString Global::toString(float f)
{
	char *id=new char;
	sprintf(id,"%f",f);
	return QString::fromLatin1(id);
}
