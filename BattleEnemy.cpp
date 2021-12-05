#include "BattleEnemy.h"

BattleEnemy::BattleEnemy(int typeOfObject, int battleX, int battleY, int hp, int atk, int def):
	BattleObject(typeOfObject, battleX, battleY, hp, atk, def, 13)
{
	setUpChars();
}

void BattleEnemy::setUpChars() {
	char newChars2[13] = { 200, 233, 188, '/', '|', ' ', '|', '\\', '|', '_', '|', 217, 192 };

	int newCoordY2[13] = { -3, -3, -3, -2, -2, -2, -2, -2, -1, -1, -1, 0, 0 };
	int newCoordX2[13] = { -1, 0, 1, -2, -1, 0, 1, 2, -1, 0, 1, -1, 1 };

	switch (typeOfObject)
	{
	case 2:
		numChars = 13;

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars2[i];
			charPos[i][0] = newCoordY2[i];
			charPos[i][1] = newCoordX2[i];
		}
		break;

	case 3:
		numChars = 13;

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars2[i];
			charPos[i][0] = newCoordY2[i];
			charPos[i][1] = newCoordX2[i];
		}
		break;

	case 4:
		numChars = 13;

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars2[i];
			charPos[i][0] = newCoordY2[i];
			charPos[i][1] = newCoordX2[i];
		}
		break;

	case 5:
		numChars = 13;

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars2[i];
			charPos[i][0] = newCoordY2[i];
			charPos[i][1] = newCoordX2[i];
		}
		break;

	case 6:
		numChars = 13;

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars2[i];
			charPos[i][0] = newCoordY2[i];
			charPos[i][1] = newCoordX2[i];
		}
		break;

	case 7:
		numChars = 13;

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars2[i];
			charPos[i][0] = newCoordY2[i];
			charPos[i][1] = newCoordX2[i];
		}
		break;

	default:
		typeOfObject = 0;
		numChars = 0;
		break;
	}
}