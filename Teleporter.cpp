#include "Teleporter.h"

Teleporter::Teleporter(int x, int y, int newMap, int newPlayerX, int newPlayerY) :
	Object(x, y, char(32), false)
{
	this->newMap = newMap;
	this->newPlayerX = newPlayerX;
	this->newPlayerY = newPlayerY;
}