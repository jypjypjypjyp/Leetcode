#include"main.h"

int FirstUniqChar(string s) {
	int record[26] = { 0 };
	for (char c : s) {
		record[c - 'a']++;
	}
	for (int i = 0; i < s.size(); i++) {
		if (record[s[i] - 'a'] == 1) return i;
	}
	return -1;

}