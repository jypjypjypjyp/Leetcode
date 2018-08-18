#include "main.h"

int divide(int dividend, int divisor)
{
	long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
	if (m < n) return 0;
	while (m >= n)
	{
		long long t = n, p = 1;
		while (m >(t << 1))
		{
			t <<= 1;
			p <<= 1;
		}
		res += p;
		m -= t;
	}
	if ((dividend < 0) ^ (divisor < 0)) res = -res;
	return res > INT_MAX ? INT_MAX : res;

}