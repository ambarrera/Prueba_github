#include <Windows.h>

#include "Game.h"
#include <iostream>

Game::Game(int screenWidth, int screenHeight, int playerHp, int playerX, int playerY):
    map(80, 20, 5, 2, 0, 9), ui(6, 24)
{
    //Variables
    running = true;
    height = screenHeight;
    width = screenWidth;
    game_state = MAIN_MENU;

    //Configuración de pantalla
    setUpScreen();
}

void Game::setUpScreen() {
    screen = new char*[height];
    for (int i = 0; i < height; i++) {
        screen[i] = new char[width];
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            screen[y][x] = ' ';
        }
    }
}

void Game::run() {
    while (running) { //El "Game loop" principal 
        updateAllObjects();
        updateScreen();
        renderScreen(); //Esto ya está definido en Game.cpp
        //Sleep(32);
    }
}

void Game::updateAllObjects() {//Aquí se maneja la lógica del juego
    map.update();
}

void Game::updateScreen() { //Aquí se modifica el array que se imprimirá
    ui.draw(screen);
    ui.displayDialogue(screen, map.npc[0].getLineDialogue(2));
    map.draw(screen);
}

void Game::renderScreen() {
    //screen[width * height - 1] = '\0';
    system("CLS");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::cout << screen[y][x];
        }
    }
}