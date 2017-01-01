#include "Character.h"



Character::Character(wchar_t rep=L'O') :Movable(2, rep)
{
	this->score = 0;
}

void Character::increaseScore(int score)
{
	this->score += score;
}

int Character::getScore()
{
	return this->score;
}