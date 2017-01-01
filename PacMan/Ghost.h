#pragma once
#include "Movable.h"
class Ghost :public Movable
{
private:
	
public:
	Ghost(wchar_t rep);
	void changeDir(bool up, bool down, bool left, bool right);

};

