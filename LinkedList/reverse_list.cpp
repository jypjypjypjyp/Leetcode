#include"main.h"


//µİ¹éĞ§ÂÊÌ«µÍÁË
//ListNode* ReverseList(ListNode* head) {
//	if (head == NULL) return NULL;
//	ListNode* a =new ListNode(head->val);
//	if (head->next == NULL) {
//		return a;
//	}
//	ListNode* result = ReverseList(head->next);
//	ListNode* temp = result;
//	while (temp->next != NULL) {
//		temp = temp->next;
//	}
//	temp->next = a;
//	return result;
//}

ListNode* ReverseList(ListNode* head) {
	if (head == NULL) return NULL;
	ListNode* top = new ListNode(head->val);
	ListNode* temp = head->next;
	ListNode* beneath=top;
	while (temp!=NULL) {
		beneath = new ListNode(temp->val);
		beneath->next = top;
		top = beneath;
		temp = temp->next;
	}
	return beneath;
}