#pragma once
class MapObject
{
private:
int type; //1-obstacle 2-character 3-ghost 4-point
wchar_t rep;
public:
MapObject(int type=1, wchar_t rep = L'█');
~MapObject();
int getType();
wchar_t getRep();
void setRep(wchar_t rep);
};

