#include <Windows.h>

#include "Game.h"

Game::Game(int screenWidth, int screenHeight) {
    //Variables
    running = true;
    height = screenHeight;
    width = screenWidth;
    //Setting up the screen (private)
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
}

void Game::draw(int x, int y, char character) {
    screen[y * width + x] = character;
}
