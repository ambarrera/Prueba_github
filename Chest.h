#pragma once
#include "Object.h"

class Chest:
	public Object
{
public:
	Chest(int x, int y, int symbol, int typeOfObject);
	int Open();
	void Close();

	bool isOpen;

private:
	int typeOfObject;
};
