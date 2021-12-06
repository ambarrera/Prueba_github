#pragma once

class BattleObject
{
public:
	BattleObject(int typeOfObject, int battleX, int battleY, int hp, int atk, int def, int numchars);
	~BattleObject();
	void drawOnBoard(int** battleBoard, int boardRows, int boardColumns);
	void drawOnScreen(char** screen, int baseY, int baseX);
	void update();

	//Stats
	int hp, atk, def;

protected:
	enum class Direction {
		LEFT,
		RIGHT,
		UP,
		DOWN,
	};

	void move(Direction direction);

	int typeOfObject;
	int battleX;
	int battleY;
	int lastBattleX;
	int lastBattleY;

	//Drawing on the screen
	int numChars;
	int** charPos;
	char* chars;

};
