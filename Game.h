#include <Windows.h>
#include "Player.h"

class Game {
public:
    //Constructor
    Game(int screenWidth, int screenHeight);

    //Funciones
    void setUpScreen();

    void handleInput();
    void updateAllObjects();
    void updateScreen();
    void renderScreen();

    void draw(int x, int y, char character);
    void draw(int x, int y, char* myString);
    bool keyPressed(int key);

    void drawMainMenu();
    void drawMap(int numMap);
    void drawUI();

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
    Player player;

    //Variables
    bool running;
    int width;
    int height;

    int cursorPos;

    //Variables privadas para configurar la pantalla
    TCHAR* screen;
    HANDLE console;
    DWORD dwBytesWritten;
};