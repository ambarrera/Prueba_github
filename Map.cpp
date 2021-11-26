#include "Map.h"
#include <fstream>

Map::Map(int numMap, int cornerX, int cornerY, int playerX, int playerY):
	player(playerX, playerY, '@')
{
	this->cornerX = cornerX;
	this->cornerY = cornerY;
	numNPCs = setUpMap(numMap);
	std::string filename = "Npc";
	filename += std::to_string(numMap);
	switch (numNPCs)
	{
	case 0:
		npc = nullptr;
		break;
	case 1:
		filename += ".txt";
		npc = new Npc * [numNPCs];
		npc[0] = new Npc(filename);
		break;
	default:
		filename += "-";
		npc = new Npc * [numNPCs];
		std::string fileNameNpc;
		for (int i = 0; i < numNPCs; i++) {
			fileNameNpc = filename + std::to_string(i);
			fileNameNpc += ".txt";
			npc[i] = new Npc(fileNameNpc);
		}
		break;
	}
}

Map::~Map() {
	delete[] npc;
	delete[] chest;
	delete[] teleporter;
}

int Map::setUpMap(int numMap) {
	int returnValue = 0;
	std::string filename = "Map";
	filename += std::to_string(numMap);
	filename += ".txt";
	std::fstream mapFile;
	mapFile.open(filename, std::ios::in);
	if (mapFile.is_open()) {
		std::getline(mapFile, name);
		int num;
		mapFile >> num;
		this->width = num;
		mapFile >> num;
		this->height = num;
		mapFile >> num;
		returnValue = num;
		mapFile >> num;
		numChests = num;
		if (num) {
			int chestX;
			int chestY;
			chest = new Chest * [num];
			for (int i = 0; i < num; i++) {
				mapFile >> chestX;
				mapFile >> chestY;
				chest[i] = new Chest(chestX, chestY, 'C');
			}
		}
		else {
			chest = nullptr;
		}
		//Teleporter
		mapFile >> num;
		numTeleporters = num;
		if (num) {
			int teleporterX;
			int teleporterY;
			int newMap;
			int newPlayerX;
			int newPlayerY;
			teleporter = new Teleporter * [num];
			for (int i = 0; i < num; i++) {
				mapFile >> teleporterX;
				mapFile >> teleporterY;
				mapFile >> newMap;
				mapFile >> newPlayerX;
				mapFile >> newPlayerY;
				teleporter[i] = new Teleporter(teleporterX, teleporterY, newMap, newPlayerX, newPlayerY);
			}
		}
		else {
			teleporter = nullptr;
		}
		map = new char* [height];
		for (int i = 0; i < height; i++) {
			map[i] = new char[width];
		}
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				mapFile >> num;
				map[y][x] = char(num);
			}
		}
		mapFile.close();
	}
	return returnValue;
}

void Map::update(int* newMapNum, int* newPlayerX, int* newPLayerY, int* typeOfObject, int* numObject) {
	*(newMapNum) = -1;
	*(newPlayerX) = 0;
	*(newPLayerY) = 0;
	int numInteractions;
	checkInteractions(typeOfObject, numObject);
	switch (*(typeOfObject)) {
	case 1:
		numInteractions = npc[*(numObject)]->numLines;
		break;
	case 2:
		numInteractions = 1;
		break;
	case 3:
		*(newMapNum) = teleporter[*(numObject)]->newMap;
		*(newPlayerX) = teleporter[*(numObject)]->newPlayerX;
		*(newPLayerY) = teleporter[*(numObject)]->newPlayerY;
		numInteractions = 0;
	default:
		numInteractions = 0;
		break;
	}
	player.update(numInteractions);
	for (int i = 0; i < numNPCs; i++) {
		npc[i]->update();
	}
	for (int i = 0; i < numChests; i++) {
		chest[i]->update();
	}
}

void Map::draw(char** screen) {
	//Map
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			screen[cornerY + y][cornerX + x] = map[y][x];
		}
	}
	//Objects
	for (int i = 0; i < numNPCs; i++) {
		npc[i]->draw(screen, cornerX, cornerY);
	}
	for (int i = 0; i < numChests; i++) {
		chest[i]->draw(screen, cornerX, cornerY);
	}
	for (int i = 0; i < numTeleporters; i++) {
		teleporter[i]->draw(screen, cornerX, cornerY);
	}
	player.draw(screen, cornerX, cornerY);
}

void Map::checkInteractions(int* typeOfObject, int* numObject) {
	*(typeOfObject) = 0;
	*(numObject) = 0;
	int playerX, playerY;
	player.getCoordinates(&playerX, &playerY);
	//Check npcs
	int npcX, npcY;
	for (int i = 0; i < numNPCs; i++) {
		npc[i]->getCoordinates(&npcX, &npcY);
		if (playerX == npcX) {
			if (playerY == npcY - 1 || playerY == npcY + 1) {
				*(typeOfObject) = 1;
				*(numObject) = i;
			}
		}
		else if (playerY == npcY) {
			if (playerX == npcX - 1 || playerX == npcX + 1) {
				*(typeOfObject) = 1;
				*(numObject) = i;
			}
		}
	}
	//Check chests
	int chestX, chestY;
	for (int i = 0; i < numChests; i++) {
		chest[i]->getCoordinates(&chestX, &chestY);
		if (playerX == chestX) {
			if (playerY == chestY - 1 || playerY == chestY + 1) {
				*(typeOfObject) = 2;
				*(numObject) = i;
			}
		}
		else if (playerY == chestY) {
			if (playerX == chestX - 1 || playerX == chestX + 1) {
				*(typeOfObject) = 2;
				*(numObject) = i;
			}
		}
	}
	//Check teleporters
	int teleporterX, telerporterY;
	for (int i = 0; i < numTeleporters; i++) {
		teleporter[i]->getCoordinates(&teleporterX, &telerporterY);
		if (playerX == teleporterX && playerY == telerporterY) {
			*(typeOfObject) = 3;
			*(numObject) = i;
		}
	}
}