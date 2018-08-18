#include "main.h"

int coinChange(vector<int>& coins, int amount)
{
	if (coins.empty()) return -1;
	if (amount == 0) return 0;
	vector<int> table(amount, -1);
	for (int i : coins)
	{
		if (i > amount) continue;
		table[i - 1] = 1;
	}
	vector<int> temp(coins.size(), -1);
	for (int i = 0; i < amount; i++)
	{
		if (table[i] != -1) continue;
		for (int j = 0; j < coins.size(); j++)
		{
			temp[j] = (i - coins[j]) < 0 ? -1 : table[i - coins[j]];
		}
		int m = -1;
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] == -1) continue;
			else if (m == -1 || m > temp[i]) m = temp[i];
		}
		if (m != -1) table[i] = m + 1;
	}
	if (table[amount - 1] == -1) return -1;
	else return table[amount - 1];
}