#include "main.h"
#include <stack>
#include <utility>


vector<int> inorderTraversal(TreeNode* root) {
	vector<int> result;
	if (root == NULL) return  result;
	stack<pair<TreeNode*, int>> st;
	st.push(make_pair(root, 0));
	while (!st.empty()) {
		if (st.top().first->left != NULL && st.top().second != 1) {
			st.top().second = 1;//1->×ó±ß×ÓÊ÷ÈëÕ»
			st.push(make_pair(st.top().first->left, 0));
		}
		else {
			result.push_back(st.top().first->val);
			TreeNode* temp = st.top().first->right;
			st.pop();
			if (temp != NULL) {
				st.push(make_pair(temp, 0));
			}
		}
	}
	return result;
}