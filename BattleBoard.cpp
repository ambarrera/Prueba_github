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
	enemy.draw(board, rows, columns);
	player.draw(board, rows, columns);
}

void BattleBoard::draw(char** screen) {
	int offX = 12;
	int offY = 12;
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < columns; x++) {
			screen[offY + y][offX + x] = board[y][x] + 39;
		}
	} 
}