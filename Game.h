#pragma once
#include "Map.h"

#include <Windows.h>

class Game {
public:
    //Constructor
    Game(int screenWidth, int screenHeight, int playerHp, int playerX, int playerY);

    //Métodos
    void run();

    //Métodos
    void updateAllObjects();
    void updateScreen();
    void renderScreen();

private:
    //Variables
    bool running;
    int width;
    int height;

    //Variables privadas y funcion para configurar la pantalla
    char** screen;
    void setUpScreen();

    //Enum del estado del juego
    enum GameStates {
        MAIN_MENU,
        EXPLORATION,
        COMBAT,
        GAME_OVER,
        CREDITS
    };

    GameStates game_state;

    //Objetos y actores del juego
    Map map;
};