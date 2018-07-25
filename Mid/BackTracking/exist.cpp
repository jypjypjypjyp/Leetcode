#include"main.h"
#include<utility>

struct Point {
	int r, c;
	int m = 0;
	Point(int r, int c) : r(r), c(c) {}
};

Point findNextPoint(vector<vector<char>>& board, Point& cur, char c) {
	while (++cur.m <= 4) {
		switch (cur.m)
		{
		case 1:
			if (cur.r - 1 >= 0 && board[cur.r-1][cur.c] == c)
				return Point(cur.r - 1, cur.c);
			break;
		case 2:
			if (cur.r + 1 < board.size() && board[cur.r+1][cur.c] == c)
				return Point(cur.r + 1, cur.c);
			break;
		case 3:
			if (cur.c - 1 >= 0 && board[cur.r][cur.c-1] == c)
				return Point(cur.r, cur.c - 1);
			break;
		case 4:
			if (cur.c + 1 < board[0].size() && board[cur.r][cur.c+1] == c)
				return Point(cur.r, cur.c + 1);
			break;
		}
	}
	return Point(-1, -1);
}

bool alreadyInclude(vector<Point>& path, Point p) {
	for (Point point : path) {
		if (point.c == p.c && point.r == p.r) return true;
	}
	return false;
}

bool exist(vector<vector<char>>& board, string word) {
	//上1下2左3右4
	//首先确认第一个点有几种情况
	vector<Point> firstPoint;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == word[0]) {
				firstPoint.push_back(Point(i, j));
			}
		}
	}
	if (firstPoint.empty()) return false;
	//栈
	vector<Point> path;
	//第一个入栈
	int i = 0;
	path.push_back(firstPoint[i++]);
	if (path.size() == word.size()) return true;
	while (true) {
		Point p = findNextPoint(board, path[path.size() - 1], word[path.size()]);
		if (p.c == -1 && p.r == -1) {
			path.pop_back();
			if (path.empty()) {
				if (i == firstPoint.size()) return false;
				path.push_back(firstPoint[i++]);
			}
		}
		else {
			if (!alreadyInclude(path, p)) {
				path.push_back(p);
				if (path.size() == word.size()) return true;
			}
		}
	}
}