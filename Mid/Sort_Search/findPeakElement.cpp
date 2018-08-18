#include "main.h"

int findPeakElement(vector<int>& nums) {
	if (nums.empty()) return -1;
	else if (nums.size() == 1) return 0;
	else if (nums.size() == 2) return nums[0] > nums[1] ? 0 : 1;
	if (nums[1] < nums[0]) return 0;
	int n = nums.size();
	if (nums[n - 1] > nums[n - 2]) return n - 1;
	for (int i = 2; i <= n / 2+1; i++) {
		if (nums[i] < nums[i - 1]) return i - 1;
		if (nums[n - i - 1] < nums[n - i]) return n - i;
	}
}