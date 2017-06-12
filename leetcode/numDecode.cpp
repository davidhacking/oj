#include "./stdc++.h"

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.length() <= 0) return 0;
        int f0 = 0, f1 = 0;
        if ('0' < s[0] && '9' >= s[0]) {
            f1 = 1;
        }
        for (int i = 1; i < s.length(); i++) {
            int t = f1;
            f1 = 0;
            if ('0' < s[i] && '9' >= s[i] && t > 0) {
                f1 += t;
            }
            int x = s[i - 1] > '0' ? ((s[i - 1] - '0') * 10 + s[i] - '0') : 0;
            if (x > 0 && x <= 26) {
                if (i == 1) {
                    f1 += 1;
                } else {
                    if (f0 > 0) f1 += f0;
                }
            }
            f0 = t;
        }
        return f1;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->numDecodings("01") << endl;
    cout << s->numDecodings("12") << endl;
    cout << s->numDecodings("123") << endl;
    return 0;
}