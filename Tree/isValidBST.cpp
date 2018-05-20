#include "main.h"
#include <stack>

bool f(TreeNode* root, int& min, int& max) {
	bool hasLeft = (root->left != NULL), hasRight = (root->right != NULL);
	int mid = root->val, left = mid, right = mid;
	min = mid; max = mid;
	if (hasLeft) {
		if (!f(root->left, min, left)) return false;
	}
	if (hasRight) {
		if (!f(root->right, right, max)) return false;
	}
	return  (!hasLeft || left < mid) && (!hasRight || right > mid);
}

bool isValidBST(TreeNode* root)
{
	if (root == NULL) return true;
	int min = 0, max = 0;
	return f(root, min, max);
}



