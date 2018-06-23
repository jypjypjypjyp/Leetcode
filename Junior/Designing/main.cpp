#include"main.h"
#include "Solution.h"

int main() {
	vector<int> nums({ 1,2,3,4,5,6,7,8,9,10 });
	Shuffle s(nums);
	auto result = s.shuffle();
	result = s.reset();
	result = s.shuffle();
}