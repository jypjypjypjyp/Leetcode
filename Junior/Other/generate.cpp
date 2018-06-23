#include "main.h"

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> result(numRows, vector<int>());
	if (numRows < 1)
		return result;
	result[0].push_back(1);
	if (numRows == 1)
		return result;
	for (int i = 1; i < numRows; i++) {
		vector<int>& curRow = result[i];
		vector<int>& lastRow = result[i - 1];
		curRow.push_back(1);
		for (int j = 0; j < lastRow.size() - 1; j++) {
			curRow.push_back(lastRow[j] + lastRow[j + 1]);
		}
		curRow.push_back(1);
	}
	return result;
}