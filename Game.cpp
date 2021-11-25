#include <Windows.h>

#include "Game.h"
#include <iostream>

Game::Game(int screenWidth, int screenHeight, int playerHp, int playerX, int playerY):
    map(0, 5, 2, 0, 9), mainUI(6, 24), mainMenu()
{
    //Variables
    running = true;
    height = screenHeight;
    width = screenWidth;
    game_state = GameState::MAIN_MENU;

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
        map.update();
        break;
    case GameState::COMBAT:
        //nose aún
        break;
    case GameState::GAME_OVER:
        //nose aún
        break;
    case GameState::CREDITS:
        //nose aún
        break;
    default:
        break;
    }
}

void Game::updateScreen() { //Aquí se modifica el array que se imprimirá
    switch (game_state)
    {
    case GameState::MAIN_MENU:
        mainMenu.draw(screen);
        break;
    case GameState::EXPLORATION:
        mainUI.draw(screen);
        mainUI.displayDialogue(screen, map.npc[0]->getLineDialogue(0));
        map.draw(screen);
        break;
    case GameState::COMBAT:
        //nose aún
        break;
    case GameState::GAME_OVER:
        //nose aún
        break;
    case GameState::CREDITS:
        //nose aún
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

void Game::renderScreen() {
    //screen[width * height - 1] = '\0';
    system("CLS");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::cout << screen[y][x];
        }
    }
}