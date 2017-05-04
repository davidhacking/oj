#include "./stdc++.h"

using namespace std;

class Solution {
public:
    bool consist(char a, char b) {
        //cout << a << ", " << b << endl;
        return (((a - 'a' + 1) % 26) == ((b - 'a') % 26));
    }
    int findSubstringInWraproundString(string p) {
        if (p.size() <= 0) 
            return 0;
        if (p.size() == 1) 
            return 1;
        vector<int> dp(p.size(), 1);
        vector<bool> f(26, false);
        f[p[0]] = true;
        for (int i = 1; i < p.size(); i++) {
            dp[i] = dp[i - 1];
            if (!f[p[i]]) {
                f[p[i]] = true;
                dp[i]++;
                for (int j = i - 1; j >= 0 && consist(p[j], p[j + 1]); j--) {
                    dp[i]++;
                }
            }
        }
        return dp[p.size() - 1];
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->findSubstringInWraproundString("zab") << endl;
    return 0;
}