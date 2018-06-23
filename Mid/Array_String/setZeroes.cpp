#include "main.h"
#include <set>

void setZeroes(vector<vector<int>>& matrix) {
	set<int> rowSet, colSet;
	int row = matrix.size(),
		col = matrix[0].size();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (matrix[i][j] == 0)
			{
				rowSet.insert(i);
				colSet.insert(j);
			}
		}
	}
	for (auto i : rowSet) {
		for (int j = 0; j < col; j++)
			matrix[i][j] = 0;
	}
	for (auto j : colSet) {
		for (int i = 0; i < row; i++)
			matrix[i][j] = 0;
	}
}