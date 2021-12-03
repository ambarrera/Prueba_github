#include "BattlePlayer.h"
#include <Windows.h>

BattlePlayer::BattlePlayer(int x, int y) :
	BattleObject(1, x, y, 100, 30, 20, 8)
{
	lastAction = Action::NOTHING;

	char newChars[8] = { '|', 'o', 197, '/', '|', '\\', '/', '\\'};

	int newCoordY[8] = { -2, -2, -1, -1, -1, -1, 0, 0 };
	int newCoordX[8] = { -2, 0, -2, -1, 0, 1, -1, 1 };

	for (int i = 0; i < numChars; i++) {
		chars[i] = newChars[i];
		charPos[i][0] = newCoordY[i];
		charPos[i][1] = newCoordX[i];
	}
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
			attack();
			lastAction = Action::PRESSED_J;
		}
	}
	else if (GetAsyncKeyState('K') & 0x8000) {
		if (lastAction != Action::PRESSED_K) {
			lastAction = Action::PRESSED_K;
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
	if (lastAction == Action::PRESSED_J) {
		chars[0] = '.';
		chars[2] = char(196);
		chars[3] = char(196);
		chars[4] = '\\';
		chars[5] = char(197);
		charPos[0][1] = 1;
		charPos[2][1] = 2;
		charPos[3][1] = 3;
	}
}

void BattlePlayer::drawOnBoard(int** battleBoard, int boardRows, int boardColumns) {
	battleBoard[lastBattleY][lastBattleX] = 0;
	if (battleY >= boardRows || battleX >= boardColumns || battleY < 0 || battleX < 0) {
		battleX = lastBattleX;
		battleY = lastBattleY;
	}
	if (battleBoard[battleY][battleX] == 2) {
		battleX = lastBattleX;
		battleY = lastBattleY;
	}
	battleBoard[battleY][battleX] = 1;
}

void BattlePlayer::attack() {

}