#include "main.h"

int qsort(vector<int>& nums, int k, int head, int end) {
	int i = head, j = end;
	int key = nums[head];
	while (i < j) {
		while (i < j&&nums[j] >= key)
			j--;
		nums[i] = nums[j];
		while (i < j&&nums[i] <= key)
			i++;
		nums[j] = nums[i];
	}
	nums[i] = key;
	int mi = nums.size() - i;
	if (mi < k)
		return qsort(nums, k, head, i - 1);
	else if (mi > k)
		return qsort(nums, k, i + 1, end);
	else
		return nums[i];
}

int findKthLargest(vector<int>& nums, int k) {
	if (nums.empty()) return 0;
	return qsort(nums, k, 0, nums.size() - 1);
}