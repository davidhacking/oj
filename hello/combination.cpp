#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
效率非常低
*/
static vector< vector<int> > get_combination_index(int n, int m) {
	
	vector< vector<int> > ret;
	if (n <= 0 || m <= 0 || m > n) {
		return ret;
	}
	if (n == m) {
		vector<int> tmp;
		for (int i = 0; i < n; i++) {
			tmp.push_back(i);
		}
		ret.push_back(tmp);
		return ret;
	}

	vector<bool> v(n);
	fill(v.end() - m, v.end(), true);
	do {
		vector<int> tmp;
		for (int i = 0; i < n; ++i) {
			if (v[i]) {
				tmp.push_back(i);
			}
		}
		ret.push_back(tmp);
	} while (next_permutation(v.begin(), v.end()));
	return ret;
}

int main() {
	vector< vector<int> > ret = get_combination_index(16, 8);
	for (int i = 0; i < ret.size(); i++) {
		vector<int> tmp = ret[i];
		for (int j = 0; j < tmp.size(); j++) {
			cout << tmp[j] << ", ";
		}
		cout << endl;
	}
	return 0;
}