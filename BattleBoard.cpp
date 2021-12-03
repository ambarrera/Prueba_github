#include "BattleBoard.h"

BattleBoard::BattleBoard(int boardRows, int boardColumns) :
	enemy(2, 3, 0, 50, 15, 10), player(0, 0)
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
	enemy.update();
	player.update();
	enemy.drawOnBoard(board, rows, columns);
	player.drawOnBoard(board, rows, columns);
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
			switch (board[y][x]) {
			case 0:
				if (y == 0) {
					screen[baseY - 3][baseX - 1] = ' ';
					screen[baseY - 3][baseX] = ' ';
					screen[baseY - 3][baseX + 1] = ' ';
				}
				screen[baseY - 1][baseX - 2] = ' ';
				screen[baseY - 1][baseX - 1] = ' ';
				screen[baseY - 1][baseX] = ' ';
				screen[baseY - 1][baseX + 1] = ' ';
				screen[baseY][baseX - 1] = ' ';
				screen[baseY][baseX] = ' ';
				screen[baseY][baseX + 1] = ' ';
				break;
			case 1:
				player.drawOnScreen(screen, baseY, baseX);
				break;
			case 2:
				enemy.drawOnScreen(screen, baseY, baseX);
				break;
			}
		}
	}
}
