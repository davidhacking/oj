#include "./stdc++.h"

using namespace std;

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