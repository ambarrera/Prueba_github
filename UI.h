#pragma once
#include <string>

class UI
{
public:
	UI(int dialogueX, int dialogueY);
	void displayDialogue(char** screen, std::string line);
	void draw(char** screen);

private:
	int dialogueX, dialogueY;
	void drawOnScreen(char** screen, int x, int y, char symbol);
	void drawOnScreen(char** screen, int x, int y, char* line);
	void drawOnScreen(char** screen, int x, int y, int num);
};
