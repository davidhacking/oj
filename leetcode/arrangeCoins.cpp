#include "./stdc++.h"

using namespace std;

/*
https://leetcode.com/problems/arranging-coins/#/description
一种方法，N = (x+1)*x/2 x<(2N)^0.5，二分搜索，或者从无穷大搜
第二种方法，精确求解出(int)((-1 + Math.sqrt(1 + 8 * (long)n)) / 2);
*/

class Solution {
public:
    int arrangeCoins(int N) {
        if (N <= 0) return 0;
        int left = 1, right = INT_MAX;
        long long n = N;
        for (long i = left + (right - left) / 2 ; left < right;) {
            long long t = (i + 1) * i / 2;
            if (t < n) {
                left = i;
                i = left + (right - left) / 2;
                continue;
            }
            if (t == n) return i;
            long j = i - 1;
            long long tmp = (j + 1) * j / 2;
            if (t > n && tmp <= n)
                return j;
            else {
                right = i;
                i = left + (right - left) / 2;
            }
        }
        return left;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->arrangeCoins(5) << endl;
    return 0;
}