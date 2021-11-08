#include <iostream>
#include "Game.h"

using namespace std;

int main() {
    Game myGame(120, 30); //Instancia de la clase game de 120 x 30
    while (myGame.running) { //El "Game loop" principal 
        myGame.handleInput();
        myGame.updateAllObjects();
        myGame.updateScreen();
        myGame.renderScreen(); //Esto ya est� definido en Game.cpp
    }
    return 0;
}

void Game::handleInput() {
    //Aqui va el input de player
    if (keyPressed('Q')) {
        running = false;
    }
}

void Game::updateAllObjects() {
    //Aqu� se maneja la l�gica del juego
    int x = 4;
    int y = 5;
    char myChar = '@';
}

void Game::updateScreen() { //Aqu� se modifica el array que se imprimir�
    //Pantalla en blanco (falta implementar ui)
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            draw(x, y, ' ');
        }
    }
    draw(0, 0, '@');
}