#include "main.h"

TreeNode* CbuildTree(vector<int>& preorder, vector<int>::iterator pHead, vector<int>::iterator pRear, vector<int>& inorder, vector<int>::iterator iHead, vector<int>::iterator iRear) {
	TreeNode* result = new TreeNode(*pHead);
	//get left child preorder
	auto i = find(iHead, iRear, *pHead);
	int leftNum = i - iHead;
	if (leftNum != 0) {
		result->left = CbuildTree(preorder, pHead + 1, pHead + 1 + leftNum, inorder, iHead, i);
	}
	int rightNum = iRear - i - 1;
	if (rightNum != 0) {
		result->right = CbuildTree(preorder, pHead + 1 + leftNum, pRear, inorder, i + 1, iRear);
	}
	return result;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.empty() || inorder.empty())
		return NULL;
	else
		return CbuildTree(preorder, preorder.begin(), preorder.end(), inorder, inorder.begin(), inorder.end());
}