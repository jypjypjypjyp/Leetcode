#include "main.h"

bool canJump(vector<int>& nums)
{
	if (nums.empty()) return false;
	int maxAchieve = 0;
	for (int i = 0; i <= maxAchieve; i++)
	{
		if (maxAchieve < nums[i] + i)
		{
			maxAchieve = nums[i] + i;
			if (maxAchieve >= nums.size() - 1)
				break;
		}
	}
	if (maxAchieve >= nums.size() - 1) return true;
	else return false;
}