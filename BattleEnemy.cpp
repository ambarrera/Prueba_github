#include "BattleEnemy.h"

BattleEnemy::BattleEnemy(int typeOfObject, int battleX, int battleY, int hp, int atk, int def):
	BattleObject(typeOfObject, battleX, battleY, hp, atk, def, 13)
{
	setUpChars();
}

void BattleEnemy::setUpChars() {
	switch (typeOfObject)
	{
	case 2:
		numChars = 13;

		char newChars[13] = { 200, 233, 188, '/', '|', ' ', '|', '\\', '|', '_', '|', 217, 192 };
		
		int newCoordY[13] = {-3, -3, -3, -2, -2, -2, -2, -2, -1, -1, -1, 0, 0};
		int newCoordX[13] = {-1, 0, 1, -2, -1, 0, 1, 2, -1, 0, 1, -1, 1};

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars[i];
			charPos[i][0] = newCoordY[i];
			charPos[i][1] = newCoordX[i];
		}
		break;
	}
}