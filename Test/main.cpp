#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int steps = 0;
	int nArray = 0;
	cin >> nArray;
	int* tree = new int[nArray];
	int* tags = new int[nArray];
	//find root nodes
	vector<int> root;
	for (int i = 0; i < nArray; i++) {
		cin >> tree[i];
		tags[i] = -1;
		if (tree[i] == i + 1) root.push_back(i + 1);
	}
	bool hasRoot = true;
	if (root.empty())
		hasRoot = false;
	else
		//fix multi-root problem
		for (int i = 1; i < root.size(); i++) {
			tree[root[i] - 1] = root[0];
			steps++;
		}
	//fix circle problem
	for (int i = 0; i < nArray; i++) {
		if (tags[i] == -1 && (!hasRoot || i != root[0] - 1)) {
			int cur = i;
			tags[cur] = i;
			while (true) {
				int temp = tree[cur] - 1;
				if (tags[temp] == i) {
					//find a circle
					if (!hasRoot) {
						root.push_back(cur + 1);
						hasRoot = true;
					}
					tree[cur] = root[0];
					steps++;
					break;
				}
				else if (tags[temp] != -1) break;
				else if (hasRoot && temp == root[0] - 1) break;
				cur = temp;
				tags[cur] = i;
			}
		}
	}
	//output
	cout << steps << endl;
	for (int i = 0; i < nArray; i++) {
		cout << tree[i] << ' ';
	}
}