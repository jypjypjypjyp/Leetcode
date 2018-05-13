#include<iostream>
#include"main.h"

int main() {
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(3);
	ListNode e(2);
	ListNode f(8);
	/*a.next = &b;
	b.next = &f;*/
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	auto result = isPalindrome(&a);
}