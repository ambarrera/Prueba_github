#pragma once

class Inventory
{
public:
	Inventory();
	bool addObject(int typeOfObject);
	void removeObject(int numObject);

	int objects[10];
	int numObjects;
};
