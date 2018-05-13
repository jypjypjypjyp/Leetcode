#include"main.h"

vector<int> Intersect(vector<int>& nums1, vector<int>& nums2) {
	vector<int> result;
	if (nums1.empty() || nums2.empty())return result;
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	auto j = nums2.begin();
	auto i = nums1.begin();
	while (i < nums1.end() && j < nums2.end()) {
		if (*i == *j) {
			result.push_back(*i);
			j++;
			i++;
		}
		else if (*i > *j) {
			j++;
		}
		else {
			i++;
		}
	}
	return result;
}