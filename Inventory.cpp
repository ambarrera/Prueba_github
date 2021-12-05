#include "Inventory.h"

Inventory::Inventory() {
	for (int i = 0; i < 10; i++) {
		objects[i] = 0;
	}
	numObjects = 0;
}

bool Inventory::addObject(int typeOfObject) {
	if (numObjects < 10) {
		objects[numObjects] = typeOfObject;
		numObjects += 1;
		return true;
	}
	else {
		return false;
	}
}

void Inventory::removeObject(int numObject) {
	for (int i = 0; i < 9 - numObject; i++) {
		objects[numObject + i] = objects[numObject + i + 1];
	}
	objects[9] = 0;
}