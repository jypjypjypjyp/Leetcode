#include"main.h"

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* result = NULL;
	ListNode* result_rear = NULL;
	ListNode* temp = NULL;
	while (l1 != NULL || l2 != NULL) {
		if (l1 == NULL) {
			temp = new ListNode(l2->val);
			l2 = l2->next;
		}
		else if (l2 == NULL) {
			temp = new ListNode(l1->val);
			l1 = l1->next;
		}
		else {
			if (l1->val > l2->val) {
				temp = new ListNode(l2->val);
				l2 = l2->next;
			}
			else {
				temp = new ListNode(l1->val);
				l1 = l1->next;
			}
		}
		if (result == NULL) { 
			result = temp; 
			result_rear = temp;
		}
		else { 
			result_rear->next = temp;
			result_rear = temp;
		}
	}
	return result;
}