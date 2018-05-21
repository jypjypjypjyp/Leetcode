#include"main.h"


int f(int n, int* num) {
	if (num[n] == 0) {
		if (n == 0)
			num[n] = 1;
		else if (n == 1)
			num[n] = 2;
		else
			num[n] = f(n - 1, num) + f(n - 2, num);
	}
	return num[n];
}

int climbStairs(int n) {
	int* num = new int[n] {0};
	return f(n - 1, num);
}