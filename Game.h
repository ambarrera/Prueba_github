#include <Windows.h>

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
    bool keyPressed(int key);

    //Enum del estado del juego
    enum GameStates {
        MAIN_MENU,
        EXPLORATION,
        COMBAT,
        GAME_OVER
    };

    GameStates game_state;

    //Variables
    bool running;
    int width;
    int height;

    //Variables privadas para configurar la pantalla
    TCHAR* screen;
    HANDLE console;
    DWORD dwBytesWritten;
};