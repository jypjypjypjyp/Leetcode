#include"main.h"
#include<map>

int SingleNumber(vector<int>& nums) {
	map<int,int> map_num;
	for (int i : nums) {
		map_num[i]++;
	}
	for (auto& i : map_num) {
		if (i.second == 1) return i.first;
	}
}