#include "main.h"

int main()
{
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	TreeNode d(4);
	TreeNode e(5);
	a.left = &b;
	a.right = &c;
	c.left = &d;
	c.right = &e;
	auto result1 = serialize(&a);
	auto result2 = deserialize(result1);
}