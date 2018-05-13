#include"main.h"
#include<map>

vector<int> TwoSum(vector<int>& nums, int target) {
	vector<pair<int, int>> map;
	for (int i = 0; i < nums.size(); i++) {
		map.push_back(pair<int,int>(i, nums[i]));
	}
	sort(map.begin(),map.end(),
		[](pair<int,int> a, pair<int, int> b){
			return a.second < b.second;
		});
	int i = 0;
	int j = map.size()-1;
	while (i != j) {
		if (map[i].second + map[j].second > target) {
			j--;
		}
		else if (map[i].second + map[j].second < target) {
			i++;
		}
		else {
			return vector<int>({ map[i].first,map[j].first });
		}
	}
}