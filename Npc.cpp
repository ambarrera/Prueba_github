#include "Npc.h"
#include <fstream>

Npc::Npc(int x, int y, char symbol, char* name):
	Creature(x, y, symbol)
{
	for (int i = 0; name[i] != '\0'; i++) {
		this->name[i] = name[i];
	}
	setUpDialogue();
}

void Npc::setUpDialogue() {
	std::fstream npcFile;
	npcFile.open("Npc0.txt", std::ios::in);
	if (npcFile.is_open()) {
		int numLines;
		npcFile >> numLines;
		dialogue = new std::string[numLines];
		std::string line;
		for (int i = 0; i < numLines; i++) {
			std::getline(npcFile, line);
			dialogue[i] = line;
		}
		npcFile.close();
	}
}

std::string Npc::getLineDialogue(int numLine) {
	return dialogue[numLine];
}