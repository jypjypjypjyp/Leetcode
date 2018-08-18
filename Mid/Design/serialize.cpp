#include "main.h"
#include <queue>
#include <sstream>

string serialize(TreeNode* root)
{
	if (root == NULL) return "";
	stringstream ss;
	queue<TreeNode*> q;
	string result;
	q.push(root);
	int curNode = 0, curNum = 1;
	bool hasChild = false;
	while (true)
	{
		if (q.front() != NULL)
		{
			ss << q.front()->val;
			result += ss.str() + ' ';
			ss.str("");
			if (!(q.front()->left == NULL && q.front()->right == NULL))
				hasChild = true;
			q.push(q.front()->left);
			q.push(q.front()->right);
			q.pop();
		}
		else
		{
			result += "@ ";
			q.push(NULL);
			q.push(NULL);
			q.pop();
		}
		if ((++curNode) == curNum)
		{
			if (!hasChild) break;
			curNum = curNum << 1;
			curNode = 0;
			hasChild = false;
		}
	}
	result.erase(result.end() - 1);
	return result;
}

TreeNode* deserialize(string data)
{
	if (data == "") return NULL;
	stringstream ss(data);
	string s;
	vector<TreeNode*> v;
	while (ss >> s)
	{
		if (s != "@")
		{
			stringstream convert(s);
			int val;
			convert >> val;
			TreeNode* newNode = new TreeNode(val);
			v.push_back(newNode);
		}
		else
		{
			v.push_back(NULL);
		}

	}
	for (int i = 0; i < v.size() / 2; i++)
	{
		v[i]->left = v[(i << 1) + 1];
		v[i]->right = v[(i << 1) + 2];
	}
	return v[0];
}