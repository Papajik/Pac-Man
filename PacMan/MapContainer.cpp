#include "MapContainer.h"


using namespace std;
MapContainer::MapContainer()
{
	for (int i = 0; i < 4; i++)
	{
		this->objects[i] = nullptr;
	}
}

bool MapContainer::addObject(MapObject* object)
{
	bool added = false;
	for (int i = 0; i < 4; i++)
	{
		if (this->objects[i] == nullptr)
		{
			this->objects[i] = object;
			SortObjects();
			added = true;
			break;
		}
	}

	return added;
}

MapObject* MapContainer::getFirstObject()
{
	return (this->objects[0]);
}

Movable* MapContainer::getMovable(int k)
{
	int count = 1;
	bool foundNotNull = true;
	for (int i = 0; i < 4; i++)
	{
		//skips already moved items
		if (foundNotNull&&objects[i] == nullptr)
		{
			count++;
		}
		if (this->objects[i] != nullptr && (objects[i]->getType() == 3 || objects[i]->getType() == 2))
		{
			foundNotNull = false;
			if (k == count)
			{
				return (Movable*)objects[i];
			}
			else count++;
		}

	}
}
wchar_t MapContainer::getRep()
{
	if (this->objects[0] == nullptr)
	{
		return L' ';
	}
	else return this->objects[0]->getRep();
}

MapContainer::~MapContainer()
{
}

int MapContainer::getNumberToMove()
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (this->objects[i] != nullptr)
		{
			int type = this->objects[i]->getType();
			if (type == 2 || type == 3)
				count++;
		}

	}
	return count;
}
void MapContainer::removeFirstObject()
{
	objects[0] = nullptr;
	//SortObjects();
}
void MapContainer::removeObject(MapObject* ob)
{
	for (int i = 0; i < 4; i++)
	{
		if (objects[i] == ob)
		{
			objects[i] = nullptr;
		}
	}
}

void MapContainer::SortObjects()
{
	//Order of types: 2-3-4-(1): 1 always alone
	MapObject* temp;
	//Bubble sort null
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3 - i; j++)
		{
			if (objects[j] == nullptr)
			{
				temp = objects[j + 1];
				objects[j + 1] = objects[j];
				objects[j] = temp;
			}
		}
	}
	//Control of nulls
	int invalid = 0;
	for (int i = 0; i < 4; i++)
	{
		if (objects[i] == nullptr)
			invalid++;
	}
	//Bubble sort
	for (int i = 0; i < 3 - invalid; i++)
	{
		for (int j = 0; j < 3 - invalid - i; j++)
		{
			if (objects[j + 1]->getType() < objects[j]->getType())
			{
				temp = objects[j + 1];
				objects[j + 1] = objects[j];
				objects[j] = temp;
			}
		}
	}
}

bool MapContainer::checkCatched()
{
	bool ghost = false;
	bool player = false;
	for (int i = 0; i < 4; i++)
	{
		if (objects[i] != nullptr)
		{
			if (objects[i]->getType() == 3)
			{
				ghost = true;
			}
			else
				if (objects[i]->getType() == 2)
				{
					player = true;
				}
		}
	}
	return  (ghost == player == true);
}

void MapContainer::checkPoints()
{
	Character* ch = nullptr;
	Food* point = nullptr;
	for (int i = 0; i < 4; i++)
	{
		if (objects[i] !=nullptr)
		{
			if (objects[i]->getType() == 2)
			{
				ch = (Character*)objects[i];
			}
			else
				if (objects[i]->getType() == 4)
				{
					point = (Food*)objects[i];
				}
		}
	}
	if (ch != nullptr&&point != nullptr)
	{
		ch->increaseScore(point->getPoints());
		this->removeObject(point);
	}
}
