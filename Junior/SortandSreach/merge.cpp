#include "main.h"

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	nums1.erase(nums1.begin() + m, nums1.end());
	int i = 0, j = 0;
	while (i < m && j < n) {
		if (nums1[i] < nums2[j]) {
			i++;
		}
		else {
			nums1.insert(nums1.begin() + i, nums2[j]);
			m++;
			j++;
			i++;
		}
	}
	if (j != n) {
		nums1.insert(nums1.begin() + m, nums2.begin() + j, nums2.begin() + n);
	}
}