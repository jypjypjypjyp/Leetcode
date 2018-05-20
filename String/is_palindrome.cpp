#include"main.h"

bool IsPalindrome(string s) {
	int i = 0, j = s.size() - 1;
	while (i <= j) {
		if (!isalnum(s[i])) i++;
		else if (!isalnum(s[j])) j--;
		else if (toupper(s[i]) != toupper(s[j])) return false;
		else {
			i++;
			j--;
		}
	}
	return true;

}