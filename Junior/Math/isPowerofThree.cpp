#include"main.h"
#include<cmath>

bool isPowerOfThree(int n) {
	double f = log10(n) / log10(3);
	if (f == (int)f) {
		return true;
	}
	return false;
}