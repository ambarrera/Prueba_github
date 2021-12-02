#include "BattlePlayer.h"
#include <Windows.h>

BattlePlayer::BattlePlayer(int x, int y) :
	BattleObject(1, x, y, 100, 30, 20)
{
	lastAction = Action::NOTHING;
}

void BattlePlayer::handleInput() {
	if (GetAsyncKeyState('A') & 0x8000) {
		if (lastAction != Action::MV_LEFT) {
			move(Direction::LEFT);
			lastAction = Action::MV_LEFT;
		}
	}
	else if (GetAsyncKeyState('D') & 0x8000) {
		if (lastAction != Action::MV_RIGHT) {
			move(Direction::RIGHT);
			lastAction = Action::MV_RIGHT;
		}
	}
	else if (GetAsyncKeyState('W') & 0x8000) {
		if (lastAction != Action::MV_UP) {
			move(Direction::UP);
			lastAction = Action::MV_UP;
		}
	}
	else if (GetAsyncKeyState('S') & 0x8000) {
		if (lastAction != Action::MV_DOWN) {
			move(Direction::DOWN);
			lastAction = Action::MV_DOWN;
		}
	}
	else if (GetAsyncKeyState('J') & 0x8000) {
		if (lastAction != Action::PRESSED_J) {
			lastAction = Action::PRESSED_J;
		}
	}
	else if (GetAsyncKeyState('S') & 0x8000) {
		if (lastAction != Action::PRESSED_J) {
			lastAction = Action::PRESSED_J;
		}
	}
	else {
		lastAction = Action::NOTHING;
	}
}

void BattlePlayer::update() {
	lastBattleX = battleX;
	lastBattleY = battleY;
	handleInput();
}

void BattlePlayer::draw(int** battleBoard, int boardRows, int boardColumns) {
	battleBoard[lastBattleY][lastBattleX] = 0;
	if (battleY >= boardRows || battleX >= boardColumns || battleY < 0 || battleX < 0) {
		battleX = lastBattleX;
		battleY = lastBattleY;
	}
	battleBoard[battleY][battleX] = 1;
}