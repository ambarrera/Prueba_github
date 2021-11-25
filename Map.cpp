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

void Map::update() {
	player.update();
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
	player.draw(screen, cornerX, cornerY);
	for (int i = 0; i < numNPCs; i++) {
		npc[i]->draw(screen, cornerX, cornerY);
	}
	for (int i = 0; i < numChests; i++) {
		chest[i]->draw(screen, cornerX, cornerY);
	}
}