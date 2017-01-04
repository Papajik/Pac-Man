#pragma once
#include<string>
#include "Parser.h"
using namespace System;
ref class Engine
{
public:
String^ map;
bool run = false;

Engine();
void startEngine();
void stop();
void setLevel(int x);
int getScore();
void setCharacterMove(int i);
private:

MapContainer** array;
Parser* parser;
Character* ch;
	//switch of steps (controls steps of movable objects - one step per engine step)
bool stepSwitch = false;
int maxScore = 0;
int lvl = 0;

void moveObjects();
void gameLoop();
void initializeGame();
void generateMap();
bool move(Movable *ghost, int i, int j);
void makeChecks(int i, int j);
void gameOver();
};
