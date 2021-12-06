#pragma once

class BattleObject
{
public:
	BattleObject(int typeOfObject, int battleX, int battleY, int hp, int atk, int def, int numchars);
	~BattleObject();
	bool drawOnBoard(int** battleBoard, int boardRows, int boardColumns);
	void drawOnScreen(char** screen, int baseY, int baseX);
	void update();

	int typeOfObject;
	//Stats
	int hp, atk, def;
	//State
	bool isAttacking;
	//Coordinates
	int battleX;
	int battleY;

protected:
	enum class Direction {
		LEFT,
		RIGHT,
		UP,
		DOWN,
	};

	void move(Direction direction);

	int lastBattleX;
	int lastBattleY;

	//Drawing on the screen
	int numChars;
	int** charPos;
	char* chars;

	//Atack
	void attack();

	int lastFrame;

};
