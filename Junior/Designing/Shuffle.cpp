#include "Solution.h"
#include <random>
#include <ctime>
#include <algorithm>
#include <utility> 

Shuffle::Shuffle(vector<int> nums)
{
	this->nums = nums;
	originalNums = nums;
}

vector<int> Shuffle::reset()
{
	nums = originalNums;
	return nums;
}

int compare(const void *arg1, const void *arg2) {
	return ((pair<int, int>*)(arg1))->second
		- ((pair<int, int>*)(arg2))->second;
}

vector<int> Shuffle::shuffle()
{
	int size = nums.size();
	pair<int, int>* p = new pair<int, int>[size];
	srand(unsigned(time(0)));
	for (int i = 0; i < size; i++) {
		p[i].first = i;
		p[i].second = rand();
	}
	qsort(p, size, sizeof(*p), compare);
	for (int i = 0; i < size; i++) {
		nums[i] = originalNums[p[i].first];
	}
	return nums;
}

Shuffle::~Shuffle()
{
}
