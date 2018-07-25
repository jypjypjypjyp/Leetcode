#include "main.h"

void connect(TreeLinkNode *root) {
	if (root == NULL || root->left!=NULL) return;
	root->left->next = root->right;
	if (root->next != NULL)
		root->right->next = root->next->left;
	connect(root->left);
	connect(root->right);
}