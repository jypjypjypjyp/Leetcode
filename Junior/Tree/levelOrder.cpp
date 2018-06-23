#include "main.h"
#include <queue>
vector<vector<int>> levelOrder(TreeNode* root) {
	queue<TreeNode*> queue;
	vector<vector<int>> result;
	if (root == NULL) return result;
	int nextLevelCount = 0, currentLevelCount = 1, level = 0;
	queue.push(root);
	while (currentLevelCount != 0) {
		result.push_back(vector<int>());
		while (currentLevelCount > 0) {
			auto temp = queue.front();
			result[level].push_back(temp->val);
			queue.pop();
			currentLevelCount--;
			if (temp->left != NULL) {
				queue.push(temp->left);
				nextLevelCount++;
			}
			if (temp->right != NULL) {
				queue.push(temp->right);
				nextLevelCount++;
			}
		}
		currentLevelCount = nextLevelCount;
		nextLevelCount = 0;
		level++;
	}
	return result;
}