#include <Windows.h>

#include "Game.h"

Game::Game(int screenWidth, int screenHeight) {
    //Variables
    running = true;
    height = screenHeight;
    width = screenWidth;
    game_state = MAIN_MENU;

    //Configuración de pantalla (private)
    setUpScreen();
}

void Game::setUpScreen() {
    screen = new TCHAR[width * height];
    console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    dwBytesWritten = 0;
    SetConsoleActiveScreenBuffer(console);
}

void Game::renderScreen() {
    screen[width * height - 1] = '\0';
    WriteConsoleOutputCharacter(console, screen, width * height, { 0, 0 }, &dwBytesWritten);
}

bool Game::keyPressed(int key) {
    if (GetAsyncKeyState(key) & 0x8000)
        return true;
    return false;
}

void Game::draw(int x, int y, char character) {
    screen[y * width + x] = character;
}

void Game::draw(int x, int y, char* myString) {
    for (int i = 0; i < height * width; i++) {
        if (myString[i] == '\0')
            break;
        screen[y * width + x + i] = myString[i];
    }
}