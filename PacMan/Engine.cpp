
#include "Engine.h"
#include "MapContainer.h"
#include <iostream>

using namespace std;


Engine::Engine()
{
	initializeGame();
}

//Thread engThread
void Engine::startEngine()
{
	gameLoop();
}

void Engine::initializeGame()
{
	this->parser = new Parser();
}

void Engine::gameLoop()
{
	this->run = true;
	while (run)
	{
		_sleep(300);
		moveObjects();
		if (run)
		{
			generateMap();
		}
		if (ch->getScore() == this->maxScore)
		{
			String^ s;
			run = false;
			s = parser->loadHighScore(s, this->lvl, this->getScore());
			this->map = "Level completed\n" + s;
		}


	}
}

void Engine::moveObjects()
{
	for (int i = 0;i < 11;i++)
	{
		for (int j = 0; j < 17; j++)
		{
			int numberToMove = array[i][j].getNumberToMove();
			for (int k = 1; k <= numberToMove; k++)
			{
				Movable* mov = array[i][j].getMovable(k);
				if (mov->getStep() == this->stepSwitch)
				{
					if (!this->move(mov, i, j))
					{
						if (mov->getType() == 3)
						{
							Ghost* g = (Ghost*)mov;
							bool up;
							if (i != 0)
								up = !(array[i - 1][j].getFirstObject() != nullptr&&array[i - 1][j].getFirstObject()->getType() == 1);
							else
								up = false;
							bool down;
							if (i != 10)
								down = !(array[i + 1][j].getFirstObject() != nullptr&&array[i + 1][j].getFirstObject()->getType() == 1);
							else
								down = false;
							bool left;
							if (j != 0)
								left = !(array[i][j - 1].getFirstObject() != nullptr&&array[i][j - 1].getFirstObject()->getType() == 1);
							else
								left = false;
							bool right;
							if (i != 16)
								right = !(array[i][j + 1].getFirstObject() != nullptr&&array[i][j + 1].getFirstObject()->getType() == 1);
							else
								right = false;

							g->changeDir(up, down, left, right);
							this->move(g, i, j);
						}
					}
					mov->switchStep();
				}

			}
			array[i][j].SortObjects();
		}
	}
	this->stepSwitch = !this->stepSwitch;
}


bool Engine::move(Movable *gh, int i, int j) {
	int DirX = gh->getDirX();
	int DirY = gh->getDirY();
	bool moved = false;
	if (DirX == 1)
	{
		//Checking bounds
		if (j + 1 <= 16)
		{
			//Checking empty container or solid objects in the way (unable to move)
			if (array[i][j + 1].getFirstObject() == nullptr || 1 != array[i][j + 1].getFirstObject()->getType())
			{
				if (array[i][j + 1].addObject(gh))
				{
					moved = true;
					//if pushed, then remove original pointer
					array[i][j].removeObject((MapObject*)gh);
					makeChecks(i, j + 1);
				}
			}
		}
	}
	if (DirX == -1)
	{
		//Checking bounds
		if (j - 1 >= 0)
		{
			//Checking empty container or solid objects in the way (unable to move)
			if (array[i][j - 1].getFirstObject() == nullptr || 1 != array[i][j - 1].getFirstObject()->getType())
			{
				if (array[i][j - 1].addObject(gh))
				{
					moved = true;
					//if pushed, then remove original pointer
					array[i][j].removeObject((MapObject*)gh);
					makeChecks(i, j - 1);
				}
			}
		}
	}
	if (DirY == 1)
	{
		//Checking bounds
		if (i + 1 <= 10)
		{
			//Checking empty container or solid objects in the way (unable to move)
			if (array[i + 1][j].getFirstObject() == nullptr || 1 != array[i + 1][j].getFirstObject()->getType())
			{
				if (array[i + 1][j].addObject(gh))
				{
					moved = true;
					//if pushed, then remove original pointer
					array[i][j].removeObject((MapObject*)gh);
					makeChecks(i + 1, j);
				}
			}
		}
	}
	if (DirY == -1)
	{
		//Checking bounds
		if (i - 1 >= 0)
		{
			//Checking empty container or solid objects in the way (unable to move)
			if (array[i - 1][j].getFirstObject() == nullptr || 1 != array[i - 1][j].getFirstObject()->getType())
			{
				if (array[i - 1][j].addObject(gh))
				{
					moved = true;
					//if pushed, then remove original pointer
					array[i][j].removeObject((MapObject*)gh);
					makeChecks(i - 1, j);
				}
			}
		}
	}
	return moved;
}

void Engine::makeChecks(int i, int j)
{
	//check if player has been caught by ghost
	if (array[i][j].checkCatched())
	{
		gameOver();
	}
	//check if player has eaten a point
	array[i][j].checkPoints();
}

void Engine::gameOver()
{
	String^ s = L"Game over\n";
	this->map = parser->loadHighScore(s, this->lvl, this->getScore());
	this->run = false;
}


void Engine::stop()
{
	this->run = false;
}

void Engine::setLevel(int x)
{
	this->lvl = x;
	this->array = new MapContainer*[11];
	for (int i = 0; i < 11; ++i) {
		this->array[i] = new MapContainer[17];
	}

	switch (x)
	{
	case 1:
		this->maxScore = parser->loadLevel(1, array);
		break;
	case 2:
		this->maxScore = parser->loadLevel(2, array);
		break;
	}

	this->ch = parser->getCharacter();
	generateMap();
}

void Engine::generateMap()
{
	wchar_t generatedMap[187];
	for (int i = 0;i < 11;i++) {
		for (int j = 0; j < 17; j++)
		{
			int pos = 17 * i + j;
			generatedMap[pos] = this->array[i][j].getRep();

		}
	}
	this->map = gcnew String(generatedMap);
}

int Engine::getScore()
{
	return this->ch->getScore();
}

void Engine::setCharacterMove(int i)
{
	switch (i)
	{
	case 0:
		this->ch->setDirX(-1);
		break;
	case 1:
		this->ch->setDirX(1);
		break;
	case 2:
		this->ch->setDirY(-1);
		break;
	case 3:
		this->ch->setDirY(1);
		break;

	}
}