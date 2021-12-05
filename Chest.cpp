#include "Chest.h"

Chest::Chest(int x, int y, int symbol, int typeOfObject):
	Object(x, y, symbol, true)
{
	this->typeOfObject = typeOfObject;
	isOpen = false;
}

int Chest::Open() {
	isOpen = true;
	return typeOfObject;
}

void Chest::Close() {
	isOpen = false;
}