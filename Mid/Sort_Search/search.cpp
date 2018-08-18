#include "main.h"
#include <algorithm>

int findSpecialPoint(vector<int>& nums, int head, int end)
{
	if (nums[head] < nums[end]) return head;
	int mid = (head + end) / 2;
	if (nums[mid] > nums[head])
		return findSpecialPoint(nums, mid, end);
	else if (nums[mid] < nums[head])
		return findSpecialPoint(nums, head, mid);
	else
		return nums[head] > nums[head + 1] ? head + 1 : head;
}

int search(vector<int>& nums, int target)
{
	if (nums.empty()) return -1;
	//find special point
	int specialPoint = findSpecialPoint(nums, 0, nums.size() - 1);
	//find target index
	int result;
	if (target >= nums[0])
		result = lower_bound(nums.begin(), (specialPoint != 0) ? nums.begin() + specialPoint : nums.end(), target) - nums.begin();
	else
		result = lower_bound(nums.begin() + specialPoint, nums.end(), target) - nums.begin();
	if (result != nums.size() && nums[result] == target) return result;
	else return -1;
}