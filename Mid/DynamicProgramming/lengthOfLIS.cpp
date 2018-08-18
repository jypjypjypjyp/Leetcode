#include "main.h"

int lengthOfLIS(vector<int>& nums)
{
	if (nums.empty()) return 0;
	vector<int> table;
	for (int n : nums)
	{
		vector<int>::iterator iter = lower_bound(table.begin(), table.end(), n);
		if (iter == table.end())
			table.push_back(n);
		else if (*iter > n)
			*iter = n;
	}
	return table.size();
}