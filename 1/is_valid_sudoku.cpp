#include"main.h"

bool IsValidUnit(const vector<char>& unit) {
	bool unit_set[9] = { false };
	for (char i : unit) {
		if (i != '.') {
			if (unit_set[(int)(i - '0')-1]) {
				return false;
			}
			else {
				unit_set[(int)(i - '0')-1] = true;
			}
		}
	}
	return true;
}

bool IsValidSudoku(vector<vector<char>>& board) {
	//row
	for (int i = 0; i < 9; i++) {
		vector<char> unit = board[i];
		if (!IsValidUnit(unit)) return false;
	}
	//column
	for (int i = 0; i < 9; i++) {
		vector<char> unit;
		for (int j = 0; j < 9; j++) {
			unit.push_back(board[j][i]);
		}
		if (!IsValidUnit(unit)) return false;
	}
	//box
	for (int i = 0; i < 9; i+=3) {
		for (int j = 0; j < 9; j+=3) {
			vector<char> unit;
			unit.push_back(board[i][j]);
			unit.push_back(board[i+1][j]);
			unit.push_back(board[i+2][j]);
			unit.push_back(board[i][j+1]);
			unit.push_back(board[i+1][j+1]);
			unit.push_back(board[i+2][j+1]);
			unit.push_back(board[i][j+2]);
			unit.push_back(board[i+1][j+2]);
			unit.push_back(board[i+2][j+2]);
			if (!IsValidUnit(unit)) return false;
		}
	}
	return true;
}