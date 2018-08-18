#include "main.h"

int titleToNumber(string s)
{
	auto iter = s.end() - 1;
	int result = 0, curN = 1;
	while (true)
	{
		result += ((*iter) - 'A' + 1)*curN;
		curN *= 26;
		if (iter == s.begin()) break;
		iter--;
	}
	return result;
}