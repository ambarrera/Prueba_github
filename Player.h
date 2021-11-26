#pragma once
#include "Creature.h"

class Player:
	public Creature
{
public:
	Player(int x, int y, char symbol);
	void update(int numInteractions);
	void draw(char** screen, int cornerX, int cornerY);

private:
	bool handleInput();
	int lastPosX, lastPosY;
	bool lastPressedEnter;
};
