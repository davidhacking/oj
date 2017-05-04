#include "./stdc++.h"

using namespace std;

void print_v(vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
}

class Solution {
public:
	int ret;
	void permutate(vector<int> &v, int s) {
		if (s == v.size()) {
			ret++;
			return;
		}
		for (int i = s; i < v.size(); i++) {
			// this is for array with duplicate value
			// if (i == s || v[i] != v[s]) {
			/*
			i thank the condition is 
			i == s || ((v[s] % (i + 1) == 0 || (i + 1) % v[s] == 0) && (v[i] % (s + 1) == 0 || (s + 1) % v[i] == 0))
			but it is v[i] % (s + 1) == 0 || (s + 1) % v[i] == 0
			cause you just gurrantee that it may be can swap is enough, let next loop to judge it 
			*/
			if (v[i] % (s + 1) == 0 || (s + 1) % v[i] == 0) {
				swap(v[i], v[s]);
				permutate(v, s + 1);
				swap(v[i], v[s]);
			}
		}
	}
    int countArrangement(int N) {
        vector<int> v(N, 0);
        ret = 0;
        for (int i = 1; i <= N; i++) {
        	v[i - 1] = i;
        }
        // v.push_back(1);
        // sort(v.begin(), v.end());

        permutate(v, 0);
        return ret;
    }
};

int main() {
	Solution *s = new Solution();
	cout << s->countArrangement(6) << endl;
	return 0;
}