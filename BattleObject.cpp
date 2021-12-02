#include "BattleObject.h"

BattleObject::BattleObject(int typeOfObject, int battleX, int battleY, int hp, int atk, int def) {
	this->typeOfObject = typeOfObject;
	this->battleX = battleX;
	this->battleY = battleY;
	lastBattleX = battleX;
	lastBattleY = battleY;
	this->hp = hp;
	this->atk = atk;
	this->def = def;
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

void BattleObject::draw(int** battleBoard, int boardRows, int boardColumns) {
	battleBoard[lastBattleY][lastBattleX] = 0;
	if (battleY >= boardRows || battleX >= boardColumns || battleY < 0 || battleX < 0) {
		battleX = lastBattleX;
		battleY = lastBattleY;
	}
	battleBoard[battleY][battleX] = typeOfObject;
}