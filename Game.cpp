#include <Windows.h>

#include "Game.h"

Game::Game(int screenWidth, int screenHeight) {
    //Variables
    running = true;
    height = screenHeight;
    width = screenWidth;
    game_state = MAIN_MENU;
    cursorPos = 0;

    //Configuración de pantalla (private)
    setUpScreen();
}

void Game::setUpScreen() {
    screen = new TCHAR[width * height];
    console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    dwBytesWritten = 0;
    SetConsoleActiveScreenBuffer(console);
}

void Game::renderScreen() {
    screen[width * height - 1] = '\0';
    WriteConsoleOutputCharacter(console, screen, width * height, { 0, 0 }, &dwBytesWritten);
}

bool Game::keyPressed(int key) {
    if (GetAsyncKeyState(key) & 0x8000)
        return true;
    return false;
}

void Game::draw(int x, int y, char character) {
    screen[y * width + x] = character;
}

void Game::draw(int x, int y, char* myString) {
    for (int i = 0; i < height * width; i++) {
        if (*(myString + i) == '\0')
            break;
        screen[y * width + x + i] = *(myString + i);
    }
}

void Game::drawMainMenu() {
    //LETRA M        
    draw(10, 5, char(219)); draw(11, 4, char(219)); draw(12, 3, char(219)); draw(13, 3, char(219)); draw(14, 3, char(219)); draw(15, 3, char(219)); draw(16, 2, char(219)); draw(17, 2, char(219)); draw(18, 2, char(219));
    draw(10, 6, char(219)); draw(11, 5, char(219)); draw(12, 4, char(219)); draw(16, 3, char(219)); draw(17, 3, char(219)); draw(18, 3, char(219)); draw(19, 3, char(219)); draw(20, 3, char(219)); draw(21, 3, char(219)); draw(22, 3, char(219)); draw(23, 3, char(219));
    draw(10, 7, char(219)); draw(11, 6, char(219)); draw(12, 5, char(219)); draw(16, 4, char(219)); draw(17, 4, char(219)); draw(18, 4, char(219)); draw(23, 4, char(219)); draw(24, 4, char(219));
    draw(10, 8, char(219)); draw(11, 7, char(219)); draw(12, 6, char(219)); draw(16, 5, char(219)); draw(17, 5, char(219)); draw(18, 5, char(219)); draw(23, 5, char(219)); draw(24, 5, char(219)); draw(25, 5, char(219));
    draw(10, 9, char(219)); draw(11, 8, char(219)); draw(12, 7, char(219)); draw(16, 6, char(219)); draw(17, 6, char(219)); draw(18, 6, char(219)); draw(23, 6, char(219)); draw(24, 6, char(219)); draw(25, 6, char(219));
    draw(11, 9, char(219)); draw(12, 8, char(219)); draw(16, 7, char(219)); draw(17, 7, char(219)); draw(18, 7, char(219)); draw(23, 7, char(219)); draw(24, 7, char(219)); draw(25, 7, char(219));
    draw(11, 10, char(219)); draw(12, 9, char(219)); draw(16, 8, char(219)); draw(17, 8, char(219)); draw(18, 8, char(219)); draw(23, 8, char(219)); draw(24, 8, char(219)); draw(25, 8, char(219));
    draw(12, 10, char(219)); draw(16, 9, char(219)); draw(17, 9, char(219)); draw(18, 9, char(219)); draw(23, 9, char(219)); draw(24, 9, char(219)); draw(25, 9, char(219));
    draw(12, 11, char(219)); draw(16, 10, char(219)); draw(17, 10, char(219)); draw(18, 10, char(219)); draw(23, 10, char(219)); draw(24, 10, char(219));
    draw(23, 11, char(219));

    //LETRA Y
    draw(27, 3, char(219)); draw(28, 2, char(219)); draw(29, 2, char(219)); draw(30, 4, char(219)); draw(31, 4, char(219)); draw(32, 4, char(219)); draw(33, 3, char(219)); draw(34, 3, char(219)); draw(35, 5, char(219));
    draw(27, 4, char(219)); draw(28, 3, char(219)); draw(29, 3, char(219)); draw(33, 4, char(219)); draw(34, 4, char(219)); draw(35, 6, char(219));
    draw(28, 4, char(219)); draw(29, 4, char(219)); draw(33, 5, char(219)); draw(34, 5, char(219)); draw(35, 7, char(219));
    draw(33, 6, char(219)); draw(34, 6, char(219)); draw(35, 8, char(219));
    draw(27, 7, char(219)); draw(28, 6, char(219)); draw(29, 6, char(219)); draw(33, 7, char(219)); draw(34, 7, char(219)); draw(35, 9, char(219));
    draw(27, 8, char(219)); draw(28, 7, char(219)); draw(29, 7, char(219)); draw(33, 8, char(219)); draw(34, 8, char(219));
    draw(28, 8, char(219)); draw(29, 8, char(219)); draw(33, 9, char(219)); draw(34, 9, char(219));
    draw(28, 9, char(219)); draw(29, 9, char(219)); draw(30, 10, char(219)); draw(31, 10, char(219)); draw(32, 10, char(219)); draw(33, 10, char(219));
    draw(29, 10, char(219));

    //LETRA R                                                      
    draw(38, 6, char(254)); draw(39, 6, char(219)); draw(40, 6, char(219)); draw(41, 6, char(219)); draw(42, 6, char(219)); draw(43, 6, char(219)); draw(44, 6, char(219)); draw(45, 6, char(219)); draw(46, 6, char(219)); draw(47, 6, char(219)); draw(48, 6, char(219)); draw(49, 6, char(219));
    draw(38, 8, char(254)); draw(39, 8, char(219)); draw(40, 8, char(219)); draw(41, 8, char(219)); draw(42, 8, char(219)); draw(43, 8, char(219)); draw(44, 8, char(219)); draw(45, 8, char(219)); draw(46, 8, char(219)); draw(47, 8, char(219)); draw(48, 8, char(219)); draw(49, 8, char(219));
    draw(40, 3, char(219)); draw(41, 3, char(219)); draw(42, 2, char(219)); draw(43, 2, char(219)); draw(44, 2, char(219)); draw(45, 2, char(219)); draw(46, 2, char(219)); draw(47, 2, char(219)); draw(48, 2, char(219));
    draw(40, 4, char(219)); draw(41, 4, char(219)); draw(42, 3, char(219)); draw(47, 3, char(219)); draw(48, 3, char(219)); draw(49, 3, char(219));
    draw(40, 5, char(219)); draw(41, 5, char(219)); draw(42, 4, char(219)); draw(47, 4, char(219)); draw(48, 4, char(219)); draw(49, 4, char(219));
    draw(40, 6, char(219)); draw(41, 6, char(219)); draw(42, 5, char(219)); draw(47, 5, char(219)); draw(48, 5, char(219)); draw(49, 5, char(219));
    draw(40, 7, char(219)); draw(41, 7, char(219)); draw(42, 6, char(219)); draw(47, 6, char(219)); draw(48, 6, char(219)); draw(49, 6, char(219));
    draw(40, 8, char(219)); draw(41, 8, char(219)); draw(42, 7, char(219));
    draw(40, 9, char(219)); draw(41, 9, char(219)); draw(42, 8, char(219)); draw(47, 8, char(219)); draw(48, 8, char(219)); draw(49, 8, char(219));
    draw(40, 10, char(219)); draw(41, 10, char(219)); draw(42, 9, char(219)); draw(47, 9, char(219)); draw(48, 9, char(219)); draw(49, 9, char(219));
    draw(40, 11, char(219)); draw(41, 11, char(219)); draw(42, 10, char(219)); draw(47, 10, char(219)); draw(48, 10, char(219)); draw(49, 10, char(219));
    draw(42, 11, char(219)); draw(47, 11, char(219)); draw(48, 11, char(219)); draw(49, 11, char(219));

    //LETRA K
    draw(51, 6, char(254)); draw(52, 6, char(219));
    draw(53, 4, char(219)); draw(54, 3, char(219)); draw(55, 2, char(219)); draw(60, 2, char(219));
    draw(53, 5, char(219)); draw(54, 4, char(219)); draw(55, 3, char(219)); draw(59, 3, char(219)); draw(60, 3, char(219));
    draw(53, 6, char(219)); draw(54, 5, char(219)); draw(55, 4, char(219)); draw(58, 4, char(219)); draw(59, 4, char(219));
    draw(53, 7, char(219)); draw(54, 6, char(219)); draw(55, 5, char(219)); draw(57, 5, char(219)); draw(58, 5, char(219));
    draw(53, 8, char(219)); draw(54, 7, char(219)); draw(55, 6, char(219)); draw(56, 6, char(219)); draw(57, 6, char(219));
    draw(53, 9, char(219)); draw(54, 8, char(219)); draw(55, 7, char(219)); draw(56, 7, char(219)); draw(57, 7, char(219));
    draw(53, 10, char(219)); draw(54, 9, char(219)); draw(55, 8, char(219)); draw(57, 8, char(219)); draw(58, 8, char(219));
    draw(55, 9, char(219)); draw(58, 9, char(219)); draw(59, 9, char(219));
    draw(59, 10, char(219)); draw(60, 10, char(219));
    draw(60, 11, char(219));

    //LETRA U
    draw(62, 4, char(219)); draw(62, 5, char(219)); draw(62, 6, char(219)); draw(62, 7, char(219)); draw(62, 8, char(219));
    draw(63, 3, char(219)); draw(63, 4, char(219)); draw(63, 5, char(219)); draw(63, 6, char(219)); draw(63, 7, char(219)); draw(63, 8, char(219)); draw(63, 9, char(219));
    draw(64, 2, char(219)); draw(64, 3, char(219)); draw(64, 4, char(219)); draw(64, 5, char(219)); draw(64, 6, char(219)); draw(64, 7, char(219)); draw(64, 8, char(219)); draw(64, 9, char(219)); draw(64, 10, char(219)); draw(64, 11, char(219));
    draw(65, 11, char(219)); draw(66, 11, char(219)); draw(67, 11, char(219)); draw(68, 11, char(219));
    draw(69, 2, char(219)); draw(69, 3, char(219)); draw(69, 4, char(219)); draw(69, 5, char(219)); draw(69, 6, char(219)); draw(69, 7, char(219)); draw(69, 8, char(219)); draw(69, 9, char(219)); draw(69, 10, char(219)); draw(69, 11, char(219));
    draw(70, 3, char(219)); draw(70, 4, char(219)); draw(70, 5, char(219)); draw(70, 6, char(219)); draw(70, 7, char(219)); draw(70, 8, char(219)); draw(70, 9, char(219));
    draw(71, 4, char(219)); draw(71, 5, char(219)); draw(71, 6, char(219)); draw(71, 7, char(219)); draw(71, 8, char(219));

    //LETRA I
    draw(73, 4, char(219)); draw(73, 5, char(219)); draw(73, 6, char(219)); draw(73, 7, char(219)); draw(73, 8, char(219)); draw(73, 9, char(219)); draw(73, 10, char(219));
    draw(74, 3, char(219)); draw(74, 4, char(219)); draw(74, 5, char(219)); draw(74, 6, char(219)); draw(74, 7, char(219)); draw(74, 8, char(219)); draw(74, 9, char(219));
    draw(75, 2, char(219)); draw(75, 3, char(219)); draw(75, 4, char(219)); draw(75, 5, char(219)); draw(75, 6, char(219)); draw(75, 7, char(219)); draw(75, 8, char(219));
    draw(76, 4, char(219)); draw(76, 5, char(219)); draw(76, 6, char(219));

    //LETRA O
    draw(81, 2, char(219)); draw(82, 2, char(219)); draw(83, 2, char(219)); draw(84, 2, char(219));
    draw(78, 4, char(219)); draw(78, 5, char(219)); draw(78, 6, char(219)); draw(78, 7, char(219)); draw(78, 8, char(219));
    draw(79, 3, char(219)); draw(79, 4, char(219)); draw(79, 5, char(219)); draw(79, 6, char(219)); draw(79, 7, char(219)); draw(79, 8, char(219)); draw(79, 9, char(219));
    draw(80, 2, char(219)); draw(80, 3, char(219)); draw(80, 4, char(219)); draw(80, 5, char(219)); draw(80, 6, char(219)); draw(80, 7, char(219)); draw(80, 8, char(219)); draw(80, 9, char(219)); draw(80, 10, char(219)); draw(80, 11, char(219));
    draw(81, 11, char(219)); draw(82, 11, char(219)); draw(83, 11, char(219)); draw(84, 11, char(219));
    draw(85, 2, char(219)); draw(85, 3, char(219)); draw(85, 4, char(219)); draw(85, 5, char(219)); draw(85, 6, char(219)); draw(85, 7, char(219)); draw(85, 8, char(219)); draw(85, 9, char(219)); draw(85, 10, char(219)); draw(85, 11, char(219));
    draw(86, 3, char(219)); draw(86, 4, char(219)); draw(86, 5, char(219)); draw(86, 6, char(219)); draw(86, 7, char(219)); draw(86, 8, char(219)); draw(86, 9, char(219));
    draw(87, 4, char(219)); draw(87, 5, char(219)); draw(87, 6, char(219)); draw(87, 7, char(219)); draw(87, 8, char(219));

    //LETRA R
    draw(89, 6, char(254)); draw(90, 6, char(219)); draw(91, 6, char(219)); draw(92, 6, char(219)); draw(93, 6, char(219)); draw(94, 6, char(219)); draw(95, 6, char(219)); draw(96, 6, char(219)); draw(97, 6, char(219)); draw(98, 6, char(219)); draw(99, 6, char(219)); draw(100, 6, char(219));
    draw(89, 8, char(254)); draw(90, 8, char(219)); draw(91, 8, char(219)); draw(92, 8, char(219)); draw(93, 8, char(219)); draw(94, 8, char(219)); draw(95, 8, char(219)); draw(96, 8, char(219)); draw(97, 8, char(219)); draw(98, 8, char(219)); draw(99, 8, char(219)); draw(100, 8, char(219));
    draw(91, 3, char(219)); draw(92, 3, char(219)); draw(93, 2, char(219)); draw(94, 2, char(219)); draw(95, 2, char(219)); draw(96, 2, char(219)); draw(97, 2, char(219)); draw(98, 2, char(219)); draw(99, 2, char(219));
    draw(91, 4, char(219)); draw(92, 4, char(219)); draw(93, 3, char(219)); draw(98, 3, char(219)); draw(99, 3, char(219)); draw(100, 3, char(219));
    draw(91, 5, char(219)); draw(92, 5, char(219)); draw(93, 4, char(219)); draw(98, 4, char(219)); draw(99, 4, char(219)); draw(100, 4, char(219));
    draw(91, 6, char(219)); draw(92, 6, char(219)); draw(93, 5, char(219)); draw(98, 5, char(219)); draw(99, 5, char(219)); draw(100, 5, char(219));
    draw(91, 7, char(219)); draw(92, 7, char(219)); draw(93, 6, char(219)); draw(98, 6, char(219)); draw(9, 6, char(219)); draw(100, 6, char(219));
    draw(91, 8, char(219)); draw(92, 8, char(219)); draw(93, 7, char(219));
    draw(91, 9, char(219)); draw(92, 9, char(219)); draw(93, 8, char(219)); draw(98, 8, char(219)); draw(99, 8, char(219)); draw(100, 8, char(219));
    draw(91, 10, char(219)); draw(92, 10, char(219)); draw(93, 9, char(219)); draw(98, 9, char(219)); draw(99, 9, char(219)); draw(100, 9, char(219));
    draw(91, 11, char(219)); draw(92, 11, char(219)); draw(93, 10, char(219)); draw(98, 10, char(219)); draw(99, 10, char(219)); draw(100, 10, char(219));
    draw(93, 11, char(219)); draw(98, 11, char(219)); draw(99, 11, char(219)); draw(100, 11, char(219));

    //Comandos(?)
    draw(45, 15, "New Game");
    draw(45, 16, "Continue");
    draw(45, 17, "Credits");
    draw(45, 18, "Exit");

    //Cursor
    draw(43, 15 + cursorPos, char(175));
}

void Game::drawMap(int numMap) {

    switch (numMap) {
    case 0:
        //Pasto
        for (int i = 0; i < 80; i++) {
            for (int j = 0; j < 20; j++) {
                draw(5 + i, 2 + j, char(176));
            }
        }
        //Copa de árbol
        for (int i = 0; i < 80; i = i + 3) {
            draw(6 + i, 2, '^');
            draw(6 + i, 7, '^');
            draw(6 + i, 13, '^');
            draw(6 + i, 18, '^');
        }
        //Tronco
        for (int i = 0; i < 80; i = i + 3) {
            draw(6 + i, 5, char(186));
            draw(6 + i, 10, char(186));
            draw(6 + i, 16, char(186));
            draw(6 + i, 21, char(186));
        }
        //Hoja Izquierda
        for (int i = 0; i < 80; i = i + 3) {
            draw(5 + i, 3, char(47));
            draw(5 + i, 4, char(47));
            draw(5 + i, 8, char(47));
            draw(5 + i, 9, char(47));
            draw(5 + i, 14, char(47));
            draw(5 + i, 15, char(47));
            draw(5 + i, 19, char(47));
            draw(5 + i, 20, char(47));
        }
        //Hoja Derecha
        for (int i = 0; i < 78; i = i + 3) {
            draw(7 + i, 3, char(92));
            draw(7 + i, 4, char(92));
            draw(7 + i, 8, char(92));
            draw(7 + i, 9, char(92));
            draw(7 + i, 14, char(92));
            draw(7 + i, 15, char(92));
            draw(7 + i, 19, char(92));
            draw(7 + i, 20, char(92));
        }
        //Centro del Arbol
        for (int i = 0; i < 80; i = i + 3) {
            draw(6 + i, 3, char(32));
            draw(6 + i, 4, char(32));
            draw(6 + i, 8, char(32));
            draw(6 + i, 9, char(32));
            draw(6 + i, 14, char(32));
            draw(6 + i, 15, char(32));
            draw(6 + i, 19, char(32));
            draw(6 + i, 20, char(32));
        }
        //Camino
        for (int i = 0; i < 80; i++) {
            draw(5 + i, 11, char(32));
            draw(5 + i, 12, char(32));
        }
        for (int i = 0; i < 20; i++) {
            draw(20, 2 + i, char(32));
            draw(21, 2 + i, char(32));
            draw(22, 2 + i, char(32));
        }
    }
}

void Game::drawUI() {
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
    draw(90, 3, "HP:");
    draw(90, 4, "ATK:");
    draw(90, 5, "DEF:");
    draw(95, 3, "100");
    draw(95, 4, "30");
    draw(95, 5, "20");
    //Cuadrante del "inventory"
    draw(89, 8, "_INVENTORY_________________");
    for (int i = 0; i < 12; i++) {
        draw(88, 9 + i, '|');
        draw(116, 9 + i, '|');
    }
    draw(88, 21, "|___________________________|");
    draw(90, 10, "1 potion");
}
