#include"main.h"

string LongestCommonPrefix(vector<string>& strs) {
	string result = "";
	char c;
	bool isOk = true;
	if (strs.empty()) return result;
	for (int i = 0; i < strs[0].size(); i++) {
		c = strs[0][i];
		for (string& s : strs) {
			if (s[i] != c) { isOk = false; break; }
		}
		if (isOk) result += c;
		else break;
	}
	return result;
}