#pragma once
#include "UI.h"

class Menu :
    public UI
{
public:
    Menu(int cursor, int numOptions);
    void draw(char** screen);
    int update();
    void changeCursorPos(int y);

private:
    int lastCursorPos;
    int cursorPos;
    int numOptions;
    
    bool handleInput();
};