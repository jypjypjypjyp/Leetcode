#include"main.h"

bool isPalindrome(ListNode* head) {
	if (head == NULL) return true;
	vector<int> array;
	ListNode* temp = head;
	while (temp != NULL) {
		array.push_back(temp->val);
		temp = temp->next;
	}
	int n = array.size();
	for (int i = 0; i < n / 2; i++) {
		if (array[i] != array[n - i - 1]) return false;
	}
	return true; 
}




//bool isPalindrome(ListNode* head) {
//	if (head == NULL || head->next == NULL) return true;
//	ListNode* slow = head;
//	ListNode* fast = head;
//	ListNode* temp = NULL;
//	while (true) {
//		slow = slow->next;
//		fast = fast->next->next;
//		if (fast->next == NULL) {
//			break;
//		}
//		else if (fast->next->next == NULL) {
//			fast = fast->next;
//			break;
//		}
//	}
//	if ((temp = slow->next->next) != NULL) {
//		slow->next->next = slow;
//		slow = slow->next;
//		while (temp != NULL) {
//			ListNode* temp2 = temp->next;
//			temp->next = slow;
//			slow = temp;
//			temp = temp2;
//		}
//	}
//	else {
//		slow->next->next = slow;
//	}
//	slow = head;
//	while (slow != fast && slow->next != fast) {
//		if (slow->val != fast->val) return false;
//		slow = slow->next;
//		fast = fast->next;
//	}
//	return true;
//}