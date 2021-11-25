#pragma once
#include "Player.h"
#include "Npc.h"
#include "Chest.h"

#include <string>

class Map{
public:
    Map(int numMap, int cornerX, int cornerY, int playerX, int playerY);
    void update();
    void draw(char** screen);

    //Objetos
    Player player;
    Npc** npc;
    Chest** chest;

private:
	//Atributos
    std::string name;
    int width;
    int height;
    int cornerX;
    int cornerY;
    int numNPCs;
    int numChests;
    char** map;

    int setUpMap(int numMap);
};