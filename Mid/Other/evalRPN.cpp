#include "main.h"
#include <stack>
#include <sstream>

vector<string> sign({ "+","-", "*", "/" });

int stringToInt(string s)
{
	stringstream ss(s);
	int result;
	ss >> result;
	return result;
}

int evalRPN(vector<string>& tokens)
{
	stack<int> s;
	for (string i : tokens)
	{
		auto iter = find(sign.begin(), sign.end(), i);
		if (iter == sign.end())
		{
			s.push(stringToInt(i));
		}
		else
		{
			int a, b, c;
			b = s.top();
			s.pop();
			a = s.top();
			s.pop();
			switch (iter - sign.begin())
			{
			case 0:c = a + b; break;
			case 1:c = a - b; break;
			case 2:c = a * b; break;
			case 3:c = a / b; break;
			}
			s.push(c);
		}
	}
	return s.top();
}