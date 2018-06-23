#include<iostream>
#include"main.h"

int main() {
	/*TreeNode root(1);
	TreeNode a(2);
	TreeNode b(2);
	TreeNode d(4);
	TreeNode f(3);
	root.left = &a;
	root.right = &b;
	a.right = &d;
	b.right = &f;*/
	vector<int> a({ -10,-3,0,5,9 });
	auto result = sortedArrayToBST(a);
}