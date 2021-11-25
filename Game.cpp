#include <Windows.h>

#include "Game.h"
#include <iostream>

Game::Game(int screenWidth, int screenHeight, int numMaps):
    mainUI(6, 24), mainMenu()
{
    //Variables
    running = true;
    height = screenHeight;
    width = screenWidth;
    numMap = 0;
    game_state = GameState::MAIN_MENU;
    //Maps
    map = new Map * [numMaps];
    for (int i = 0; i < numMaps; i++) {
        map[i] = new Map(i, 5, 2, 3, 10);
    }

    //Configuraci�n de pantalla
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
        renderScreen(); //Esto ya est� definido en Game.cpp
        //Sleep(32);
    }
}

void Game::updateAllObjects() {//Aqu� se maneja la l�gica del juego
    switch (game_state)
    {
    case GameState::MAIN_MENU:
        switch (mainMenu.update()) {
        case 0:
            changeGameState(GameState::EXPLORATION);
            break;
        case 1:
            changeGameState(GameState::EXPLORATION);
            break;
        case 2:
            changeGameState(GameState::CREDITS);
            break;
        case 3:
            running = false;
            break;
        }
        break;
    case GameState::EXPLORATION:
        int newMapNum;
        int newPlayerX;
        int newPlayerY;
        map[numMap]->update(&newMapNum, &newPlayerX, &newPlayerY);
        if (newMapNum != -1) {
            changeMap(newMapNum, newPlayerX, newPlayerY);
        }
        break;
    case GameState::COMBAT:
        //nose a�n
        break;
    case GameState::GAME_OVER:
        //nose a�n
        break;
    case GameState::CREDITS:
        //nose a�n
        break;
    default:
        break;
    }
}

void Game::updateScreen() { //Aqu� se modifica el array que se imprimir�
    switch (game_state)
    {
    case GameState::MAIN_MENU:
        mainMenu.draw(screen);
        break;
    case GameState::EXPLORATION:
        mainUI.draw(screen);
        if (map[numMap]->npc != nullptr) {
            mainUI.displayDialogue(screen, map[numMap]->npc[0]->getLineDialogue(0));
        }
        map[numMap]->draw(screen);
        break;
    case GameState::COMBAT:
        //nose a�n
        break;
    case GameState::GAME_OVER:
        //nose a�n
        break;
    case GameState::CREDITS:
        //nose a�n
        break;
    default:
        break;
    }
}

void Game::changeGameState(GameState newstate) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            screen[y][x] = ' ';
        }
    }
    game_state = newstate;
}

void Game::changeMap(int newMapNum, int newPlayerX, int newPlayerY) {
    numMap = newMapNum;
    map[numMap]->player.setCoordinates(newPlayerX, newPlayerY);
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