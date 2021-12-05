#include "MainUI.h"

MainUI::MainUI(int dialogueX, int dialogueY) {
    this->dialogueX = dialogueX;
    this->dialogueY = dialogueY;
}

void MainUI::displayDialogue(char**screen, std::string line) {
    int numline = 0;
    int numChar = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] != '_') {
            screen[dialogueY + numline][dialogueX + numChar] = line[i];
            numChar += 1;
        }
        else {
            numline += 1;
            numChar = 0;
        }
    }
}

void MainUI::draw(char** screen) {
    //Cuadrante del mapa
    drawOnScreen(screen, 5, 1, "_______________________________> MYRKVI R WOODS <_______________________________");
    for (int i = 0; i < 20; i++) {
        drawOnScreen(screen, 4, 2 + i, '|');
        drawOnScreen(screen, 85, 2 + i, '|');
    }
    drawOnScreen(screen, 5, 21, "________________________________________________________________________________");
    drawOnScreen(screen, 44, 1, (char)209);
    //Cuadrante del texto
    drawOnScreen(screen, 5, 22, "_________________________________________________________________________________");
    for (int i = 0; i < 4; i++) {
        drawOnScreen(screen, 4, 23 + i, '|');
        drawOnScreen(screen, 85, 23 + i, '|');
    }
    drawOnScreen(screen, 3, 27, "_j_______________________________________________________________________________ |");
    drawOnScreen(screen, 2, 28, "(_________________________________________________________________________________@'");
    drawOnScreen(screen, 85, 23, ".@");
    //Cuadrante de los "stats"
    drawOnScreen(screen, 89, 1, "_STATS_____________________");
    for (int i = 0; i < 4; i++) {
        drawOnScreen(screen, 88, 2 + i, '|');
        drawOnScreen(screen, 116, 2 + i, '|');
    }
    drawOnScreen(screen, 88, 6, "|___________________________|");
    drawOnScreen(screen, 90, 3, "HP:");
    drawOnScreen(screen, 90, 4, "ATK:");
    drawOnScreen(screen, 90, 5, "DEF:");
    drawOnScreen(screen, 95, 3, 12);
    drawOnScreen(screen, 95, 4, 12);
    drawOnScreen(screen, 95, 5, 12);
    //Cuadrante del "inventory"
    drawOnScreen(screen, 89, 8, "_INVENTORY_________________");
    for (int i = 0; i < 12; i++) {
        drawOnScreen(screen, 88, 9 + i, '|');
        drawOnScreen(screen, 116, 9 + i, '|');
    }
    drawOnScreen(screen, 88, 21, "|___________________________|");

    char* inventoryNames[4] = { "Health Potion", "Apple", "Candy", "Acorn"};

    for (int i = 0; i < inventory.numObjects; i++) {
        drawOnScreen(screen, 90, 10 + i, inventoryNames[inventory.objects[i]]);
    }
}
