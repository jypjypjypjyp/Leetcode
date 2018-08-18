#include "main.h"
#include <algorithm>

int row, column;

int findLowerBound(vector<vector<int>>& matrix, int target, int head, int end)
{
	int mid = (head + end) / 2;
	if (head == mid) return matrix[end][0] <= target ? end : head;
	if (matrix[mid][0] > target)
		return findLowerBound(matrix, target, head, mid);
	else
		return findLowerBound(matrix, target, mid, end);
}

int findUpperBound(vector<vector<int>>& matrix, int target, int head, int end)
{
	int mid = (head + end) / 2;
	if (head == mid) return matrix[head][column - 1] >= target ? head : end;
	if (matrix[mid][column - 1] > target)
		return findUpperBound(matrix, target, head, mid);
	else
		return findUpperBound(matrix, target, mid, end);
}

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	if (matrix.empty()||matrix[0].empty()) return false;
	row = matrix.size(); column = matrix[0].size();
	int lowerBound = findLowerBound(matrix, target, 0, row - 1);
	int upperBound = findUpperBound(matrix, target, 0, row - 1);
	for (int i = upperBound; i <= lowerBound; i++)
	{
		auto iter = lower_bound(matrix[i].begin(), matrix[i].end(), target);
		if (iter != matrix[i].end() && *iter == target)
			return true;
	}
	return false;
}