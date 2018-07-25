#include "main.h"

vector<int> getSubset(vector<int>& nums, vector<bool>& vec) {
	vector<int> result;
	for (int i = 0; i < nums.size(); i++) {
		if (vec[i]) result.push_back(nums[i]);
	}
	return result;
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> result;
	if (nums.empty()) return result;
	vector<bool> vec(nums.size(),false);
	bool finish = false;
	while (!finish) {
		result.push_back(getSubset(nums,vec));
		int cursor = nums.size() - 1;
		while (cursor >= 0) {
			if (vec[cursor]) {
				vec[cursor--] = false;
			}
			else {
				vec[cursor] = true;
				break;
			}
		}
		if (cursor < 0) break;
	}
	return result;
}