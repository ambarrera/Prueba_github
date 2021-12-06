#include <Windows.h>

#include "Game.h"
#include <iostream>
#include <stdio.h>   // NULL
#include <stdlib.h>  // srand and rand
#include <time.h>    // time

Game::Game(int screenWidth, int screenHeight, int numMaps):
    mainUI(6, 24), mainMenu()
{
    srand(time(NULL));
    //Variables
    running = true;
    height = screenHeight;
    width = screenWidth;
    numMap = 0;
    maxMaps = numMaps;
    numBattle = 0;
    maxBattles = 6;
    game_state = GameState::MAIN_MENU;
    talkNpc = nullptr;
    //Maps
    map = new Map * [numMaps];
    for (int i = 0; i < numMaps; i++) {
        map[i] = new Map(i, 5, 2, 3, 10);
    }
    //Battles
    battle = new BattleBoard * [maxBattles];
    for (int i = 0; i < maxBattles; i++) {
        battle[i] = new BattleBoard(3, 6, 2 + i);
    }

    //Configuración de pantalla
    setUpScreen();
}

Game::~Game() {
    for (int i = 0; i < maxMaps; i++) {
        delete map[i];
    }
    delete[] map;
    for (int i = 0; i < maxBattles; i++) {
        delete battle[i];
    }
    delete[] battle;
    for (int i = 0; i < height; i++) {
        delete[] screen[i];
    }
    delete[] screen;
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
        int newMapNum;
        int newPlayerX;
        int newPlayerY;
        int typeOfObject;
        int numObject;
        map[numMap]->update(&newMapNum, &newPlayerX, &newPlayerY, &typeOfObject, &numObject);
        if (newMapNum != -1) {
            changeMap(newMapNum, newPlayerX, newPlayerY);
        }
        if (map[numMap]->player.isInteracting) {
            switch (typeOfObject)
            {
            case 1:
                if (talkNpc == nullptr) {
                    talkNpc = new BattleBoard(3, 6, 8 + map[numMap]->npc[numObject]->numNpc);
                    for (int i = 0; i < 20; i++) {
                        cleanScreen(i + 2);
                    }
                    talkNpc->update();
                }
                for (int i = 0; i < 3; i++) {
                    cleanScreen(24 + i);
                }
                mainUI.displayDialogue(screen, map[numMap]->npc[numObject]->getLineDialogue(map[numMap]->npc[numObject]->numLines - (map[numMap]->player.isInteracting)));
                break;
            case 2:
                if (mainUI.inventory.addObject(map[numMap]->chest[numObject]->Open())) {
                    switch (map[numMap]->chest[numObject]->Open()) {
                    case 0:
                        mainUI.displayDialogue(screen, "You found a chest, it contains... a potion!_One potion has been added to your inventory");
                        break;
                    case 1:
                        mainUI.displayDialogue(screen, "You found a chest, it contains... an apple!_One apple has been added to your inventory");
                        break;
                    case 2:
                        mainUI.displayDialogue(screen, "You found a chest, it contains... a candy!_One candy has been added to your inventory");
                        break;
                    case 3:
                        mainUI.displayDialogue(screen, "You found a chest, it contains... an acorn!_One acorn has been added to your inventory");
                        break;
                    default:
                        break;
                    }
                    break;
                }
                else {
                    map[numMap]->chest[numObject]->Close();
                    mainUI.displayDialogue(screen, "There is not enough space in your inventory!_Try getting using some of the stuff you already have.");
                }
            default:
                break;
            }
        }
        else {
            delete talkNpc;
            talkNpc = nullptr;
            for (int i = 0; i < 3; i++) {
                cleanScreen(24 + i);
            }
        }
        //Prueba
        int playerX;
        int playerY;
        map[numMap]->player.getCoordinates(&playerX, &playerY);
        if (playerX == 18 && playerY == 10) {
            for (int i = 0; i < 20; i++) {
                cleanScreen(i + 2);
            }
            numBattle = rand() % maxBattles;
            game_state = GameState::COMBAT;
        }
        break;
    case GameState::COMBAT:
        battle[numBattle]->update();
        if (battle[numBattle]->player.hp <= 0) {
            game_state = GameState::GAME_OVER;
        }
        else if (battle[numBattle]->enemy.hp <= 0) {
            for (int i = 0; i < maxBattles; i++) {
                battle[i]->player.hp = battle[numBattle]->player.hp;
            }
            game_state = GameState::EXPLORATION;
        }
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
        mainUI.displayStats(screen, battle[numBattle]->player.hp, battle[numBattle]->player.atk, battle[numBattle]->player.def);
        if (talkNpc == nullptr) {
            map[numMap]->draw(screen);
        }
        else {
            talkNpc->draw(screen);
        }
        break;
    case GameState::COMBAT:
        mainUI.draw(screen);
        mainUI.displayStats(screen, battle[numBattle]->player.hp, battle[numBattle]->player.atk, battle[numBattle]->player.def);
        battle[numBattle]->draw(screen);
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

void Game::changeMap(int newMapNum, int newPlayerX, int newPlayerY) {
    numMap = newMapNum;
    map[numMap]->player.setCoordinates(newPlayerX, newPlayerY);
}

void Game::cleanScreen(int a) {
    for (int i = 0; i < width; i++) {
        screen[a][i] = ' ';
    }
}

void Game::renderScreen() {
    //screen[width * height - 1] = '\0';
    system("CLS");
    for (int y = 0; y < height - 1; y++) {
        for (int x = 0; x < width; x++) {
            std::cout << screen[y][x];
        }
        std::cout << std::endl;
    }
    for (int x = 0; x < width; x++) {
        std::cout << screen[height - 1][x];
    }
}