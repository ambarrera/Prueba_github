#pragma once
#include "Menu.h"
class MainMenu :
    public Menu
{
public:
    MainMenu();

    void draw(char** screen);
};
