#pragma once
#include "MapObject.h"
#include "Movable.h"
#include "Food.h"
#include "Character.h"
class MapContainer
{
public:
	MapContainer();
	~MapContainer();
	bool addObject(MapObject* object);
	MapObject* getFirstObject();
	Movable* getMovable(int pos);
	int getNumberToMove();
	void SortObjects();
	void removeFirstObject();
	wchar_t getRep();
	void removeObject(MapObject* ob);
	bool checkCatched();
	void checkPoints();
private:
	MapObject* objects[4];
	
};

