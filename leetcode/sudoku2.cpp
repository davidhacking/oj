#include "./stdc++.h"

using namespace std;

void print_vs(vector<vector<char> > b) {
	for (int i = 0; i < b.size(); i++) {
		string t(b[i].begin(), b[i].end());
		cout << t << ", " << endl;
	}
	cout << endl;
}

class Solution {
public:
	bool check(vector<vector<char> >& b, char t, int i, int j) {
		for (int k = 0; k < 9; k++) {
			if (b[i][k] == t) return false;
			if (b[k][j] == t) return false;
		}
		return true;
	}
	bool isValidSudoku(vector<vector<char> >& b, vector<vector<bool> > &m, int i, int j) {
		while (b[i][j] != '.') {
			if (j < 8) {
				j++;
			} else if (i < 8) {
				j = 0;
				i++;
			} else {
				// cout << "from while" << endl;
				return true;
			}
		}
		//if (m[(i / 3) * 3 + j / 3].size() <= 0) return false;
		for (int k = 0; k < 9; k++) {
			if (m[(i / 3) * 3 + j / 3][k]) continue;
			char t = '1' + k;
			if (check(b, t, i, j)) {
				b[i][j] = t;
				m[(i / 3) * 3 + j / 3][k] = true;
				int ti = i, tj = j;
				if (tj < 8) {
					tj++;
				} else if (ti < 8) {
					tj = 0;
					ti++;
				} else {
					// cout << "from for 1" << endl;
					// print_vs(b);
					return true;
				}
				bool f = isValidSudoku(b, m, ti, tj);
				if (!f) {
					m[(i / 3) * 3 + j / 3][k] = false;
					b[i][j] = '.';
				} else {
					// cout << "from for 2" << endl;
					return true;
				}
			}
		}
		// cout << "from for 3" << endl;
		return false;
	}
    void solveSudoku(vector<vector<char> >& board) {
        vector<vector<bool> > m(9, vector<bool>(9, false));
        for (int i = 0; i < 9; i++) {
        	for (int j = 0; j < 9; j++) {
        		if (board[i][j] != '.') {
        			m[(i / 3) * 3 + j / 3][board[i][j] - '1'] = true;
        		}
        	}
        }
        isValidSudoku(board, m, 0, 0);
    }
};

int main() {

	string s0 = "..9748...";
	string s1 = "7........";
	string s2 = ".2.1.9...";
	string s3 = "..7...24.";
	string s4 = ".64.1.59."; 
	string s5 = ".98...3..";
	string s6 = "...8.3.2.";
	string s7 = "........6";
	string s8 = "...2759..";

	vector<vector<char> > b;
	b.push_back(vector<char>(s0.begin(), s0.end()));
	b.push_back(vector<char>(s1.begin(), s1.end()));
	b.push_back(vector<char>(s2.begin(), s2.end()));
	b.push_back(vector<char>(s3.begin(), s3.end()));
	b.push_back(vector<char>(s4.begin(), s4.end()));
	b.push_back(vector<char>(s5.begin(), s5.end()));
	b.push_back(vector<char>(s6.begin(), s6.end()));
	b.push_back(vector<char>(s7.begin(), s7.end()));
	b.push_back(vector<char>(s8.begin(), s8.end()));

	Solution *s = new Solution();
	s->solveSudoku(b);
	return 0;
}