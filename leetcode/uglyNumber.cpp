#include "./stdc++.h"

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> k(primes.size(), 0), u(n, INT_MAX);
        u[0] = 1;
        for (int i = 1; i < n; i++) {
        	for (int j = 0; j < primes.size(); j++) {
        		if (u[i] > u[k[j]] * primes[j]) {
        			u[i] = u[k[j]] * primes[j];
        		}
        	}
        	for (int j = 0; j < primes.size(); j++) {
        		if (u[i] == u[k[j]] * primes[j]) {
        			k[j]++;
        		}
        	}
        }
        // copy(u.begin(), u.end(), ostream_iterator<int>(cout, ", "));
        // cout << endl;
        return u[n - 1];
    }
};

int main() {
	int a[] = {2, 7, 13, 19};
	std::vector<int> v(a, a + 4);
	Solution *s = new Solution();
	cout << s->nthSuperUglyNumber(12, v) << endl;
}