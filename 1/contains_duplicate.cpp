#include"main.h"
#include<set>

bool ContainsDuplicate(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	return unique(nums.begin(), nums.end()) != nums.end();
}