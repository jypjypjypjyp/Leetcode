#include "main.h"

int uniquePaths(int m, int n)
{
	if (m <= 1 || n <= 1) return 1;
	vector<vector<int>> table(n, vector<int>(m, 1));
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
			table[i][j] = table[i - 1][j] + table[i][j - 1];
	}
	return table[n - 1][m - 1];
}