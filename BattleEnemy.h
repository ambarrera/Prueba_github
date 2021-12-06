#pragma once
#include "BattleObject.h"

class BattleEnemy :
    public BattleObject
{
public:
    BattleEnemy(int typeOfObject, int battleX, int battleY, int hp, int atk, int def);
    void update(int currentFrame);

private:
    void setUpChars();
};
