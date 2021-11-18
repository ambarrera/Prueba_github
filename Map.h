class Map{
public:

	//Variables
	int numMap;
    char* screen;
    int width;
    int height;

	Map(char *theScreen, int width, int height) {
		numMap = 0;
        screen = theScreen;
        this->width = width;
        this->height = height;
	}

    void draw(int x, int y, char mychar) {
        screen[y * width + x] = mychar;
    }

	void drawMap(char* screen) {
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
            break;

        case 1:
            //Pasto
            for (int i = 0; i < 80; i++) {
                for (int j = 0; j < 20; j++) {
                    draw(5 + i, 2 + j, char(176));
                }
            }
            //Copa de árbol
            for (int i = 0; i < 80; i = i + 3) {
                draw(5 + i, 2, '^');
                draw(5 + i, 6, '^');
                draw(5 + i, 10, '^');
                draw(5 + i, 14, '^');
                draw(5 + i, 18, '^');
            }
            //Tronco
            for (int i = 0; i < 80; i = i + 3) {
                draw(5 + i, 5, char(186));
                draw(5 + i, 9, char(186));
                draw(5 + i, 13, char(186));
                draw(5 + i, 17, char(186));
                draw(5 + i, 21, char(186));
            }
            //Hoja Izquierda
            for (int i = 0; i < 78; i = i + 3) {
                draw(7 + i, 3, char(47));
                draw(7 + i, 4, char(47));
                draw(7 + i, 7, char(47));
                draw(7 + i, 8, char(47));
                draw(7 + i, 11, char(47));
                draw(7 + i, 12, char(47));
                draw(7 + i, 15, char(47));
                draw(7 + i, 16, char(47));
                draw(7 + i, 19, char(47));
                draw(7 + i, 20, char(47));
            }
            //Hoja Derecha
            for (int i = 0; i < 80; i = i + 3) {
                draw(6 + i, 3, char(92));
                draw(6 + i, 4, char(92));
                draw(6 + i, 7, char(92));
                draw(6 + i, 8, char(92));
                draw(6 + i, 11, char(92));
                draw(6 + i, 12, char(92));
                draw(6 + i, 15, char(92));
                draw(6 + i, 16, char(92));
                draw(6 + i, 19, char(92));
                draw(6 + i, 20, char(92));
            }
            //Centro del Árbol
            for (int i = 0; i < 80; i = i + 3) {
                draw(5 + i, 3, char(32));
                draw(5 + i, 4, char(32));
                draw(5 + i, 7, char(32));
                draw(5 + i, 8, char(32));
                draw(5 + i, 11, char(32));
                draw(5 + i, 12, char(32));
                draw(5 + i, 15, char(32));
                draw(5 + i, 16, char(32));
                draw(5 + i, 19, char(32));
                draw(5 + i, 20, char(32));
            }
            //CEMENTERIO
            //Pasto
            for (int i = 0; i < 12; i++) {
                for (int j = 0; j < 6; j++) {
                    draw(7 + i, 6 + j, char(176));
                }
            }
            for (int i = 0; i < 17; i++) {
                draw(15 + i, 10, char(176));
                draw(15 + i, 11, char(176));
            }
            //Tumbas
            draw(9, 6, char(206));
            draw(16, 6, char(206));
            draw(9, 9, char(206));
            draw(16, 9, char(206));
            draw(9, 7, char(178));
            draw(16, 7, char(178));
            draw(9, 10, char(178));
            draw(16, 10, char(178));

            //PUEBLO
            //Pasto
            for (int i = 0; i < 57; i++) {
                for (int j = 0; j < 6; j++) {
                    draw(25 + i, 6 + j, char(176));
                }
            }
            //Casas
            //Tejas
            for (int i = 0; i < 6; i++) {
                draw(53 + i, 6, char(92));
                draw(47 + i, 6, char(47));

                draw(62 + i, 9, char(92));
                draw(73 + i, 8, char(92));

                draw(38 + i, 9, char(47));
                draw(28 + i, 8, char(47));
            }
            draw(34, 8, char(92));
            draw(44, 9, char(92));
            draw(72, 8, char(47));
            draw(61, 9, char(47));
            //Muros
            for (int i = 0; i < 6; i++) {
                draw(47 + i, 7, char(124));
                draw(53 + i, 7, char(124));
                draw(47 + i, 8, char(124));
                draw(53 + i, 8, char(124));
            }
            for (int i = 0; i < 7; i++) {
                draw(28 + i, 9, char(124));
                draw(38 + i, 10, char(124));
                draw(61 + i, 10, char(124));
                draw(72 + i, 9, char(124));
            }
            //Pisos
            for (int i = 0; i < 4; i++) {
                draw(48 + i, 7, char(95));
                draw(54 + i, 7, char(95));
                draw(48 + i, 8, char(95));
                draw(54 + i, 8, char(95));
            }
            for (int i = 0; i < 4; i++) {
                draw(29 + i, 9, char(95));
                draw(39 + i, 10, char(95));
                draw(63 + i, 10, char(95));
                draw(74 + i, 9, char(95));
            }

            //LAGO
            //Pasto
            for (int i = 0; i < 27; i++) {
                for (int j = 0; j < 8; j++) {
                    draw(40 + i, 14 + j, char(176));
                }
            }
            //Agua
            for (int i = 0; i < 22; i++) {
                draw(42 + i, 15, char(126));
                draw(42 + i, 20, char(126));
            }
            for (int i = 0; i < 24; i++) {
                draw(41 + i, 16, char(126));
                draw(41 + i, 19, char(126));
            }
            for (int i = 0; i < 26; i++) {
                draw(40 + i, 17, char(126));
                draw(40 + i, 18, char(126));
            }


            //Camino
            for (int i = 0; i < 75; i++) {
                draw(7 + i, 12, char(32));
                draw(7 + i, 13, char(32));
            }
            for (int i = 0; i < 20; i++) {
                draw(22, 2 + i, char(32));
                draw(23, 2 + i, char(32));
                draw(24, 2 + i, char(32));
            }
            for (int i = 0; i < 8; i++) {
                draw(12, 6 + i, char(32));
                draw(13, 6 + i, char(32));
            }
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 11; j++) {
                    draw(52 + i, 9 + j, char(32));
                }
            }
            draw(33, 10, char(32)); draw(34, 10, char(32)); draw(33, 11, char(32)); draw(34, 11, char(32));
            draw(72, 10, char(32)); draw(73, 10, char(32)); draw(72, 11, char(32)); draw(73, 11, char(32));
            draw(43, 11, char(32)); draw(44, 11, char(32));
            draw(61, 11, char(32)); draw(62, 11, char(32));

            for (int i = 0; i < 18; i++) {
                draw(44 + i, 17, char(32));
            }
            break;

        case 2:
            //Pasto
            for (int i = 0; i < 80; i++) {
                for (int j = 0; j < 20; j++) {
                    draw(5 + i, 2 + j, char(176));
                }
            }
            //Copa de árbol
            for (int i = 0; i < 80; i = i + 3) {
                draw(6 + i, 2, '^');
                draw(6 + i, 6, '^');
                draw(6 + i, 14, '^');
                draw(6 + i, 18, '^');
            }
            //Tronco
            for (int i = 0; i < 80; i = i + 3) {
                draw(6 + i, 5, char(186));
                draw(6 + i, 9, char(186));
                draw(6 + i, 17, char(186));
                draw(6 + i, 21, char(186));
            }
            //Hoja Izquierda
            for (int i = 0; i < 80; i = i + 3) {
                draw(5 + i, 3, char(47));
                draw(5 + i, 4, char(47));
                draw(5 + i, 7, char(47));
                draw(5 + i, 8, char(47));
                draw(5 + i, 15, char(47));
                draw(5 + i, 16, char(47));
                draw(5 + i, 19, char(47));
                draw(5 + i, 20, char(47));
            }
            //Hoja Derecha
            for (int i = 0; i < 78; i = i + 3) {
                draw(7 + i, 3, char(92));
                draw(7 + i, 4, char(92));
                draw(7 + i, 7, char(92));
                draw(7 + i, 8, char(92));
                draw(7 + i, 15, char(92));
                draw(7 + i, 16, char(92));
                draw(7 + i, 19, char(92));
                draw(7 + i, 20, char(92));
            }
            //Centro del Árbol
            for (int i = 0; i < 80; i = i + 3) {
                draw(6 + i, 3, char(32));
                draw(6 + i, 4, char(32));
                draw(6 + i, 7, char(32));
                draw(6 + i, 8, char(32));
                draw(6 + i, 15, char(32));
                draw(6 + i, 16, char(32));
                draw(6 + i, 19, char(32));
                draw(6 + i, 20, char(32));
            }
            //CASA
            //Pasto
            for (int i = 0; i < 12; i++) {
                for (int j = 0; j < 4; j++) {
                    draw(29 + i, 6 + j, char(176));
                }
            }
            //Tejas
            for (int i = 0; i < 7; i++) {
                draw(30 + i, 7, char(47));
            }
            draw(37, 7, char(92));
            //Muros
            for (int i = 0; i < 8; i++) {
                draw(30 + i, 8, char(124));
            }
            //Pisos
            for (int i = 0; i < 5; i++) {
                draw(31 + i, 8, char(95));
            }

            //Vacio
            for (int i = 0; i < 15; i++) {
                for (int j = 0; j < 20; j++) {
                    draw(41 + i, 2 + j, char(176));
                }
            }
            for (int i = 0; i < 11; i++) {
                for (int j = 0; j < 20; j++) {
                    draw(43 + i, 2 + j, char(32));
                }
            }
            for (int i = 0; i < 15; i++) {
                draw(41 + i, 2, char(32));
                draw(41 + i, 10, char(32));
                draw(41 + i, 13, char(32));
                draw(41 + i, 21, char(32));
            }
            for (int i = 0; i < 13; i++) {
                draw(42 + i, 3, char(32));
                draw(42 + i, 9, char(32));
                draw(42 + i, 14, char(32));
                draw(42 + i, 20, char(32));
            }


            //Camino
            for (int i = 0; i < 75; i++) {
                draw(8 + i, 11, char(32));
                draw(8 + i, 12, char(32));
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 9; j++) {
                    draw(20 + i, 13 + j, char(32));
                }
            }

            draw(36, 9, char(32)); draw(36, 10, char(32)); draw(37, 9, char(32)); draw(37, 10, char(32));

            //Puente
            for (int i = 0; i < 17; i++) {
                draw(40 + i, 11, char(186));
                draw(40 + i, 12, char(186));
                draw(40 + i, 10, char(205));
                draw(40 + i, 13, char(205));
            }


        }

	}
};