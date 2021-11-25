#include "Player.h"
#include <Windows.h>

Player::Player(int x, int y, char symbol):
	Creature(x, y, symbol)
{
	lastPosX = x;
	lastPosY = y;
}

void Player::handleInput(bool isAbleToInteract) {
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
	else if (isAbleToInteract && GetAsyncKeyState(VK_SPACE) & 0x8000) {
		setCoordinates(40, 9);
	}
}

void Player::update(bool isAbleToInteract) {
	lastPosX = x;
	lastPosY = y;
	handleInput(isAbleToInteract);
}

void Player::draw(char** screen, int cornerX, int cornerY) {
	if (screen[y + cornerY][x + cornerX] != char(32) && screen[y + cornerY][x + cornerX] != char(179)) {
		x = lastPosX;
		y = lastPosY;
	}
	screen[y + cornerY][x + cornerX] = symbol;
}