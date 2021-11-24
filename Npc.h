#pragma once
#include "Creature.h"
#include <string>

class Npc :
    public Creature
{
public:
	Npc(char* fileName);
	std::string getLineDialogue(int x);

private:
	//Variables
	std::string name;
	std::string* dialogue;
};