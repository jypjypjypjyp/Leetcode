#include "main.h"
#include <unordered_map>

int majorityElement(vector<int>& nums)
{
	if (nums.size() <= 2) return nums[0];
	unordered_map<int, int> map;
	for (int i : nums)
	{
		auto iter = map.find(i);
		if ( iter == map.end())
			map.insert(pair<int, int>(i, 1));
		else
		{
			(*iter).second++;
			if ((*iter).second > nums.size() / 2)
				return i;
		}
	}
}