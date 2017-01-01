#include "MapObject.h"



MapObject::MapObject(int type, wchar_t rep) {
this->type = type;
this->rep = rep;
}


MapObject::~MapObject()
{
}



int MapObject::getType()
{
	return this->type;
}



wchar_t MapObject::getRep()
{
	return this->rep;
}

void MapObject::setRep(wchar_t rep)
{
	this->rep = rep;
}
