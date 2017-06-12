#include "./stdc++.h"

using namespace std;

class Solution {
public:
    int m, n;
    bool exist(vector<vector<char> >& b, int i, int j, string &w, int wi) {
    	// cout << i << ", " << j << endl;
        if (wi == ((int) w.length())) return true;
        // up
        if ((i - 1) >= 0 && b[i - 1][j] == w[wi]) {
            b[i - 1][j] = 0xff;
            bool f = exist(b, i - 1, j, w, wi + 1);
            b[i - 1][j] = w[wi];
            if (f) return true;
        }
        // right
        if ((j + 1) <= (n - 1) && b[i][j + 1] == w[wi]) {
            b[i][j + 1] = 0xff;
            bool f = exist(b, i, j + 1, w, wi + 1);
            b[i][j + 1] = w[wi];
            if (f) return true;
        }
        // down
        if ((i + 1) <= (m - 1) && b[i + 1][j] == w[wi]) {
            b[i + 1][j] = 0xff;
            bool f = exist(b, i + 1, j, w, wi + 1);
            b[i + 1][j] = w[wi];
            if (f) return true;
        }
        // left
        if ((j - 1) >= 0 && b[i][j - 1] == w[wi]) {
            b[i][j - 1] = 0xff;
            bool f = exist(b, i, j - 1, w, wi + 1);
            b[i][j - 1] = w[wi];
            if (f) return true;
        }
        return false;
    }
    bool exist(vector<vector<char> >& board, string word) {
        if (word == "" || board.size() <= 0) return false;
        m = board.size(); n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    board[i][j] = 0xff;
                    bool f = exist(board, i, j, word, 1);
                    if (f) {
                        board[i][j] = word[0];
                        return true;
                    }
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
};

int main() {
	vector<vector<char> > b;
	string s1 = "ABCE";
	b.push_back(vector<char>(s1.begin(), s1.end()));
	string s2 = "SFCS";
	b.push_back(vector<char>(s2.begin(), s2.end()));
	string s3 = "ADEE";
	b.push_back(vector<char>(s3.begin(), s3.end()));
	Solution *s = new Solution();
	cout << s->exist(b, "ABCCED") << endl;
	return 0;
}