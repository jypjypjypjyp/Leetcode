#include"main.h"
#include<stack>

int maxDepth(TreeNode* root)
{
	if (root == NULL) return 0;
	stack<TreeNode*> stack;
	TreeNode* currentNode = root;
	stack.push(root);
	int height = 1, maxHeight = 1;
	while (!stack.empty())
	{
		if (currentNode->left != NULL)
		{
			height++;
			stack.push(currentNode->left);
			currentNode = currentNode->left;
		}
		else if (currentNode->right != NULL)
		{
			height++;
			stack.push(currentNode->right);
			currentNode = currentNode->right;
		}
		else
		{
			if (height > maxHeight) maxHeight = height;
			//Go Back
			stack.pop();
			TreeNode* temp=NULL;
			while (!stack.empty()&&((temp=stack.top())->left != currentNode || temp->right == NULL))
			{
				currentNode = temp;
				stack.pop();
				height--;
			}
			if (stack.empty()) break;
			currentNode = temp->right;
			stack.push(currentNode);
		}
	}
	return maxHeight;
}