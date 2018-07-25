#include "main.h"

struct Button {
	int number;//»ùÓÚ2
	int a;
};

vector<vector<char>> map(
	{
		{ 'a','b','c' },
		{ 'd','e','f' },
		{ 'g','h','i' },
		{ 'j','k','l' },
		{ 'm','n','o' },
		{ 'p','q','r','s' },
		{ 't','u','v' },
		{ 'w','x','y','z' }
	}
);

vector<int> map_n(
	{
		3,3,3,3,3,4,3,4
	}
);

int n;

bool step(vector<Button>& btnVec) {
	bool isCarry = true;
	int b = n - 1;
	while (b >= 0 && isCarry) {
		if (btnVec[b].a == map_n[btnVec[b].number] - 1) {
			btnVec[b].a = 0;
			isCarry = true;
		}
		else {
			btnVec[b].a++;
			isCarry = false;
		}
		b--;
	}
	if (b == -1 && isCarry) return false;
	else return true;
}

string output(vector<Button>& btnVec) {
	string result;
	for (auto i : btnVec) {
		result += map[i.number][i.a];
	}
	return result;
}

vector<string> letterCombinations(string digits) {
	vector<string> result;
	n = digits.size();
	if (n == 0)return result;
	vector<Button> btnVec(n);
	int sizeOfAnswer = 1;
	for (int i = 0; i < n; i++) {
		btnVec[i].number = digits[i] - '2';
		sizeOfAnswer *= map_n[btnVec[i].number];
	}
	result.push_back(output(btnVec));
	while (step(btnVec)) {
		result.push_back(output(btnVec));
	}
	return result;
}