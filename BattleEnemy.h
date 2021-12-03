#pragma once
#include "BattleObject.h"

class BattleEnemy :
    public BattleObject
{
public:
    BattleEnemy(int typeOfObject, int battleX, int battleY, int hp, int atk, int def);

private:
    void setUpChars();
};
