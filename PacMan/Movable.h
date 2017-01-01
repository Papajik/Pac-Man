#pragma once
#include "MapObject.h"
class Movable : public MapObject
{
private:
	int dirX;
	int dirY;
	bool step = false;
public:
	Movable(int type, wchar_t rep);
	~Movable();
	int getDirX();
	int getDirY();
	void setDirX(int x);
	void setDirY(int y);
	bool getStep();
	void switchStep();
};

