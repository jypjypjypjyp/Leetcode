#include "main.h"
#include <algorithm>

int rob(vector<int>& nums) {
	int  count = nums.size(), *array = new int[count], result = 0;
	bool* isRob = new bool[count];
	if (count != 0) {
		array[0] = nums[0];
		isRob[0] = true;
		if (count > 1) {
			if (nums[0] > nums[1]) {
				array[1] = nums[0];
				isRob[1] = false;
			}
			else {
				array[1] = nums[1];
				isRob[1] = true;
			}
			for (int i = 2; i < count; i++) {
				if (isRob[i - 1]) {
					int temp = array[i - 2] + nums[i];
					if (array[i - 1] > temp) {
						array[i] = array[i - 1];
						isRob[i] = false;
					}
					else {
						array[i] = temp;
						isRob[i] = true;
					}
				}
				else {
					array[i] = array[i - 1] + nums[i];
					isRob[i] = true;
				}
			}
			result = array[count - 1];
		}
		else result = array[0];
	}
	delete[] array;
	delete[] isRob;
	return result;
}