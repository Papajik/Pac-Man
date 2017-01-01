#pragma once
#include "Movable.h"
class Character : public Movable
{
private:
	int score;
public:
	Character(wchar_t rep);
	void increaseScore(int score);
	int getScore();
	
};


