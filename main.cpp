#include <iostream>
#include "Game.h"


using namespace std;

int main() {
    Game myGame(120, 30, 100, 12, 12); //Instancia de la clase game de 120 x 30
    while (myGame.running) { //El "Game loop" principal 
        myGame.handleInput();
        myGame.updateAllObjects();
        myGame.updateScreen();
        myGame.renderScreen(); //Esto ya est� definido en Game.cpp
        //Sleep(32);
    }
    return 0;
}

void Game::handleInput() {
    //Aqui va el input de player
    if (keyPressed(VK_ESCAPE)) {
        running = false;
    }
    if (keyPressed('M')) {
        game_state = MAIN_MENU;
    }

    //Seg�n el "game_state"
    switch (game_state) {
    case MAIN_MENU:
        if (keyPressed(VK_SPACE)) {
            if (lastKeyPressed != VK_SPACE) {
                switch (cursorPos) {
                case 0:
                    game_state = EXPLORATION;
                    cursorPos = 0;
                    break;
                case 1:
                    game_state = EXPLORATION;
                    cursorPos = 0;
                    break;
                case 2:
                    game_state = CREDITS;
                    break;
                case 3:
                    running = false;
                    break;
                default:
                    break;
                }
                lastKeyPressed = VK_SPACE;
            }
        }
        else if (keyPressed('W')) {
            if (cursorPos != 0 && lastKeyPressed != 'W') {
                cursorPos -= 1;
                lastKeyPressed = 'W';
            }
        }
        else if (keyPressed('S')) {
            if (cursorPos != 3 && lastKeyPressed != 'S') {
                cursorPos += 1;
                lastKeyPressed = 'S';
            }
        }
        else {
            lastKeyPressed = 0;
        }
        break;

    case EXPLORATION:
        if (keyPressed('A')) {
            if (player -> x != 5)
                player -> x -= 1;
        }
        if (keyPressed('D')) {
            if (player -> x != 84)
                player -> x += 1;
        }
        if (keyPressed('W')) {
            if (player -> y != 2)
                player -> y -= 1;
        }
        if (keyPressed('S')) {
            if (player -> y != 21)
                player -> y += 1;
        }
        break;

    case COMBAT:
        if (keyPressed('A')) {
            if ((player->square % 6) != 0 && lastKeyPressed != 'A') {
                player->square -= 1;
                lastKeyPressed = 'A';
            }
        }
        else if (keyPressed('D')) {
            if ((player->square + 1) % 6 != 0 && lastKeyPressed != 'D') {
                player->square += 1;
                lastKeyPressed = 'D';
            }
        }
        else if (keyPressed('W')) {
            if (player->square >= 6 && lastKeyPressed != 'W') {
                player->square -= 6;
                lastKeyPressed = 'W';
            }
        }
        else if (keyPressed('S')) {
            if (player->square <= 11 && lastKeyPressed != 'S') {
                player->square += 6;
                lastKeyPressed = 'S';
            }
        }
        else {
            lastKeyPressed = 0;
        }
        break;

    case GAME_OVER:
        if (keyPressed(VK_SPACE)) {
            if (lastKeyPressed != VK_SPACE) {
                switch (cursorPos) {
                case 0:
                    game_state = EXPLORATION;
                    player->hp = 247;
                    cursorPos = 0;
                    break;
                case 1:
                    game_state = MAIN_MENU;
                    cursorPos = 0;
                    break;
                default:
                    break;
                }
            }
        }
        else if (keyPressed('W')) {
            if (cursorPos != 0 && lastKeyPressed != 'W') {
                cursorPos -= 1;
                lastKeyPressed = 'W';
            }
        }
        else if (keyPressed('S')) {
            if (cursorPos != 1 && lastKeyPressed != 'S') {
                cursorPos += 1;
                lastKeyPressed = 'S';
            }
        }
        else {
            lastKeyPressed = 0;
        }
        break;

    case CREDITS:
        if (keyPressed(VK_SPACE)) {
            if (lastKeyPressed != VK_SPACE) {
                game_state = MAIN_MENU;
                lastKeyPressed = VK_SPACE;
            }
        }
        else {
            lastKeyPressed = 0;
        }
        break;
    }
}

void Game::updateAllObjects() {
    //Aqu� se maneja la l�gica del juego
    switch (game_state) {
    case MAIN_MENU:
        break;

    case EXPLORATION:
        if (player -> x == 30)
            game_state = COMBAT;
        if (player -> hp <= 0) {
            player -> hp = 0;
            game_state = GAME_OVER;
        }
        if (player -> y == 21 && map->numMap == 0) {
            map->numMap = 1;
            player -> y = 3;
            player->x = player->x + 2;
        }
        if (player->y == 2 && map->numMap == 1) {
            map->numMap = 0;
            player->x = player->x - 2;
            player-> y = 20;
        }
        if (player->y == 2 && map->numMap ==0) {
            map->numMap = 2;
            player->y = 20;
        }
        if (player->y == 21 && map->numMap == 2) {
            map->numMap = 0;
            player->y = 3;
        }
        break;

    case COMBAT:
        if (player -> hp <= 0) {
            player -> hp = 0;
            game_state = GAME_OVER;
        }
        break;

    case GAME_OVER:
        break;

    case CREDITS:
        break;
    }
   
}

void Game::updateScreen() { //Aqu� se modifica el array que se imprimir�
    //Pantalla en blanco (falta implementar ui)
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            draw(x, y, ' ');
        }
    }
    //Dibuja la parte del juego correspondiente
    switch (game_state) {
    case MAIN_MENU:
        drawMainMenu();
        break;

    case EXPLORATION:
        drawUI();
        drawMap(map->numMap);
        draw(npcs[0].x, npcs[0].y, '#');
        draw(player -> x, player -> y, '@');
        break;

    case COMBAT:
        drawUI();
        draw(38, 1, "    COMBAT    ");
        drawCombat();
        drawEnemy(1);
        break;

    case GAME_OVER:
        draw(0, 0, "Game Over");
        draw(0, 1, "Press SPACE to choose an option");
        drawGameOver();
        break;

    case CREDITS:
        draw(0, 0, "Credits (Work in progress)");
        draw(0, 1, "Press SPACE to go back");
        break;
    }
}