#pragma once
#include "BattleObject.h"

class BattleNpc :
    public BattleObject
{
public:
    BattleNpc(int typeOfObject, int battleX, int battleY, int hp, int atk, int def);

private:
    void setUpChars();
};
