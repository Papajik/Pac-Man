#pragma once
#include "MapContainer.h"
#include "MapObject.h"
#include "Food.h"
#include "Ghost.h";
#include "Character.h";

#include <fstream>
class Parser
{
private:
	Character* ch;
public:
Parser();
int loadLevel(int x, MapContainer **array);
Character* getCharacter();
};

