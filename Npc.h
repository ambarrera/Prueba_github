class Npc{
public:

	//Variables
	int x;
	int y;
	char name[8];
	char character;

	//Constructor
	Npc() {
		x = 0;
		y = 0;
		for (int i = 0; i < 7; i++) {
			name[i] = ' ';
		}
		name[7] = '\0';
		character = 'Q';
	}

	//Funciones
	void setNameTo(char* name) {
		for (int i = 0; i < 7; i++) {
			if (name[i] != '\0') {
				this->name[i] = name[i];
			}
		}		
	}

	void setCharacterTo(char character) {
		this->character = character;
	}

	void setCoordinates(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

