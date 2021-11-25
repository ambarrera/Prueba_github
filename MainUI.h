#pragma once
#include "UI.h"

class MainUI :
    public UI
{
public:
    MainUI(int dialogueX, int dialogueY);
    void draw(char** screen);
    void displayDialogue(char** screen, std::string line);

private:
    int dialogueX, dialogueY;

};
