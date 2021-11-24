#include "Map.h"
#include <fstream>

Map::Map(int width, int height, int cornerX, int cornerY, int playerX, int playerY):
	player(playerX, playerY, '@')
{
	this->width = width;
	this->height = height;
	this->cornerX = cornerX;
	this->cornerY = cornerY;
	npc = new Npc(0, 0 , 'i', "Leonard");
	chest = new Chest(1, 0, 'C');
	setUpMap();
}

void Map::setUpMap() {
	map = new char*[height];
	for (int i = 0; i < height; i++) {
		map[i] = new char[width];
	}
	std::fstream mapFile;
	mapFile.open("Map0.txt", std::ios::in);
	if (mapFile.is_open()) {
		int num;
		for (int y = 0; y < 20; y++) {
			for (int x = 0; x < 80; x++) {
				mapFile >> num;
				map[y][x] = char(num);
			}
		}
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
	for (int i = 0; i < sizeof(npc); i++) {
		npc[i].draw(screen, cornerX, cornerY);
	}
	for (int i = 0; i < sizeof(chest); i++) {
		chest[i].draw(screen, cornerX, cornerY);
	}
}