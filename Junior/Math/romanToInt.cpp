#include "main.h"
#include <map>
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
int romanToInt(string s) {
	map<char, int> table;
	table['I'] = 1;
	table['V'] = 5;
	table['X'] = 10;
	table['L'] = 50;
	table['C'] = 100;
	table['D'] = 500;
	table['M'] = 1000;
	char state = 'S';
	char last;
	int result = 0;
	for (char c : s) {
		switch (state)
		{
		case'S': {
			last = c;
			state = 'A';
			break;
		}
		case'A': {
			if (table[c] > table[last]) {
				result += table[c] - table[last];
				state = 'B';
			}
			else {
				result += table[last];
				last = c;
			}
			break;
		}
		case'B': {
			last = c;
			state = 'A';
			break;
		}
		default:
			break;
		}
	}
	if (state == 'A')
		result += table[last];
	return result;
}