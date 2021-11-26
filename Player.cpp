#include "Player.h"
#include <Windows.h>

Player::Player(int x, int y, char symbol):
	Creature(x, y, symbol)
{
	lastPosX = x;
	lastPosY = y;
	lastPressedEnter = false;
}

bool Player::handleInput() {
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		if (!lastPressedEnter) {
			lastPressedEnter = true;
			return true;
		}
	}
	else if (!isInteracting) {
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
		lastPressedEnter = false;
	}
	else {
		lastPressedEnter = false;
	}
	return false;
}

void Player::update(int numInteractions) {
	lastPosX = x;
	lastPosY = y;
	bool pressedEnter = handleInput();
	if (!isInteracting) {
		if (numInteractions && pressedEnter) {
			isInteracting = numInteractions;
		}
	}
	else if (pressedEnter) {
		isInteracting--;
	}
}

void Player::draw(char** screen, int cornerX, int cornerY) {
	if (screen[y + cornerY][x + cornerX] != char(32) && screen[y + cornerY][x + cornerX] != char(179)) {
		x = lastPosX;
		y = lastPosY;
	}
	screen[y + cornerY][x + cornerX] = symbol;
}