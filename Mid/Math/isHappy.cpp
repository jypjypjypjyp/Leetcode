#include "main.h"
#include <set>

bool isHappy(int n)
{
	set<int> s;
	while (s.find(n) == s.end())
	{
		s.insert(n);
		int f = 1;
		int sum = 0;
		int t;
		while (f != 1410065408 && (t = (n / f)) != 0)
		{
			sum += pow(t % 10, 2);
			f *= 10;
		}
		if (sum == 1)
			return true;
		n = sum;
	}
	return false;
}