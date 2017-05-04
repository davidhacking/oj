#include "./stdc++.h"
using namespace std;
class Solution {
public:
	int max, N;
	void getCombine(int total, vector<int>& nums, int *t, int ti, int s, int e, int m) {
        if(s > e || m <= 0) {
        	if (ti == total) {
        		int n = N;
        		int x = 1;
        		for (int i = 0; i < ti; i++) {
        			if (i == 0) 
        				x *= t[i];
        			else
        				x *= t[i] - t[i - 1];
        		}
        		x *= N - t[ti - 1];
        		max = std::max(max, x);
        	}
        	return;
        }
        int tmp = ti;
        t[ti++] = nums[s];
        getCombine(total, nums, t, ti, s + 1, e, m - 1);
        ti = tmp;
        s++;
        while (nums[s] == nums[s - 1]) s++;
        getCombine(total, nums, t, ti, s, e, m);
    }
    int integerBreak(int n) {
        if (n == 2) return 1;
        vector<int> v(n - 1, 0);
        max = 1;
        N = n;
        for (int i = 1; i <= n - 1; i++) {
        	v[i - 1] = i;
        }
        for (int i = 1; i <= n - 1; i++) {
        	// cout << i << endl;
    		int t[i];
    		getCombine(i, v, t, 0, 0, v.size() - 1, i);
        }
        return max;
    }
    /*
    假设分成x个数最大则这些数为n/x, f(n) = (n/x)^x关于x的函数，x等于e时最大e等于2.71828
    */
    int integerBreakx(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int ret = 1;
        while (n > 4) {
            n -= 3;
            ret *= 3;
        }
        ret *= n;
        return ret;
    }
};

int main() {
	Solution *s = new Solution();
	cout << s->integerBreak(11) << endl;
	return 0;
}