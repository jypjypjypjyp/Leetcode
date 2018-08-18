#pragma once
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string serialize(TreeNode* root);
TreeNode* deserialize(string data);