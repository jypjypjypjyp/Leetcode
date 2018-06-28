#include"main.h"

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if (headA == NULL || headB == NULL) return NULL;
	ListNode* i = headA, *endA = NULL, *endB = NULL;
	int sizeA = 1, sizeB = 1,n=0;
	while (i->next != NULL) {
		sizeA++;
		i = i->next;
	}
	endA = i;
	i = headB;
	while (i->next != NULL) {
		sizeB++;
		i = i->next;
	}
	endB = i;
	if (endA != endB) return NULL;
	ListNode *A = headA, *B = headB, **temp = NULL;
	if (sizeA > sizeB) {
		temp = &A;
		n = sizeA - sizeB;
	}
	else {
		temp = &B;
		n = sizeB - sizeA;
	}
	for (int j = 0; j < n; j++) {
		*temp = (*temp)->next;
	}
	while (A != B) {
		A = A->next;
		B = B->next;
	}
	return A;
}