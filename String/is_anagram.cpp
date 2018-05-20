#include"main.h"

bool IsAnagram(string s, string t) {
	int record[26] = {0};
	for (char c : s) {
		record[c - 'a']++;
	}
	for (char c : t) {
		record[c - 'a']--;
	}
	for (int i : record) {
		if (i != 0) return false;
	}
	return true;
}