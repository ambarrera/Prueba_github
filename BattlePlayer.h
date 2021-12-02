#pragma once
#include "BattleObject.h"

class BattlePlayer :
    public BattleObject
{
public:
    BattlePlayer(int x, int y);
	void draw(int** battleBoard, int boardRows, int boardColumns);
	void update();

private:
	enum class Action {
		MV_LEFT,
		MV_RIGHT,
		MV_UP,
		MV_DOWN,
		PRESSED_J,
		PRESSED_K,
		NOTHING,
	};

	Action lastAction;
    void handleInput();

};
