#pragma once
#include "MapContainer.h"
#include "MapObject.h"
#include "Food.h"
#include "Ghost.h"
#include "Character.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Parser
{
private:
	Character* ch;
	bool Parser::compareScore(int actual, System::String^ inFile);
public:
Parser();
int loadLevel(int x, MapContainer **array);
System::String^ loadHighScore(System::String^ str, int lvl, int actualScore);
Character* getCharacter();
};

