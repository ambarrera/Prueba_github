#pragma once
#include "Creature.h"
#include <string>

class Npc :
    public Creature
{
public:
	Npc(std::string fileName);
	~Npc();
	std::string getLineDialogue(int x);

	int numLines;

private:
	//Variables
	std::string name;
	std::string* dialogue;
};