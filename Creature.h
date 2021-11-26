#pragma once
#include "Object.h"

class Creature :
    public Object
{
public:
	Creature(int x, int y, char symbol);

	int isInteracting;

protected:
	enum class Direction {
		LEFT,
		RIGHT,
		UP, 
		DOWN
	};

	void move(Direction direction);
};
