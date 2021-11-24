#include "Player.h"
#include <Windows.h>

Player::Player(int x, int y, char symbol):
	Creature(x, y, symbol) {}

void Player::handleInput() {
	if (GetAsyncKeyState('A') & 0x8000) {
		move(Direction::LEFT);
	}
	else if (GetAsyncKeyState('D') & 0x8000) {
		move(Direction::RIGHT);
	}
	else if (GetAsyncKeyState('W') & 0x8000) {
		move(Direction::UP);
	}
	else if (GetAsyncKeyState('S') & 0x8000) {
		move(Direction::DOWN);
	}
}