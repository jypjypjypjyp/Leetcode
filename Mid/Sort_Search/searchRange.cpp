#include "main.h"

vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> result({ -1,-1 });
	if (nums.empty()||nums[0] > target || nums[nums.size() - 1] < target) return result;
	int head = 0, end = nums.size() - 1;
	int mid = (head + end) >> 1;
	while (head != end) {
		if (nums[mid] > target) {
			end = mid - 1;
		}
		else if (nums[mid] < target) {
			head = mid + 1;
		}
		else {
			break;
		}
		mid = (head + end) >> 1;
	}
	if (head == end && nums[head] != target) return result;
	int tmp = mid;
	while (tmp >= 0 && nums[--tmp] == target);
	result[0] = tmp + 1;
	while (mid < nums.size() && nums[++mid] == target);
	result[1] = mid - 1;
	return result;
}