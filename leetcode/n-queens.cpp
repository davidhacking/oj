#include "./stdc++.h"

using namespace std;

void print_v(vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		cout << "(" << i << ", " << v[i] << ")" << ", ";
	}
	cout << endl;
}

void print_s(vector<vector<string> > &v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << ", " << endl;
		cout << endl;
	}
	cout << endl;
}


class Solution {
public:
	// check whether can place v[i] = j i表示行，j表示列
	bool check(vector<int> &v, int i) {
		for (int k = 0; k < i; k++) {
			// 行不用check
			// check列 斜线
			if (v[k] == v[i] || abs(v[k] - v[i]) == abs(k - i)) {
				return false;
			}
		}
		return true;
	}
	// m 行 M 总行数
	void solveNQueens(vector<vector<string> > &ret, vector<int> &v, int m, int M) {
		if (m == M) {
			// print
			// print_v(v);
			vector<string> vs;
			for (int i = 0; i < v.size(); i++) {
				string t(v.size(), '.');
				t[v[i]] = 'Q';
				vs.push_back(t);
			}
			ret.push_back(vs);
			return;
		}
		int i = 0;
		for (; i < M; i++) {
			v[m] = i;
			if (check(v, m)) {
				solveNQueens(ret, v, m + 1, M);
			}
		}
	}
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ret;
        if (n <= 0) return ret;
		vector<int> v(n, -1);
        solveNQueens(ret, v, 0, n);
        return ret;
    }
};

int main() {
	Solution *s = new Solution();
	s->solveNQueens(1);
	s->solveNQueens(2);
	s->solveNQueens(3);
	vector<vector<string> > ret = s->solveNQueens(4);
	print_s(ret);
	s->solveNQueens(5);
	return 0;
}