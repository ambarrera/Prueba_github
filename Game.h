#include <Windows.h>

class Game {
public:
    //Constructor and Destructor(?)
    Game(int screenWidth, int screenHeight);

    //Functions
    void setUpScreen();

    void handleInput();
    void updateAllObjects();
    void updateScreen();
    void renderScreen();

    void draw(int x, int y, char character);
    bool keyPressed(int key);

    //Variables
    bool running;
    int width;
    int height;

    //Private variables to set up the screen
    TCHAR* screen;
    HANDLE console;
    DWORD dwBytesWritten;
};