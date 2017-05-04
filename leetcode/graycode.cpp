#include "./stdc++.h"

using namespace std;

/*
镜射排列*/

class Solution {
public:
	void append(vector<string> &g, int n, int bc) {
		int t = 1 << n;
		for (int i = 0; i < t/2; i++) {
			g[i][bc] = '0';
		}
		for (int i = t/2; i < t; i++) {
			g[i][bc] = '1';
		}
	}
	void cpString(string &a, string &b, int i, int j) {
		for (int k = i; k <= j; k++) {
			b[k] = a[k];
		}
	}
	void mirror(vector<string> &g, int i, int n) {
		int t = (1 << i) - 1, sum = 1 << (i - 1);
		for (int k = 0; k < sum; k++) {
			cpString(g[k], g[t - k], n - i, n - 1);
		}
	}
	void print_s(vector<string> &g) {
		for (int i = 0; i < g.size(); i++) {
        	cout << g[i] << endl;
        }
        cout << endl;
	}
    vector<int> grayCode(int n) {
    	vector<int> ret;
    	if (n <= 0) {
    		ret.push_back(0);
    		return ret;
    	}
    	int total = 1 << n;
        vector<string> g(total, string(n, '0'));
        for (int i = n; i >= 1; i--) {
        	if (i < n) {
        		mirror(g, n - i + 1, n);
        	}
        	append(g, n - i + 1, i - 1);
        	// print_s(g);
        }
        for (int i = 0; i < g.size(); i++) {
        	// cout << g[i] << endl;
        	bitset<32> b(g[i]);
        	ret.push_back(b.to_ulong());
        }
        return ret;
    }
};

void print_v(vector<int> g) {
	for (int i = 0; i < g.size(); i++) {
    	cout << g[i] << ", ";
    }
    cout << endl;
}

int main() {
	Solution *s = new Solution();
	print_v(s->grayCode(9));
	return 0;
}