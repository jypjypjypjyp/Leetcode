#include "main.h"
#include <set>

bool compare(const vector<int> &a, const vector<int> &b)
{
	if (a[0] > b[0]) {
		return true;
	}
	else if (a[0] < b[0]) {
		return false;
	}
	else {
		if (a[1] > b[1]) {
			return true;
		}
		else if (a[1] < b[1]) {
			return false;
		}
		else {
			if (a[2] > b[2]) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

vector<vector<int>> threeSum(vector<int>& nums) {
	qsort(&nums[0], nums.size(), sizeof(int), [](const void* a, const void* b) {return *(int*)a - *(int*)b; });
	set<vector<int>, bool(*)(const vector<int>& a, const vector<int>& b)> s(&compare);
	for (int i = 0; i <= nums.size() - 3; i++) {
		int j = nums.size() - 1, k = i + 1;
		while (k != j) {
			if (nums[k] + nums[j] + nums[i] > 0) {
				j--;
			}
			else if (nums[k] + nums[j] + nums[i] < 0) {
				k++;
			}
			else {
				vector<int> tmp({ nums[i], nums[k], nums[j] });
				s.insert(tmp);
				k++;
			}
		}
		while (nums[i] == nums[i + 1]) i++;
	}
	return vector<vector<int>>(s.begin(), s.end());
}

