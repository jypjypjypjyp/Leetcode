#include "main.h"
#include <stack>

bool isCouple(char c, char t) {
	switch (c)
	{
	case'(': {
		if (t == ')') return true;
		break;
	}
	case'[': {
		if (t == ']') return true;
		break;
	}
	case'{': {
		if (t == '}') return true;
		break;
	}
	default:
		break;
	}
	return false;
}

bool isValid(string s) {
	stack<char> stack;
	for (char c : s) {
		if (c == '(' || c == '[' || c == '{') {
			stack.push(c);
		}
		else if (c == ')' || c == ']' || c == '}') {
			if (stack.size() != 0 && isCouple(stack.top(), c)) {
				stack.pop();
			}
			else return false;
		}
	}
	if (stack.size() == 0)
		return true;
	else return false;
}