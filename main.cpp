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
    if (keyPressed('q')) {
        running = false;
    }
}

void Game::updateAllObjects() {
    //Aqu� se maneja la l�gica del juego
    int x = 4;
    int y = 5;
    char myChar = '@';
}

void Game::updateScreen() {
    //Aqu� se modifica el array que se imprimir�
    draw(30, 0, '@');
}