#include "Ghost.h"
#include <stdlib.h> 
#include <time.h>


Ghost::Ghost(wchar_t rep) :Movable(3, rep)
{
}

void Ghost::changeDir(bool up, bool down, bool left, bool right)
{
	
	bool changed = false;
	
	while (!changed) {
		srand(time(NULL));
		int dir = rand() % 4;
		switch (dir)
		{
		case 0:
		{
			if (left)
			{
				changed = true;
				this->setDirX(-1);
				this->setRep(L'←');
				break;
			}
		}

		case 1:
		{
			if (right)
			{
				changed = true;
				this->setDirX(1);
				this->setRep(L'→');
				break;
			}
		}

		case 2:
		{
			if (up)
			{
				changed = true;
				this->setDirY(-1);
				this->setRep(L'↑');
				break;
			}
		}
		case 3:
		{
			if (down)
			{
				changed = true;
				this->setDirY(1);
				this->setRep(L'↓');
				break;
			}
		}
		}
	}
}

