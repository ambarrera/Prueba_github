class Player{
public:

	//Variables
	int hp; 
	int def;
	int atk;
	int x;
	int y;	
	int exp;
	int square;

	Player() {
		hp = 100;
		def = 20;
		atk = 30;
		x = 20;
		y = 2;
		exp = 0;
		square = 0;
	}

	Player(int hp, int def, int atk, int x, int y, int exp, int square) {
		this -> hp = hp;
		this -> def = def;
		this -> atk = atk;
		this -> x = x;
		this -> y = y;
		this -> exp = exp;
		this -> square = square;
	}

};
