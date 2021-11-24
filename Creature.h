#pragma once
#include "Object.h"

class Creature :
    public Object
{
public:
	Creature(int x, int y, char symbol);

protected:
	enum class Direction {
		LEFT,
		RIGHT,
		UP, 
		DOWN
	};
	//Variables
	void move(Direction direction);
};
