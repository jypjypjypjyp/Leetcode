#include "main.h"

int main() {
	ListNode a(1);
	ListNode b(2);
	a.next = &b;
	ListNode c(3);
	b.next = &c;
	ListNode a1(1);
	a1.next = &c;
	ListNode d(4);
	c.next = &d;
	ListNode e(5);
	d.next = &e;
	ListNode f(6);
	e.next = &f;
	auto result = getIntersectionNode(&a, &a1);
}