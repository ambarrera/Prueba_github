#pragma once
#include "Object.h"

class Chest:
	public Object
{
public:
	Chest(int x, int y, int typeOfObject);
	int Open();
	void Close();

	bool isOpen;

private:
	int typeOfObject;
};
