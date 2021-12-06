#include "BattleBoard.h"

BattleBoard::BattleBoard(int boardRows, int boardColumns, int objectType) :
	enemy(objectType, 5, 1, 50, 25, 10), player(2, 1), npc(objectType, 3, 1, 50, 20, 10)
{
	frames = 0;
	rows = boardRows;
	columns = boardColumns;
	board = new int* [rows];
	for (int i = 0; i < rows; i++) {
		board[i] = new int[columns];
	}
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < columns; x++) {
			board[y][x] = 0;
		}
	}

}

BattleBoard::~BattleBoard() {	
	for (int i = 0; i < rows; i++) {
		delete[] board[i];
	}
	delete[] board;
}

void BattleBoard::update() {
	enemy.update(frames);
	player.update(frames);
	npc.update();
	npc.drawOnBoard(board, rows, columns);
	bool playerDamaged = enemy.drawOnBoard(board, rows, columns);
	player.drawOnBoard(board, rows, columns);
	if (player.isAttacking) {
		if (player.battleX + 1 == enemy.battleX && player.battleY == enemy.battleY) {
			enemy.hp -= player.atk - enemy.def;
		}
	}
	if (playerDamaged) {
		player.hp -= enemy.atk - player.def;
	}
	if (enemy.isAttacking) {
		if (enemy.typeOfObject == 7) {
			if (enemy.battleX - 1 == player.battleX && enemy.battleY == player.battleY) {
				player.hp -= enemy.atk - player.def;
			}
		}
		else {
			//Centauro
		}
	}
	frames += 1;
}

void BattleBoard::draw(char** screen) {
	int offX = 14;
	int offY = 7;
	for (int j = 0; j < rows + 1; j++) {
		for (int i = 0; i < columns * 9 + (columns - 1); i++) {
			screen[offY + j * 3][offX + i + 1] = '_';
		}
	}
	for (int i = 0; i < rows * 3; i++) {
		for (int j = 0; j < columns + 1; j++) {
			screen[offY + i + 1][offX + (j * 10)] = '|';
		}
	}
	int baseX, baseY;
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < columns; x++) {
			baseY = offY + 3 * y + 2;
			baseX = offX + 10 * x + 5;
			if (y == 0) {
				screen[baseY - 3][baseX - 4] = ' ';
				screen[baseY - 3][baseX - 3] = ' ';
				screen[baseY - 3][baseX - 2] = ' ';
				screen[baseY - 3][baseX - 1] = ' ';
				screen[baseY - 3][baseX] = ' ';
				screen[baseY - 3][baseX + 1] = ' ';
				screen[baseY - 3][baseX + 2] = ' ';
				screen[baseY - 3][baseX + 3] = ' ';
				screen[baseY - 3][baseX + 4] = ' ';
			}
			for (int i = 0; i < 2; i++) {
				screen[baseY - i][baseX - 4] = ' ';
				screen[baseY - i][baseX - 3] = ' ';
				screen[baseY - i][baseX - 2] = ' ';
				screen[baseY - i][baseX - 1] = ' ';
				screen[baseY - i][baseX] = ' ';
				screen[baseY - i][baseX + 1] = ' ';
				screen[baseY - i][baseX + 2] = ' ';
				screen[baseY - i][baseX + 3] = ' ';
				screen[baseY - i][baseX + 4] = ' ';
			}

			if (board[y][x] != 0) {
				if (board[y][x] == 1) {
					player.drawOnScreen(screen, baseY, baseX);
				}
				else if (board[y][x] <= 7) {
					enemy.drawOnScreen(screen, baseY, baseX);
				}
				else {
					npc.drawOnScreen(screen, baseY, baseX);
				}
			}
		}
	}
}
