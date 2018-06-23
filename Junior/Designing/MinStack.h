#pragma once
struct Node
{
	int a[256];
	Node* next;
	Node* prev;
	Node() :next(nullptr), prev(nullptr) {}
};


class MinStack
{
private:
	Node * head;
	Node * current;
	int size;
	int min;
public:
	MinStack();
	~MinStack();
	void push(int x);
	void pop();
	int top();
	int getMin();
};

