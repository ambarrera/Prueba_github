#pragma once
#include "UI.h"

class Menu :
    public UI
{
public:
    Menu(int cursor, int numOptions);
    int update();
    void changeCursorPos(int y);

protected:
    int lastCursorPos;
    int cursorPos;
    int numOptions;
    
    bool handleInput();
};