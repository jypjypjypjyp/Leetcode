#include "main.h"
#include <sstream>

vector<string> fizzBuzz(int n) {
	vector<string> result;
	if (n < 1) return result;
	for (int i = 1; i <= n; i++) {
		string a = "";
		if (i % 3 == 0) {
			a += "Fizz";
		}
		if (i % 5 == 0) {
			a += "Buzz";
		}
		if (a == "") {
			a = to_string(i);
		}
		result.push_back(a);
	}
	return result;
}