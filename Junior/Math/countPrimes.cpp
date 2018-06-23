#include "main.h"

int countPrimes(int n) {
	if (n < 2) return 0;
	vector<int> ps;
	for (int i = 3; i <= n; i += 2) {
		bool isP = true;
		for (int a : ps) {
			if (i%a == 0)
			{
				isP = false;
				break;
			}
		}
		if (isP)
			ps.push_back(i);
	}
	return ps.size() + 1;
}