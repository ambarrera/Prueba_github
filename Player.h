#pragma once
#include "Creature.h"

class Player:
	public Creature
{
public:
	Player(int x, int y, char symbol);
	void update(bool isAbleToInteract);
	void draw(char** screen, int cornerX, int cornerY);

private:
	void handleInput(bool isAbleToInteract);
	int lastPosX, lastPosY;
};
