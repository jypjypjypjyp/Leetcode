#include"main.h"

void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	double x = (n - 1) / 2.0;
	double y = x;
	for (int i = 1; i < n; i++) {
		for (double j = (n % 2 == 0) ? 0.5 : 0; j < i; j++) {
			if (x + j < n&&y + i - j < n) {
				int &a = matrix[(int)(x + j)][(int)(y + i - j)],
					&b = matrix[(int)(x - i + j)][(int)(y + j)],
					&c = matrix[(int)(x - j)][(int)(y - i + j)],
					&d = matrix[(int)(x + i - j)][(int)(y - j)];
				int temp = a;
				a = b;
				b = c;
				c = d;
				d = temp;
			}
		}
	}
}