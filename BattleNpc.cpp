#include "BattleNpc.h"

BattleNpc::BattleNpc(int typeOfObject, int battleX, int battleY, int hp, int atk, int def):
	BattleObject(typeOfObject, battleX, battleY, hp, atk, def, 45)
{
	setUpChars();
}

void BattleNpc::setUpChars() {

	char newChars8[23] = { '\\', '/', 219, 219, 219, '{', '}', 197, '|', ')', '(', 'o', 'o', '_', ']', '[', '_', '_', '_', '_', '"', '"', '"' };
	int newCoordY8[23] = { -2, -2, -2, -2, -2, -1, -1, -2, -3, -3, -3, -3, -3, -4, -4, -4, -4, -4, -2, -5, -1, 0, 0 };
	int newCoordX8[23] = { +2, -2, -1, 0, +1, -1, +1, +4, +4, +2, -2, +1, -1, 0, +1, -1, -2, +2, +3, 0, -3, -1, +1 };

	char newChars9[45] = { 248, 'w', 248, '_', '_', '\\', '/', '\\', '/', '"', '"', ':', '_', '(', '_', '_', ')', '_', ':', ':', ',', ',', 96, '"', '"', 238, ',', '"', '"', '"', 'U', 'U', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	int newCoordY9[45] = { -3, -3, -3, -5, -5, -5, -5, -5, -5, -4, -4, -3, -3, -2, -2, -3, -2, -2, -3, -2, -2, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -3, -3 };
	int newCoordX9[45] = { -4, -2, 0, 0, -1, -2, +2, +3, -3, -5, +5, +6, -7, -8, -7, +7, +8, +7, -6, -6, +6, +5, -5, +4, +3, -3, -1, +1, -1, 0, -2, +2, 0, +1, -1, +2, -2, +3, -3, +4, -4, +5, -5, -5, +5 };

	char newChars10[22] = { ')', '/', '_', '_', '_', '_', '\\', '(', 223, 238, 192, 238, 223, ')', '(', '\\', '/', '|', '|', '_', ',', ',' };
	int newCoordY10[22] = { -3, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, 1, 0, 0 };
	int newCoordX10[22] = { +4, +3, +2, +1, 0, -1, -2, -3, +2, +1, 0, -1, -2, +4, -3, +2, -2, -1, +1, 0, -1, +1 };

	char newChars11[21] = { '\\', '/', '<', 219, 219, 219, 220, 220, '}', '{', '@', '@', 153, ']', '[', '(', ')', '>', '_', '|', '|' };
	int newCoordY11[21] = { -2, -2, -1, -2, -2, -2, -1, -1, -3, -3, -3, -3, -4, -4, -4, -4, -4, -1, -5, 0, 0 };
	int newCoordX11[21] = { +2, -2, -3, -1, 0, +1, -1, +1, +2, -2, +1, -1, 0, +1, -1, -2, +2, +3, 0, -1, +1 };

	char newChars12[27] = { ',', ';', 206, '_', '_', '[', ']', 'o', 'o', 'O', 207, ')', '/', '/', 207, '(', ')', '(', ')', 220, ')', '(', 220, '|', '|', ' ', ' '};
	int newCoordY12[27] = { -4, -4, -4, -4, -4, -3, -3, -3, -3, -3, -2, -2, -2, -1, -1, -2, -2, -2, -2, -2, -1, -1, -1, 0, 0, -2, -2 };
	int newCoordX12[27] = { +5, +6, 0, -1, +1, -2, +2, -1, +1, +5, +5, +3, +4, +3, -4, -3, +3, -2, +2, 0, +1, -1, 0, -1, +1, -1, +1 };

	switch (typeOfObject)
	{
	case 8: //Solaire
		numChars = 23;

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars8[i];
			charPos[i][0] = newCoordY8[i];
			charPos[i][1] = newCoordX8[i];
		}
		break;
	case 9: //Zsiff
		numChars = 45;

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars9[i];
			charPos[i][0] = newCoordY9[i];
			charPos[i][1] = newCoordX9[i];
		}
		break;
	case 10: //Burak
		numChars = 22;

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars10[i];
			charPos[i][0] = newCoordY10[i];
			charPos[i][1] = newCoordX10[i];
		}
		break;
	case 11: //Khelang
		numChars = 21;

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars11[i];
			charPos[i][0] = newCoordY11[i];
			charPos[i][1] = newCoordX11[i];
		}
		break;
	case 12: //Ghorm
		numChars = 27;

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars12[i];
			charPos[i][0] = newCoordY12[i];
			charPos[i][1] = newCoordX12[i];
		}
		break;
	default:
		numChars = 0;
		typeOfObject = 0;
		break;
	}
}