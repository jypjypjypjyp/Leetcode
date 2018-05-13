#include"main.h"
#include<sstream>

string CountAndSay(int n) {
	if (n == 1) return "1";
	string previous = CountAndSay(n - 1);
	stringstream ss;
	char current = previous[0];
	int num = 0;
	for (char c : previous) {
		if (c == current) num++;
		else {
			ss << num << current;
			current = c;
			num = 1;
		}
	}
	ss << num << current;
	string s;
	ss >> s;
	return s;
}