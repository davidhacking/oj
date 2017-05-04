#include "./stdc++.h"

using namespace std;

/*
能不用map就不用用数组最快
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        bool flag = false;
        vector<vector<bool> > m(9, vector<bool>(9, false));
        for (int i = 0; i < 9; i++) {
        	map<char, bool> t;
        	for (int j = 0; j < 9; j++) {
        		if (board[i][j] != '.') {
        			if (t.count(board[i][j]) <= 0) {
        				t[board[i][j]] = true;
        			} else {
        				return false;
        			}
        			flag = true;
        			if (m[(i / 3) * 3 + j / 3][board[i][j] - '1']) {
        				return false;
        			}
        			m[(i / 3) * 3 + j / 3][board[i][j] - '1'] = true;
        		}
        	}
        }
        for (int i = 0; i < 9; i++) {
        	map<char, bool> t;
        	for (int j = 0; j < 9; j++) {
        		if (board[j][i] != '.') {
        			if (t.count(board[j][i]) <= 0) {
        				t[board[j][i]] = true;
        			} else {
        				return false;
        			}
        		}
        	}
        }
        return flag;
    }
};

int main() {
	/*
[".87654321","2........","3........","4........","5........","6........","7........","8........","9........"]
["..4...63.",".........","5......9.","...56....","4.3.....1","...7.....","...5.....",".........","........."]
	*/
	// string s0 = "..4...63.";
	// string s1 = ".........";
	// string s2 = "5......9.";
	// string s3 = "...56....";
	// string s4 = "4.3.....1"; 
	// string s5 = "...7.....";
	// string s6 = "...5.....";
	// string s7 = ".........";
	// string s8 = ".........";

	string s0 = ".87654321";
	string s1 = "2........";
	string s2 = "3........";
	string s3 = "4........";
	string s4 = "5........"; 
	string s5 = "6........";
	string s6 = "7........";
	string s7 = "8........";
	string s8 = "9........";


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
	cout << s->isValidSudoku(b) << endl;
	return 0;
}