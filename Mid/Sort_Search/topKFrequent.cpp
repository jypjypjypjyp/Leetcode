#include "main.h"
#include <queue>
#include <functional>
#include <unordered_map>

struct N {
	int k;
	int v;
	N(int k, int v) :k(k), v(v) {}
};

struct cmp
{
	bool operator ()(N& a, N& b) {
		return a.v > b.v;
	}
};

vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> map;
	for (int i : nums) {
		map[i]++;
	}
	priority_queue < N, vector<N>, cmp > q;
	for (pair<int, int> i : map) {
		if (q.size() < k) {
			q.push(N(i.first, i.second));
		}
		else if (q.top().v < i.second) {
			q.pop();
			q.push(N(i.first, i.second));
		}
	}
	vector<int> result;
	while (!q.empty()) {
		result.push_back(q.top().k);
		q.pop();
	}
	return result;
}