#include "main.h"
#include <stack>

bool Symmetrical(TreeNode* left, TreeNode* right)
{
	if (left == NULL && right == NULL) return true;
	if (right == NULL || left == NULL) return false;
	return (left->val == right->val);
}

bool f(TreeNode* left, TreeNode* right) {
	if (!Symmetrical(left, right)) return false;
	else
		if (left != NULL)
			return f(left->left, right->right) && f(left->right, right->left);
		else
			return true;
}

bool isSymmetric(TreeNode* root)
{
	if (root == NULL) return true;
	return f(root->left, root->right);
}
