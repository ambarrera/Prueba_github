#include "Menu.h"
#include <Windows.h>

Menu::Menu(int cursorPos, int numOptions)
{
	this->cursorPos = cursorPos;
	this->lastCursorPos = cursorPos;
	this->numOptions = numOptions;
}

void Menu::changeCursorPos(int y) {
	cursorPos += y;
}

int Menu::update() {
	lastCursorPos = cursorPos;
	if (handleInput()) {
		return lastCursorPos;
	}
	else {
		return -1;
	}
}

bool Menu::handleInput() {
	if (GetAsyncKeyState('W') & 0x8000) {
		if (cursorPos > 0) {
			cursorPos--;
		}
	}
	else if (GetAsyncKeyState('S') & 0x8000) {
		if (cursorPos < numOptions - 1) {
			cursorPos++;
		}
	}
	else if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		return true;
	}
	return false;
}