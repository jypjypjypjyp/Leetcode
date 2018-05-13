#include"main.h"

vector<int> PlusOne(vector<int>& digits) {
	vector<int> result(digits.size()); 
	vector<int>::iterator i = digits.end() - 1;
	vector<int>::iterator j = result.end() - 1;
	*j = 1;
	while (i>digits.begin()) {
		*j += *i;
		if (*j >= 10) {
			*(j - 1) = 1;
			*j = 0;
		}
		i--; j--;
	}
	*j += *i;
	if (*j >= 10) {
		*j = 0;
		result.insert(j, 1);
	}
	return result;
}