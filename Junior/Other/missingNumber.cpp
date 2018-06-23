#include "main.h"

int missingNumber(vector<int>& nums) {
	int cur = 0, n = nums.size(), value = 0;
	while (cur != -1) {
		value = nums[cur];
		int next;
		if (value < nums.size())
			next = value;
		else
			next = 1;
		while (nums[next] < 0) {
			next++;
		}
		if (next < nums.size())
			cur = next;
		else
			cur = -1;
	}
	int i = 0;
	for (; i < n; i++) {
		if (nums[i] >= 0) break;
	}
	return i;
}