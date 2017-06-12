#include "./stdc++.h"
using namespace std;
class Solution {
public:
	int numTrees(int n, map<int, int> &m) {
        if (m.count(n) > 0) return m[n];
        int ret = 0;
        for (int i = 1; i <= n; i++) {
        	if (i == 1) ret += numTrees(n - 1, m);
        	else if (i == n) ret += numTrees(n - 1, m);
        	else ret += numTrees(i - 1, m) * numTrees(n - i, m);
        }
        return m[n] = ret;
    }
    int numTrees(int n) {
        map<int, int> m;
        m[1] = 1;
        return numTrees(n, m);
    }
};

int main() {
	Solution *s = new Solution();
	cout << s->numTrees(3) << endl;
	return 0;
}