#include "UI.h"

UI::UI() {}

void UI::drawOnScreen(char** screen, int x, int y, char symbol) {
    screen[y][x] = symbol;
}

void UI::drawOnScreen(char** screen, int x, int y, char* line) {
    for (int i = 0; *(line + i) != '\0'; i++) {
        screen[y][x + i] = *(line + i);
    }
}

void UI::draw(char** screen) {
    drawOnScreen(screen, 45, 10, "CREDITS");

    //Nombres
    drawOnScreen(screen, 45, 13, "Mariana Caceres");
    drawOnScreen(screen, 45, 14, "Diego Zeballos");
    drawOnScreen(screen, 45, 15, "Amara Barrera");
    drawOnScreen(screen, 45, 16, "Gabriel Nuñez");

    drawOnScreen(screen, 45, 18, "Press 'J' to go back.");
}

void UI::drawOnScreen(char** screen, int x, int y, int num) {
    char numChars[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    if (num >= 100) {
        screen[y][x] = numChars[num / 100];
        screen[y][x + 1] = numChars[(num % 100) / 10];
        screen[y][x + 2] = numChars[(num % 100) % 10];
    }
    else if (num >= 10) {
        screen[y][x] = numChars[num / 10];
        screen[y][x + 1] = numChars[num % 10];
    }
    else {
        screen[y][x] = numChars[num];
    }
}