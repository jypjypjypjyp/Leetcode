#include"main.h"

ListNode* RemoveNthFromEnd(ListNode* head, int n) {
	int num = 0;
	ListNode* temp = head;
	while (temp!=NULL) {
		num++;
		temp = temp->next;
	}
	num -= n;
	if (num == 0) return head->next;
	temp = head;
	while (temp != NULL) {
		if (num == 1) {
			ListNode* a = temp->next;
			temp->next = a->next;
			delete a;
			break;
		}
		else {
			temp = temp->next;
			num--;
		}
	}
	return head;
}