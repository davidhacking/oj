#include "./stdc++.h"

using namespace std;

struct Data {
	int i, j, val;
	Data(int i, int j, int v): i(i), j(j), val(v) {}
};

struct Comp {
	bool operator() (Data a, Data b) {
		return a.val > b.val;
	}
};

class Solution {
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
    	int n = matrix.size();
    	if (n <= 0) return 0;
    	if (k == 1) return matrix[0][0];
    	if (k == n) return matrix[n - 1][n - 1];
        priority_queue<Data, vector<Data>, Comp> pq;
        for (int i = 0; i < n; i++) {
        	pq.push(Data(0, i, matrix[0][i]));
        }
        for (int i = 0; i < k - 1; i++) {
        	Data t = pq.top();
        	// cout << t.val << endl;
        	pq.pop();
        	if (t.i == (n - 1)) continue;
        	pq.push(Data(t.i + 1, t.j, matrix[t.i + 1][t.j]));
        }
        return pq.top().val;
    }
};

int main() {
	vector<vector<int> > v;
	int a[] = {1,5,9};
    v.push_back(vector<int>(a, a+sizeof(a)/sizeof(a[0])));
    int a1[] = {10,11,13};
    v.push_back(vector<int>(a1, a1+sizeof(a1)/sizeof(a1[0])));
    int a2[] = {12,13,15};
    v.push_back(vector<int>(a2, a2+sizeof(a2)/sizeof(a2[0])));
    Solution *s = new Solution();
    cout << s->kthSmallest(v, 8) << endl;
	return 0;
}