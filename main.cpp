#include <iostream>
#include "Game.h"

int main() {
    Game game(120, 30, 100, 12, 12); //Instancia de la clase game de 120 x 30
    game.run();
    return 0;
}
/*
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
*/