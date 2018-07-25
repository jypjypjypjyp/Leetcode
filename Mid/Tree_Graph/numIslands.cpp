#include "main.h"

int height, width;

void update(vector<vector<char>>& grid, vector<vector<bool>>& state, int r, int c) {
	if (r > 0 && grid[r - 1][c] == '1' && !state[r - 1][c]) {
		state[r - 1][c] = true;
		update(grid, state, r - 1, c);
	}
	if (r < height - 1 && grid[r + 1][c] == '1' && !state[r + 1][c]) {
		state[r + 1][c] = true;
		update(grid, state, r + 1, c);
	}
	if (c > 0 && grid[r][c - 1] == '1' && !state[r][c - 1]) {
		state[r][c - 1] = true;
		update(grid, state, r, c - 1);
	}
	if (c < width - 1 && grid[r][c + 1] == '1' && !state[r][c + 1]) {
		state[r][c + 1] = true;
		update(grid, state, r, c + 1);
	}
}

int numIslands(vector<vector<char>>& grid) {
	if (grid.empty() || grid[0].empty()) return 0;
	height = grid.size(); width = grid[0].size();
	int result = 0;
	vector<vector<bool>> state(height, vector<bool>(width, false));
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (grid[i][j] == '1' && !state[i][j]) {
				result++;
				state[i][j] = true;
				update(grid, state, i, j);
			}
		}
	}
	return result;
}