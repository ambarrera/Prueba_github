#include "Inventory.h"

Inventory::Inventory() {
	for (int i = 0; i < 5; i++) {
		objects[i] = 0;
	}
	numObjects = 0;
}

bool Inventory::addObject(int typeOfObject) {
	if (numObjects < 5) {
		objects[numObjects] = typeOfObject;
		numObjects += 1;
		return true;
	}
	else {
		return false;
	}
}

void Inventory::removeObject(int numObject) {
	for (int i = 0; i < 4 - numObject; i++) {
		objects[numObject + i] = objects[numObject + i + 1];
	}
	objects[4] = 0;
}