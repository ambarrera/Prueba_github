#include <iostream>
#include "Game.h"
//#include "Player.h"

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
    if (keyPressed('E')) {
        game_state = GAME_OVER;
    }
    if (keyPressed('R')) {
        game_state = EXPLORATION;
    }
    if (keyPressed('W')) {
        player.y -= 1;
    }
    if (keyPressed('S')) {
        player.y += 1;
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
    //Prueba de cambio de Game_states
    switch (game_state) {
    case MAIN_MENU:
        draw(0, 0, "Main Menu");
        break;
    case EXPLORATION:
        //Cuadrante del mapa
        draw(5, 1, "_______________________________> MYRKVI R WOODS <_______________________________");
        for (int i = 0; i < 20; i++) {
            draw(4, 2 + i, '|');
            draw(85, 2 + i, '|');
        }
        draw(5, 21, "________________________________________________________________________________");
        draw(44, 1, (char)209);
        //Cuadrante del texto
        draw(5, 22, "_________________________________________________________________________________");
        for (int i = 0; i < 4; i++) {
            draw(4, 23 + i, '|');
            draw(85, 23 + i, '|');
        }
        draw(3, 27, "_j_______________________________________________________________________________ |");
        draw(2, 28, "(_________________________________________________________________________________@'");
        draw(85, 23, ".@");
        //Cuadrante de los "stats"
        draw(89, 1, "_STATS_____________________");
        for (int i = 0; i < 4; i++) {
            draw(88, 2 + i, '|');
            draw(116, 2 + i, '|');
        }
        draw(88, 6, "|___________________________|");
        //Cuadrante del "inventory"
        draw(89, 8, "_INVENTORY_________________");
        for (int i = 0; i < 12; i++) {
            draw(88, 9 + i, '|');
            draw(116, 9 + i, '|');
        }
        draw(88, 21, "|___________________________|");
        break;
    case GAME_OVER:
        draw(0, 0, "Game Over");
        break;
    default:
        break;
    }

    draw(player.x, (player.y) / 200, '@');
}