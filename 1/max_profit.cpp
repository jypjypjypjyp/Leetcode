#include"main.h"

int MaxProfit(vector<int> &prices)
{
    int max_profit=0;
    for (int i = 1; i < prices.size(); i++)
    {
        int diff = prices[i] - prices[i - 1];
        max_profit += (diff > 0) ? diff : 0;
    }
    return max_profit;
}