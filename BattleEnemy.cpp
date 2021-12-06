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

	char newChars3[17] = { '|', '=', '=', '=', '|', '/', '/', '#','#', '#', '\\', '\\', '#', '#', '#', 217, 192 };

	int newCoordY3[17] = { -3, -3, -3, -3, -3, -2, -2, -1, -1, -1, -2, -2, -2, -2, -2, 0, 0 };
	int newCoordX3[17] = { -2, -1, 0, 1, +2, -2, -3, -1, 0, +1, +2, +3, -1, 0, +1, -1, +1 };

	char newChars4[19] = { '_', '|', '=', '=', '|', '_', '/', '|', '|', 178, 178, 178, 178, '|', '|','\\', 'W', ' ', 'W' };

	int newCoordY4[19] = { -3, -3, -3, -3, -3, -3, -2, -1, -1, -1, -2, -1, -2, -2, -2, -2, 0, 0, 0 };
	int newCoordX4[19] = { -2, -1, 0, +1, +2, +3, -3, -1, +2, 0, 0, +1, +1, -1, 2, 4, -1, 0, 2 };

	char newChars5[27] = { '\\', '\\', 226, '/', '/', '{', '-', '-', '<', '|', '|', '|', '|','|', '|', 177, 177, 177, 177, 177, 177, '\\', 217, 217, ' ', 217, 217 };

	int newCoordY5[27] = { -3, -3, -4, -3, -3, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0 };
	int newCoordX5[27] = { +1, 0, -2, -5, -4, -6, -7, -8, -9, -1, -2, -3, -1, -2, -3, +1, -1, -2, -3, 0, -1, +2, -2, -3, -1, 0, 1 };

	char newChars6[16] = { ';', ';', '_', '_', '_', '(', ')', 'O', 'O', ';', '\\', '(', '(', '_', '"', '"', };

	int newCoordY6[16] = { -3, -3, -3, -3, -3, -2, -2, -2, -2, -2, -1, -1, -1, -1, 0, 0 };
	int newCoordX6[16] = { 2, -2, 1, 0, -1, -2, +2, -1, +1, 0, +2, +1, -1, 0, 0, +1 };

	char newChars7[18] = { ')', '(', 'O', '/', '\\', '\\', 15, 176, 176, 176, 176, 176, 176,'|', '|', 217, 217, 217 };

	int newCoordY7[18] = { -4, -4, -3, -2, -2, -2, -3, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0 };
	int newCoordX7[18] = { +1, -1, 0, -2, +2, -3, -4, 0, +1, -1, 0, -1, +1, +2, -2, +1, -1, 0 };

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
		numChars = 17;

		for (int i = 0; i < numChars; i++) {
			chars[i] = newChars3[i];
			charPos[i][0] = newCoordY3[i];
			charPos[i][1] = newCoordX3[i];
		}
		break;

	case 4:
		numChars = 19;

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
		numChars = 16;

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

void BattleEnemy::update(int currentFrame) {
	lastBattleX = battleX;
	lastBattleY = battleY;
	switch (typeOfObject)
	{
	case 2:
		//nada
		break;
	case 3:
		if (currentFrame % 10 == 0) {
			move(Direction::LEFT);
		}
		else if (currentFrame % 5 == 0) {
			move(Direction::RIGHT);
		}
		break;
	case 4:
		if (currentFrame % 40 == 0) {
			move(Direction::LEFT);
		}
		else if (currentFrame % 20 == 0) {
			move(Direction::DOWN);
		}
		else if (currentFrame % 10 == 0) {
			move(Direction::UP);
		}
		else if (currentFrame % 15 == 0) {
			move(Direction::UP);
		}
		else if (currentFrame % 5 == 0) {
			move(Direction::DOWN);
		}
		break;
	case 5:
		if (currentFrame % 40 == 0) {
			move(Direction::DOWN);
		}
		else if (currentFrame % 20 == 0) {
			move(Direction::UP);
		}
		else if (currentFrame % 10 == 0) {
			move(Direction::UP);
		}
		else if (currentFrame % 5 == 0) {
			move(Direction::DOWN);
		}
		else if (currentFrame % 9) {
			attack();
		}
		break;
	case 6:
		if (currentFrame % 40 == 0) {
			move(Direction::LEFT);
		}
		break;
	case 7:
		if (currentFrame % 80 == 0) {
			move(Direction::DOWN);
		}
		else if (currentFrame % 40 == 0) {
			move(Direction::UP);
		}
		else if (currentFrame % 10 == 0) {
			move(Direction::UP);
		}
		else if (currentFrame % 10 == 0) {
			move(Direction::DOWN);
		}
		else if (currentFrame % 5) {
			attack();
		}
		if (isAttacking) {
			chars[5] = 196;
			charPos[6][0] = -2;
			lastFrame = currentFrame;
		}
		if (currentFrame == lastFrame + 5); {
			chars[5] = '\\';
			charPos[6][0] = -3;
		}
		break;
	default:
		break;
	}
}