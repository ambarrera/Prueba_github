#include <iostream>
#include "Game.h"

using namespace std;

int main() {
    Game myGame(120, 30); //Instancia de la clase game de 120 x 30
    while (myGame.running) { //El "Game loop" principal 
        myGame.handleInput();
        myGame.updateAllObjects();
        myGame.updateScreen();
        myGame.renderScreen(); //Esto ya está definido en Game.cpp
        Sleep(64);
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

    //Según el "game_state"
    switch (game_state) {
    case MAIN_MENU:
        if (keyPressed(VK_SPACE)) {
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
        }
        if (keyPressed('W')) {
            if (cursorPos != 0)
                cursorPos -= 1;
        }
        if (keyPressed('S')) {
            if (cursorPos != 3)
                cursorPos += 1;
        }
        break;

    case EXPLORATION:
        if (keyPressed('A')) {
            if (player.x != 5)
                player.x -= 1;
        }
        if (keyPressed('D')) {
            if (player.x != 84)
                player.x += 1;
        }
        if (keyPressed('W')) {
            if (player.y != 2)
                player.y -= 1;
        }
        if (keyPressed('S')) {
            if (player.y != 21)
                player.y += 1;
        }
        break;

    case COMBAT:
        break;

    case GAME_OVER:
        if (keyPressed('J')) {
            switch (cursorPos) {
            case 0:
                game_state = EXPLORATION;
                player.hp = 247;
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
        if (keyPressed('W')) {
            if (cursorPos != 0)
                cursorPos -= 1;
        }
        if (keyPressed('S')) {
            if (cursorPos != 1)
                cursorPos += 1;
        }
        break;

    case CREDITS:
        if (keyPressed('J')) {
            game_state = MAIN_MENU;
        }
        break;
    }
}

void Game::updateAllObjects() {
    //Aquí se maneja la lógica del juego
    switch (game_state) {
    case MAIN_MENU:
        break;

    case EXPLORATION:
        if (player.x == 30)
            game_state = COMBAT;
        if (player.hp <= 0) {
            player.hp = 0;
            game_state = GAME_OVER;
        }
        break;

    case COMBAT:
        player.hp -= 1;
        if (player.hp <= 0) {
            player.hp = 0;
            game_state = GAME_OVER;
        }
        break;

    case GAME_OVER:
        break;

    case CREDITS:
        break;
    }
   
}

void Game::updateScreen() { //Aquí se modifica el array que se imprimirá
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
        drawMap(0);
        draw(player.x, player.y, '@');
        break;

    case COMBAT:
        drawUI();
        draw(38, 1, "    COMBAT    ");
        break;

    case GAME_OVER:
        draw(0, 0, "Game Over");
        draw(0, 1, "Press J to choose an option");
        drawGameOver();
        break;

    case CREDITS:
        draw(0, 0, "Credits (Work in progress)");
        draw(0, 1, "Press J to go back");
        break;
    }
}