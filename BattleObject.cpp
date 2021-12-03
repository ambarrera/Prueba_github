#include "BattleObject.h"

BattleObject::BattleObject(int typeOfObject, int battleX, int battleY, int hp, int atk, int def, int numChars) {
	this->typeOfObject = typeOfObject;
	this->battleX = battleX;
	this->battleY = battleY;
	lastBattleX = battleX;
	lastBattleY = battleY;
	this->hp = hp;
	this->atk = atk;
	this->def = def;

	this->numChars = numChars;
	charPos = new int* [numChars];
	for (int i = 0; i < numChars; i++) {
		charPos[i] = new int[2];
	}
	
	chars = new char[numChars];
}

BattleObject::~BattleObject() {
	for (int i = 0; i < numChars; i++) {
		delete[] charPos[i];
	}
	delete[] charPos;

	delete chars;
}

void BattleObject::move(Direction direction) {
	switch (direction) {
	case Direction::LEFT:
		battleX--;
		break;
	case Direction::RIGHT:
		battleX++;
		break;
	case Direction::UP:
		battleY--;
		break;
	case Direction::DOWN:
		battleY++;
		break;
	default:
		break;
	}
}

void BattleObject::update() {
	lastBattleX = battleX;
	lastBattleY = battleY;
	move(Direction::DOWN);
}

void BattleObject::drawOnBoard(int** battleBoard, int boardRows, int boardColumns) {
	battleBoard[lastBattleY][lastBattleX] = 0;
	if (battleY >= boardRows || battleX >= boardColumns || battleY < 0 || battleX < 0) {
		battleX = lastBattleX;
		battleY = lastBattleY;
	}
	battleBoard[battleY][battleX] = typeOfObject;
}

void BattleObject::drawOnScreen(char** screen, int baseY, int baseX) {
	for (int i = 0; i < numChars; i++) {
		screen[baseY + charPos[i][0]][baseX + charPos[i][1]] = chars[i];
	}
}