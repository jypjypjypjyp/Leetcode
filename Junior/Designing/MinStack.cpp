#include "MinStack.h"



MinStack::MinStack()
{
	size = 0;
}

MinStack::~MinStack()
{
	Node* current = head, *next;
	while (current != nullptr)
	{
		next = current->next;
		delete current;
		current = next;
	}
}

void MinStack::push(int x)
{
	size++;
	if (size == 1) {
		head = new Node();
		current = head;
		current->a[0] = x;
		min = x;
	}
	else if (size % 256 == 1) {
		Node* newNode = new Node();
		current->next = newNode;
		newNode->prev = current;
		current = newNode;
		newNode->a[0] = x;
	}
	else {
		current->a[size % 256] = x;
	}
	if (x < min) min = x;
}

void MinStack::pop()
{
	if (size != 0) {
		if (top() == min) {
			min = head->a[0];
			Node* c = head;
			while (c != nullptr)
			{
				int s = (c == current) ? size % 256 : 256;
				for (int i = 0; i < s; i++) {
					if (current->a[i] < min) 
						min = current->a[i];
				}
				c = c->next;
			}
		}
		size--;
		if (size % 256 == 0) {
			Node* temp = current->prev;
			delete current;
			current = temp;
		}
	}
}

int MinStack::top()
{
	return current->a[size % 256 - 1];
}

int MinStack::getMin()
{
	return min;
}
