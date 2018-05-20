#include "main.h"

TreeNode* f(vector<int>& nums, int start, int end) {
	int count = end - start;
	if (count == 0) return NULL;
	TreeNode* root = new TreeNode(nums[start + count / 2]);
	root->left = f(nums, start, start + count / 2);
	root->right = f(nums, start + count / 2 + 1, end);
	return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	return f(nums, 0, nums.size());
}