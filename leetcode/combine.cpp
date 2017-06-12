#include "stdc++.h"
using namespace std;

class Solution {
public:
    void combine(vector<vector<int> > &ret, vector<int> &v, vector<int> &nl, int s, int k) {
        v.push_back(nl[s]);
        k--;
        if (k == 0) {
            ret.push_back(v);
        } else {
            for (int i = s + 1; i < nl.size(); i++) {
                v.push_back(nl[i]);
                k--;
                if (k == 0) {
                    ret.push_back(v);
                } else if (i + 1 < nl.size()) {
                    combine(ret, v, nl, i + 1, k);
                }
                v.pop_back();
                k++;
            }
        }
        v.pop_back();
        k++;
        if (s + 1 < nl.size() && k > 0) {
            combine(ret, v, nl, s + 1, k);
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<int> nl(n, 0);
        for (int i = 1; i <= n; i++) {
            nl[i - 1] = i;
        }
        vector<vector<int> > ret;
        if (k == 0) return ret;
        if (k >= n) {
            ret.push_back(nl);
            return ret;
        }
        vector<int> v;
        combine(ret, v, nl, 0, k);
        return ret;
    }
};

void print_vv(vector<vector<int> > &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    Solution *s = new Solution();
    vector<vector<int> > v = s->combine(4, 3);
    print_vv(v);
    return 0;
}