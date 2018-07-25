#include "main.h"
#include <algorithm>

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> result;
	if (nums.size() == 0) return result;
	sort(nums.begin(),nums.end());
	result.push_back(nums);
	while (next_permutation(nums.begin(),nums.end())) {
		result.push_back(nums);
	}
	return result;
}