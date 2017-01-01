#include "Food.h"



Food::Food(int point, wchar_t rep):MapObject(4, rep)
{
	this->points = point;
}


Food::~Food()
{
}

int Food::getPoints()
{
	return this->points;
}
