#include "main.h"

ListNode* oddEvenList(ListNode* head) {
	ListNode* a = head, *b = head, *c = NULL;
	while ((c = a = a->next) != NULL && (a = a->next) != NULL) {
		c->next = a->next;
		a->next = b->next;
		b = b->next = a;
		a = c;
	}
	return head;
}