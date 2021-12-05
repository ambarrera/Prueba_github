#pragma once
#include "Creature.h"
#include <string>

class Npc :
    public Creature
{
public:
	Npc(std::string fileName, int numNpc);
	~Npc();
	std::string getLineDialogue(int x);

	int numLines;
	int numNpc;

private:
	//Variables
	std::string name;
	std::string* dialogue;
};