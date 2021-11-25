#pragma once
#include <string>

class UI
{
public:
	UI();
	void draw(char** screen);

protected:
	void drawOnScreen(char** screen, int x, int y, char symbol);
	void drawOnScreen(char** screen, int x, int y, char* line);
	void drawOnScreen(char** screen, int x, int y, int num);
};
