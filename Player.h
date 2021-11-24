#pragma once
#include "Creature.h"

class Player:
	public Creature
{
public:
	Player(int x, int y, char symbol);

private:
	void handleInput();
};
