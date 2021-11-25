#pragma once
#include "Creature.h"

class Player:
	public Creature
{
public:
	Player(int x, int y, char symbol);
	void update();
	void draw(char** screen, int cornerX, int cornerY);

private:
	void handleInput();
	int lastPosX, lastPosY;
};
