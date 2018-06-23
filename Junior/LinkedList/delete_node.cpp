#include"main.h"

void DeleteNode(ListNode* node) {
	ListNode* temp=node->next;
	node->val = temp->val;
	node->next = temp->next;
	delete temp;
}