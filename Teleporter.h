#pragma once
#include "Object.h"
class Teleporter :
    public Object
{
public:
    Teleporter(int x, int y, int newMap, int newPlayerX, int newPlayerY);
    int newMap;
    int newPlayerX;
    int newPlayerY;
};
