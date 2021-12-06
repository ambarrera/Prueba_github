#pragma once
#include "UI.h"
#include "Map.h"
#include "MainUI.h"
#include "MainMenu.h"
#include "BattleBoard.h"
#include "GameOverMenu.h"

#include <Windows.h>

class Game {
public:
    //Constructor
    Game(int screenWidth, int screenHeight, int numMaps);
    ~Game();

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
    int numMap;
    int maxMaps;
    int numBattle;
    int maxBattles;
    int numFrame;
    int lastbattle;

    //Variables privadas y funcion para configurar la pantalla
    char** screen;
    void setUpScreen();

    //Enum del estado del juego
    enum class GameState {
        MAIN_MENU,
        EXPLORATION,
        COMBAT,
        GAME_OVER,
        CREDITS
    };

    GameState game_state;

    //Objetos y actores del juego
    Map** map;
    MainUI mainUI;
    MainMenu mainMenu;
    BattleBoard** battle;
    BattleBoard* talkNpc;
    GameOverMenu gomenu;
    UI credits;

    void cleanScreen(int a);
    void changeGameState(GameState newState);
    void changeMap(int newMapNum, int newPlayerX, int newPlayerY);
};