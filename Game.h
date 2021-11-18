#include <Windows.h>
#include "Player.h"
#include "Npc.h"
#include "Map.h"

class Game {
public:
    //Constructor
    Game(int screenWidth, int screenHeight, int playerHp, int playerX, int playerY);

    //Funciones

    void handleInput();
    void updateAllObjects();
    void updateScreen();
    void renderScreen();

    void draw(int x, int y, char character);
    void draw(int x, int y, char* myString);
    void draw(int x, int y, int num);
    bool keyPressed(int key);

    void drawMainMenu();
    void drawUI();
    void drawCombat();
    void drawEnemy(int numEnemy);
    void drawGameOver();

    //Enum del estado del juego
    enum GameStates {
        MAIN_MENU,
        EXPLORATION,
        COMBAT,
        GAME_OVER,
        CREDITS
    };

    GameStates game_state;

    //Objetos y actores del juego;
    Player *player; //puntero a una instancia de player
    Npc *npcs; //array donde estan los npcs
    Map *map;

    //Variables
    bool running;
    int width;
    int height;

    int cursorPos;
    int lastKeyPressed;

private:
    //Variables privadas y funcion para configurar la pantalla
    char* screen;

    void setUpScreen();
};