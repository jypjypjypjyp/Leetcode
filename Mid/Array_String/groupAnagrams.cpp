#include"main.h"

struct Info
{
	int* set;
	vector<string> strs;
};

bool compare(const Info &a, const Info &b)
{
	for (int i = 0; i < 26; i++) {
		if (a.set[i] > b.set[i]) {
			return true;
		}
		else if (a.set[i] < b.set[i]) {
			return false;
		}
	}
	return false;
}

int* getInfo(string s) {
	int *info = new int[26]{ 0 };
	for (char c : s) {
		info[c - 'a']++;
	}
	return info;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	set<Info, bool(*)(const Info &a, const Info &b)> info_set(&compare);
	for (auto i : strs) {
		int *info = getInfo(i);
		Info tmp = {
			info,
			vector<string>({i})
		};
		auto j = info_set.find(tmp);
		if (j == info_set.end()) {
			info_set.insert(tmp);
		}
		else {
			Info tmp = (*j);
			tmp.strs.push_back(i);
			info_set.erase(j);
			info_set.insert(tmp);
		}
	}
	vector<vector<string>> result;
	for (auto i : info_set) {
		result.push_back(i.strs);
		delete[] i.set;
	}
	return result;
}