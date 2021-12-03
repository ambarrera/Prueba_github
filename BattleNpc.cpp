#include "BattleNpc.h"

BattleNpc::BattleNpc(int typeOfObject, int battleX, int battleY, int hp, int atk, int def):
	BattleObject(typeOfObject, battleX, battleY, hp, atk, def, 23)
{
	setUpChars();
}

void BattleNpc::setUpChars() {

	char newChars3[23] = { '\\', '/', 219, 219, 219, '{', '}', 197, '|', ')', '(', 'o', 'o', '_', ']', '[', '_', '_', '_', '_', '"', '"', '"' };
	int newCoordY3[23] = { -2, -2, -2, -2, -2, -1, -1, -2, -3, -3, -3, -3, -3, -4, -4, -4, -4, -4, -2, -5, -1, 0, 0 };
	int newCoordX3[23] = { +2, -2, -1, 0, +1, -1, +1, +4, +4, +2, -2, +1, -1, 0, +1, -1, -2, +2, +3, 0, -3, -1, +1 };

	char newChars4[21] = { '\\', '/', '<', '219', '219', '219', '220', '220', '}', '{', '@', '@', '153', ']', '[', '(', ')', '>', '_', '|', '|' };
	int newCoordY4[21] = { -2, -2, -1, -2, -2, -2, -1, -1, -3, -3, -3, -3, -4, -4, -4, -4, -4, -1, -5, 0, 0 };
	int newCoordX4[21] = { +2, -2, -3, -1, 0, +1, -1, +1, +2, -2, +1, -1, 0, +1, -1, -2, +2, +3, 0, -1, +1 };

	char newChars5[22] = { ')', '/', '_', '_', '_', '_', '\\', '(', '223', '238', '192', '238', '223', ')', '(', '\\', '/', '|', '|', '_', ',', ',' };
	int newCoordY5[22] = { -3, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, 1, 0, 0 };
	int newCoordX5[22] = { +4, +3, +2, +1, 0, -1, -2, -3, +2, +1, 0, -1, -2, +4, -3, +2, -2, -1, +1, 0, -1, +1 };

	switch (typeOfObject)
	{
	case 3: //Solaire
		numChars = 23;

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars3[i];
			charPos[i][0] = newCoordY3[i];
			charPos[i][1] = newCoordX3[i];
		}
		break;
	case 4: //Khelang
		numChars = 21;

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars4[i];
			charPos[i][0] = newCoordY4[i];
			charPos[i][1] = newCoordX4[i];
		}
		break;
	case 5: //Burak
		numChars = 22;

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars5[i];
			charPos[i][0] = newCoordY5[i];
			charPos[i][1] = newCoordX5[i];
		}
		break;
	}
}