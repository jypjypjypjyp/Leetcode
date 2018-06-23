#include"main.h"

void MoveZeroes(vector<int>& nums) {
	auto i = nums.begin();
	auto j = nums.begin();//0µÄ¿ªÍ·
	while (i < nums.end()) {
		if (*i != 0)
		{
			int temp = *j;
			*j = *i;
			*i = temp;
			j++;
		}
		i++;
	}
}