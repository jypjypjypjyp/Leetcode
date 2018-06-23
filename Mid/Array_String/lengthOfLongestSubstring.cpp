#include "main.h"
#include <set>

int lengthOfLongestSubstring(string s) {
	int result = 1, head = 0, rear = 0, size = s.size() - 1;
	bool isOK = true;
	char badAlpha;
	if (size == 0) return 0;
	set<char> alphabet;
	alphabet.insert(s[0]);
	while (rear < size) {
		if (isOK) {
			rear++;
			if (alphabet.find(s[rear]) == alphabet.end()) {
				alphabet.insert(s[rear]);
				if (result < rear - head + 1)
					result = rear - head + 1;
			}
			else {
				badAlpha = s[rear];
				isOK = false;
			}
		}
		else {
			if (s[head] == badAlpha) {
				isOK = true;
			}
			else {
				alphabet.erase(s[head]);
			}
			head++;
		}
	}
	return result;
}