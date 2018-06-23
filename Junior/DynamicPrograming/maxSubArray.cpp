#include "main.h"

int maxSubArray(vector<int>& nums) {
	if (nums.empty()) return 0;
	int res = nums[0], cur_max = 0;
	for (auto i : nums) {
		cur_max += i;
		if (cur_max > res)
			res = cur_max;
		if (cur_max < 0) {
			cur_max = 0;
		}
	}
	return res;
}