#include "BattleEnemy.h"

BattleEnemy::BattleEnemy(int typeOfObject, int battleX, int battleY, int hp, int atk, int def):
	BattleObject(typeOfObject, battleX, battleY, hp, atk, def, 49)
{
	setUpChars();
}

void BattleEnemy::setUpChars() {
	char newChars2[13] = { 200, 233, 188, '/', '|', ' ', '|', '\\', '|', '_', '|', 217, 192 };

	int newCoordY2[13] = { -3, -3, -3, -2, -2, -2, -2, -2, -1, -1, -1, 0, 0 };
	int newCoordX2[13] = { -1, 0, 1, -2, -1, 0, 1, 2, -1, 0, 1, -1, 1 };

	char newChars3[14] = { '|', '=', '=', '|', '/', '/', '#','#', '\\', '\\', '#', '#', 217, 192 };

	int newCoordY3[14] = { -3, -3, -3, -3, -2, -2, -1, -1, -2, -2, -2, -2, 0, 0 };
	int newCoordX3[14] = { -1, 0, 1, +2, -1, -2, 0, +1, 0, +1, +2, +3, -1, 1 };

	char newChars4[17] = { '_', '|', '=', '=', '|', '_', '/', '|', '|', 178, 178, '|', '|','\\', 'W', ' ', 'W' };

	int newCoordY4[17] = { -3, -3, -3, -3, -3, -3, -2, -1, -1, -1, -2, -2, -2, -2, 0, 0, 0 };
	int newCoordX4[17] = { -2, -1, 0, +1, +2, +3, -3, -1, +2, 0, 0, -1, +2, +4, -1, 0, +2 };

	char newChars5[27] = { '\\', '\\', 226, '/', '/', '{', '-', '-', '<', '|', '|', '|', '|','|', '|', 177, 177, 177, 177, 177, 177, '\\', 217, 217, ' ', 217, 217 };

	int newCoordY5[27] = { -3, -3, -4, -3, -3, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0 };
	int newCoordX5[27] = { +1, 0, -2, -5, -4, -6, -7, -8, -9, -1, -2, -3, -1, -2, -3, +1, -1, -2, -3, 0, -1, +2, -2, -3, -1, 0, 1 };

	char newChars6[49] = { '<', ' ', '(', '\\', '\\', ' ', '.', '.', ' ', '/', '/', ')', ' ','>', '-', '-', '(', ')', ' ', '|', ' ', ' ', '|', ' ', '/', ' ', '|', ' ', ' ', '|', ' ', '\\','\\', ' ', ' ', '/', '|', '|', '\\', '\\', ' ', ' ', '/', '/', '(', ')', '_', ')' };

	int newCoordY6[49] = { -5, -6, -5, -4, -4, -4, -4, -4, -4, -4, -4, -5, -6, -5, -3, -3, -3, -3, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, +1, +1, +2, +2, +2, +2, +2, +2, +1, +1, 0, 0 };
	int newCoordX6[49] = { -2, -3, -4, -3, -2, 0, +1, +2, +3, +4, +5, +4, +3, -2, +3, -1, +2, -2, -1, 0, +1, +2, +3, -3, -2, -1, 0, +1, +2, +3, +4, -1, 0, +1, +2, +1, 0, 0, +1, +2, +3, +4, +5, +4, +6, +5, +6 };

	char newChars7[18] = { ')', '(', 'O', '/', '\\', '/', 15, 176, 176, 176, 176, 176, 176,'|', '|', 'L', 'L', 'L' };

	int newCoordY7[18] = { -4, -4, -3, -2, -2, -2, -2, -3, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0 };
	int newCoordX7[18] = { +1, -1, 0, -2, +2, +3, +4, +1, -1, 0, -1, 0, +1, -2, +2, -1, 0, +1 };

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
		numChars = 14;

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars3[i];
			charPos[i][0] = newCoordY3[i];
			charPos[i][1] = newCoordX3[i];
		}
		break;

	case 4:
		numChars = 17;

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars4[i];
			charPos[i][0] = newCoordY4[i];
			charPos[i][1] = newCoordX4[i];
		}
		break;

	case 5:
		numChars = 27;

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars5[i];
			charPos[i][0] = newCoordY5[i];
			charPos[i][1] = newCoordX5[i];
		}
		break;

	case 6:
		numChars = 49;

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars6[i];
			charPos[i][0] = newCoordY6[i];
			charPos[i][1] = newCoordX6[i];
		}
		break;

	case 7:
		numChars = 18;

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars7[i];
			charPos[i][0] = newCoordY7[i];
			charPos[i][1] = newCoordX7[i];
		}
		break;

	default:
		typeOfObject = 0;
		numChars = 0;
		break;
	}
}