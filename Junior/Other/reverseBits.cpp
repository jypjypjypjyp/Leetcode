#include "main.h"
#include <cmath>

uint32_t reverseBits(uint32_t n) {
	uint32_t result = 0;
	uint32_t a = pow(2, 31);
	for (int i = 0, p = -33; i < 32; i++) {
		result += (n & (a >> i))* pow(2, p += 2);
	}
	return result;
}