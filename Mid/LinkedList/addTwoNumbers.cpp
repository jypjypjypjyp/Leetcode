#include "main.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* result = NULL;
	ListNode* cursor = NULL;
	int carry = 0;
	while (l1 != NULL || l2 != NULL) {
		int sum=0;
		if (l1 != NULL && l2 != NULL) {
			sum = l1->val + l2->val + carry;
			l1 = l1->next;
			l2 = l2->next;
		}
		else if (l1 == NULL) {
			sum = l2->val + carry;
			l2 = l2->next;
		}
		else if (l2 == NULL) {
			sum = l1->val + carry;
			l1 = l1->next;
		}
		carry = sum / 10;
		if (result == NULL) {
			result = new ListNode(sum % 10);
			cursor = result;
		}
		else {
			cursor->next = new ListNode(sum % 10);
			cursor = cursor->next;
		}
	}
	if (carry != 0)
		cursor->next = new ListNode(carry);
	return result;
}