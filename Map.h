#pragma once
#include "Player.h"
#include "Npc.h"
#include "Chest.h"
#include "Teleporter.h"

#include <string>

class Map{
public:
    Map(int numMap, int cornerX, int cornerY, int playerX, int playerY);
    void update(int *newMapNum, int *newPlayerX, int *newPLayerY);
    void draw(char** screen);

    //Objetos
    Player player;
    Npc** npc;
    Chest** chest;
    Teleporter** teleporter;

private:
	//Atributos
    std::string name;
    int width;
    int height;
    int cornerX;
    int cornerY;
    int numNPCs;
    int numChests;
    int numTeleporters;
    char** map;

    int setUpMap(int numMap);
    void checkInteractions(int* typeOfObject, int* numObject);
};