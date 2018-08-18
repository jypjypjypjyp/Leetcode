#include "main.h"
#include <unordered_map>
#include <queue>

int leastInterval(vector<char>& tasks, int n)
{
	if (n == 0) return tasks.size();
	//init
	unordered_map<char, int> map;
	for (char c : tasks)
		map[c]++;
	vector<char> q(n, 0);
	//---------
	int tag = 0, result = 0, left = tasks.size(), isAssign = false;
	while (left > 0)
	{
		//get availble task 
		for (auto pair : map)
		{
			auto iter = find(q.begin(), q.end(), pair.first);
			if (iter == q.end())
			{
				isAssign = true;
				q[tag] = pair.first;
				left--;
				if (++tag == n) tag = 0;
				if (--map[pair.first] == 0)
					map.erase(pair.first);
				break;
			}
		}
		if (!isAssign)
		{
			q[tag] = 0;
			if (++tag == n) tag = 0;
		}
		result++;
		isAssign = false;
	}
	return result;
}