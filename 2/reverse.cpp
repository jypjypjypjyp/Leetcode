#include"main.h"
#include<stdlib.h>
#include<string>
#include<sstream>

int Reverse(int x) {
	int flag = 1;
	if (x < 0) {
		x = -x;
		flag = -1;
	}
	int64_t sum = 0;
	while (x > 0) {
		sum = sum * 10 + x % 10;
		x /= 10;
	}
	sum = sum * flag;
	return (sum > INT32_MAX || sum < INT32_MIN) ? 0 : sum;
}