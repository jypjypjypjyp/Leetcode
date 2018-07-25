#include "main.h"

vector<string> generateParenthesis(int n) {
	vector<string> result;
	if (n <= 0) return result;
	stack<bool, vector<bool>> sta(vector<bool>(n, true));
	string curS(n,'(');
	int nOfTrue = n;
	while (!sta.empty()) {
		if (nOfTrue == n) {
			while (sta.size() < 2 * n) {
				sta.push(false);
				curS += ')';
			}
		}
		else {
			nOfTrue++;
			sta.push(true);
			curS += '(';
		}
		if (sta.size() == 2 * n) {
			result.push_back(curS);
			//»ØËÝ
			while (!sta.empty()) {
				if (sta.top()&&2*nOfTrue-2>=sta.size()) {
					sta.pop();
					sta.push(false);
					*(curS.end() - 1) = ')';
					nOfTrue--;
					break;
				}
				else {
					if (sta.top()) nOfTrue--;
					sta.pop();
					curS.erase(curS.end() - 1);
				}
			}
		}
	}
	return result;
}