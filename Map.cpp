#include "Map.h"
#include <fstream>

Map::Map(int cornerX, int cornerY, int playerX, int playerY):
	player(playerX, playerY, '@')
{
	this->cornerX = cornerX;
	this->cornerY = cornerY;
	npc = new Npc("Npc0.txt");
	chest = new Chest(1, 0, 'C');
	setUpMap();
}

void Map::setUpMap() {
	std::fstream mapFile;
	mapFile.open("Map0.txt", std::ios::in);
	if (mapFile.is_open()) {
		int num;
		mapFile >> num;
		this->width = num;
		mapFile >> num;
		this->height = num;
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
}

void Map::update() {
	player.update();
	for (int i = 0; i < sizeof(npc); i++) {
		npc[i].update();
	}
	for (int i = 0; i < sizeof(chest); i++) {
		chest[i].update();
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
	for (int i = 0; i < 1; i++) {
		npc[i].draw(screen, cornerX, cornerY);
	}
	for (int i = 0; i < 1; i++) {
		chest[i].draw(screen, cornerX, cornerY);
	}
}