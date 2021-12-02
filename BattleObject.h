#pragma once

class BattleObject
{
public:
	BattleObject(int typeOfObject, int battleX, int battleY, int hp, int atk, int def);
	void draw(int** battleBoard, int boardRows, int boardColumns);
	void update();

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

	//Stats
	int hp, atk, def;
};
