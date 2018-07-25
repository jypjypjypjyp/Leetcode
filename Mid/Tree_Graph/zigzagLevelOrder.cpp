#include "main.h"
#include <queue>

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> result;
	if (root == NULL) return result;
	queue<TreeNode*> q;
	int currentLevel = 0, curLevelNums = 0, nextLevelNums = 0;
	result.push_back(vector<int>());
	q.push(root);
	curLevelNums++;
	while (curLevelNums != 0) {
		if (q.front()->left != NULL) {
			q.push(q.front()->left);
			nextLevelNums++;
		}
		if (q.front()->right != NULL) {
			q.push(q.front()->right);
			nextLevelNums++;
		}
		if (currentLevel % 2 == 0)
			result[currentLevel].push_back(q.front()->val);
		else
			result[currentLevel].insert(result[currentLevel].begin(), q.front()->val);
		q.pop();
		curLevelNums--;
		if (curLevelNums == 0 && nextLevelNums != 0) {
			curLevelNums = nextLevelNums;
			nextLevelNums = 0;
			result.push_back(vector<int>());
			currentLevel++;
		}
	}
	return result;
}