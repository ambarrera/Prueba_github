#pragma once
#include "Creature.h"

class Npc :
    public Creature
{
public:
	Npc(int x, int y, char symbol, char* name);

private:
	//Variables
	char name[8];
};