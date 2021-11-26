#include "Npc.h"
#include <fstream>

Npc::Npc(std::string fileName):
	Creature(0, 0, 'N')
{
	std::fstream npcFile;
	npcFile.open(fileName, std::ios::in);
	if (npcFile.is_open()) {
		std::string line;
		std::getline(npcFile, line);
		name = line;
		int num;
		npcFile >> num;
		symbol = char(num);
		npcFile >> num;
		x = num;
		npcFile >> num;
		y = num;
		npcFile >> num;
		numLines = num;
		dialogue = new std::string[num];
		std::getline(npcFile, line);
		for (int i = 0; i < num; i++) {
			std::getline(npcFile, line);
			dialogue[i] = line;
		}
		npcFile.close();
	}
}

Npc::~Npc() {
	delete[] dialogue;
}

std::string Npc::getLineDialogue(int numLine) {
	return dialogue[numLine];
}