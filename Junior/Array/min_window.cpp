#include "main.h"
#include <unordered_map>

bool IsContainAll(unordered_map<char, int>& map) {
	for (auto p : map) {
		if (p.second < 0) return false;
	}
	return true;
}

string MinWindow(string s, string t) {
	unordered_map<char, int> map;
	for (char c : t) {
		map[c]--;
	}
	auto start = s.begin();
	auto end = s.begin();
	bool is_contain_all = false;
	int len = INT32_MAX;
	int min_len_s = 0;
	//--------------------------------
	while (true) {
		if (is_contain_all) {
			if ((int)(end - start) < len) {
				len = (int)(end - start);
				min_len_s = (int)(start - s.begin());
			}
			if (map.end() != map.find(*start)) {
				map[*start]--;
				if (map[*start] < 0) is_contain_all = false;
			}
			start++;
		}
		else {
			if (end == s.end()) break;
			if (map.end() != map.find(*end)) {
				map[*end]++;
				is_contain_all = IsContainAll(map);
			}
			end++;
		}
	}
	return s.substr(min_len_s, len>s.size()?0:len);
}