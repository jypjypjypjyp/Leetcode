#include "main.h"

bool isPalidrome(string s, int a, int b) {
	while (a < b) {
		if (s[a] != s[b]) return false;
		a++;
		b--;
	}
}

string longestPalindrome(string s) {
	int n = s.size();
	if (n == 0) return "";
	int resulta=0, results=1;
	int* pLength = new int[n] { 1 }; 
	for (int i = 0; i < n; i++) {
		char c = s[i];
		int j = i;
		int lowerBound = i + pLength[i];
		while (j = s.find(c, j + 1)) {
			if (j == string::npos) {
				break;
			}
			else {
				if (j<lowerBound)
					continue;
				if (isPalidrome(s, i, j)) {
					int s = j - i + 1;
					if (s > results) {
						resulta = i;
						results = s;
					}
					for (int k = i; k < j; k++) {
						pLength[k] = s;
						s--;
					}
				}
			}
		}
	}
	return s.substr(resulta, results);
}