#include "main.h"

int main() {
	/*TreeNode a(4);
	TreeNode b(2);
	a.left = &b;
	TreeNode c(6);
	a.right = &c;
	TreeNode d(1);
	b.left = &d;
	TreeNode e(3);
	b.right = &e;
	TreeNode f(5);
	c.left = &f;
	TreeNode g(7);
	c.right = &g;*/
	vector<vector<char>> a;
	a.push_back(vector<char>({ '1','1','1','0','0' }));
	a.push_back(vector<char>({ '0','1','0','0','0' }));
	a.push_back(vector<char>({ '0','1','0','0','0' }));
	a.push_back(vector<char>({ '0','0','0','0','0' }));
	auto result = numIslands(a);
}