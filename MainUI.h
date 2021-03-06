#pragma once
#include "UI.h"
#include "Inventory.h"

class MainUI :
    public UI
{
public:
    MainUI(int dialogueX, int dialogueY);
    void draw(char** screen);
    void displayDialogue(char** screen, std::string line);
    void displayStats(char** screen, int hp, int atk, int def);

    Inventory inventory;

private:
    int dialogueX, dialogueY;
    
};
