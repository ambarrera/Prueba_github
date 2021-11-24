#pragma once
#include "Player.h"
#include "Npc.h"
#include "Chest.h"

class Map{
public:
    Map(int width, int height, int cornerX, int cornerY, int playerX, int playerY);
    void update();
    void draw(char** screen);

    //Objetos
    Player player;
    Npc* npc;
    Chest* chest;

private:
	//Variables
    int width;
    int height;
    int cornerX;
    int cornerY;
    char** map;

    void setUpMap();
};