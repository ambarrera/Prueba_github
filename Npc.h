#pragma once
#include "Creature.h"
#include <string>

class Npc :
    public Creature
{
public:
	Npc(int x, int y, char symbol, char* name);
	std::string getLineDialogue(int x);

private:
	//Variables
	char name[8];
	std::string* dialogue;

	void setUpDialogue();
};