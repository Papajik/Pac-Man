#pragma once
#include "MapObject.h"
class Food: public MapObject
{
private:
	int points;
public:
	Food(int point, wchar_t rep);
	~Food();
	int getPoints();
};
