#include "Ghost.h"
#include <stdlib.h> 
#include <time.h>


Ghost::Ghost(wchar_t rep) :Movable(3, rep)
{
}

void Ghost::changeDir(bool up, bool down, bool left, bool right)
{

	int changed = 0;

	while (changed < 3) {
		changed++;
		srand(time(NULL));
		int dir = rand() % 4;
		switch (dir)
		{
		case 0:
		{
			if (left)
			{
				changed = 10;
				this->setDirX(-1);
				this->setRep(L'←');
				break;
			}
		}

		case 1:
		{
			if (right)
			{
				changed = 10;
				this->setDirX(1);
				this->setRep(L'→');
				break;
			}
		}

		case 2:
		{
			if (up)
			{
				changed = 10;
				this->setDirY(-1);
				this->setRep(L'↑');
				break;
			}
		}
		case 3:
		{
			if (down)
			{
				changed = 10;
				this->setDirY(1);
				this->setRep(L'↓');
				break;
			}
		}
		}
	}
	if (changed != 10)
	{
		if (up)
		{
			this->setDirY(-1);
			this->setRep(L'↑');
		}
		else if (left)
		{
			this->setDirX(-1);
			this->setRep(L'←');
		}
		else if (right)
		{
			this->setDirX(1);
			this->setRep(L'→');
		}
		else if (down)
		{
			this->setDirY(1);
			this->setRep(L'↓');
		}
	}
}

