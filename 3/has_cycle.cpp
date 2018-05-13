#include"main.h"

bool hasCycle(ListNode *head) {
	ListNode *slow = head, *fast = head;
	while (fast!=NULL) {
		slow = slow->next;
		fast = fast->next;
		if (fast == NULL) break;
		fast = fast->next;
		if (slow == fast) return true;
	}
	return false;
}