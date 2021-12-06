#include "GameOverMenu.h"

GameOverMenu::GameOverMenu() :
    Menu(0, 2) {}

void GameOverMenu::draw(char** screen) {
    //Titulo
    drawOnScreen(screen, 45, 10, "GAME OVER");

    //Comandos(?)
    drawOnScreen(screen, 45, 15, "Try Again");
    drawOnScreen(screen, 45, 16, "Exit Game");

    //Cursor
    drawOnScreen(screen, 43, 15 + lastCursorPos, ' ');
    drawOnScreen(screen, 43, 15 + cursorPos, char(175));
}