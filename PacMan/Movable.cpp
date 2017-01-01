#include "Movable.h"



Movable::Movable(int type, wchar_t rep) :MapObject(type, rep)
{ 
	this->dirX = 0;
	this->dirY = 0;
}


Movable::~Movable()
{
}

int Movable::getDirX()
{
	return this->dirX;
}
int Movable::getDirY()
{
	return this->dirY;
}

void Movable::setDirX(int x)
{
	this->dirY = 0;
	this->dirX = x;
}

void Movable::setDirY(int y)
{
	this->dirX = 0;
	this->dirY = y;
}

bool Movable::getStep()
{
	return this->step;
}

void Movable::switchStep()
{
	this->step = !this->step;
}