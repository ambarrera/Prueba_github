#include "Chest.h"

Chest::Chest(int x, int y, int typeOfObject):
	Object(x, y, 'C', true)
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