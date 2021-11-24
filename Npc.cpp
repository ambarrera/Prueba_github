#include "Npc.h"
#include <fstream>

Npc::Npc(char* fileName):
	Creature(0, 0, 'N')
{
	std::fstream npcFile;
	npcFile.open(fileName, std::ios::in);
	if (npcFile.is_open()) {
		std::string line;
		std::getline(npcFile, line);
		name = line;
		int numLines;
		npcFile >> numLines;
		symbol = char(numLines);
		npcFile >> numLines;
		x = numLines;
		npcFile >> numLines;
		y = numLines;
		npcFile >> numLines;
		dialogue = new std::string[numLines];
		std::getline(npcFile, line);
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