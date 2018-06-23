#include"main.h"

int maxProfit(vector<int>& prices) {
	vector<int> vs;
	for (int i = 0; i < prices.size() - 1; i++) {
		vs.push_back(prices[i + 1] - prices[i]);
	}
	int res = maxSubArray(vs);
	return res < 0 ? 0 : res;
}