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

void draw(char** screen) {
    //do nothing
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