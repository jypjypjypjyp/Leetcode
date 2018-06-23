#include"main.h"

bool increasingTriplet(vector<int>& nums) {
	int a[3], b, an = 0;
	bool ab = false;
	for (int i : nums) {
		if (!ab) {
			if (an == 0) {
				a[0] = i;
				an++;
			}
			else if (an == 1) {
				if (i > a[1]) {
					a[1] = i;
					an++;
				}
				else if (i < a[1]) {
					a[0] = i;
				}
			}
			else if (an == 2) {
				if (i < a[0]) {
					b = i;
					ab = true;
				}
				else if (a[0] < i && i < a[1]) {
					a[1] = i;
				}
				else if (i > a[1]) {
					return true;
				}
			}
		}
		else {
			if (i < b) {
				b = i;
			}
			else if (b < i && i < a[1]) {
				a[0] = b;
				a[1] = i;
				ab = false;
			}
			else if (i > a[1]) {
				return true;
			}
		}
	}
	return false;
}