#include <iostream>
#include "Game.h"
#include "Player.h"

using namespace std;

int main() {
    Game myGame(120, 30); //Instancia de la clase game de 120 x 30
    while (myGame.running) { //El "Game loop" principal 
        myGame.handleInput();
        myGame.updateAllObjects();
        myGame.updateScreen();
        myGame.renderScreen(); //Esto ya está definido en Game.cpp
    }
    return 0;
}

void Game::handleInput() {
    //Aqui va el input de player
    if (keyPressed('Q')) {
        running = false;
    }
    if (keyPressed('D')) {
        game_state = GAME_OVER;
    }
}

void Game::updateAllObjects() {
    //Aquí se maneja la lógica del juego
    int x = 4;
    int y = 5;
    char myChar = '@';
}

void Game::updateScreen() { //Aquí se modifica el array que se imprimirá
    //Pantalla en blanco (falta implementar ui)
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            draw(x, y, ' ');
        }
    }
    switch (game_state) {
    case MAIN_MENU:
        draw(0, 0, "Main Menu");
        break;
    case GAME_OVER:
        draw(0, 0, "Game Over");
        break;
    default:
        break;
    }
}