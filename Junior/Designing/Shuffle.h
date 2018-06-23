#pragma once
#include"main.h"
class Shuffle
{
private:
	vector<int> originalNums;
	vector<int> nums;
public:
	Shuffle(vector<int> nums);
	vector<int> reset();
	vector<int> shuffle();
	~Shuffle();
};

