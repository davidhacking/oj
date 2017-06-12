#include "./stdc++.h"
using namespace std;
// 失效函数: 对于ti f(i) = max(k) 0<=k<i t0...tk=t[i-k]...ti or f(i)=-1
// 寻找最长的前缀
vector<int> f(string t) {
    vector<int> kmp(t.length(), -1);
    for (int i = 1; i < t.length(); i++) {
        int x = kmp[i - 1];
        while (x != -1) {
            if (t[x + 1] == t[i]) {
                kmp[i] = x + 1;
                break;
            }
            x = kmp[x];
        }
        if (x == -1 && t[0] == t[i]) {
            kmp[i] = 0;
        }
    }
    return kmp;
}
vector<int> find(string &s, string &t) {
    vector<int> ret;
    int j = 0;
    vector<int> kmp = f(t);
    for (int i = 0; i < s.length(); ) {
        cout << i << ", " << j << endl;
        if (s[i] == t[j]) {
            if (j == (t.length() - 1)) {
                j = 0;
                ret.push_back(i - t.length() + 1);
            } else {
                j++;
            }
            i++;
            continue;
        }
        if (j > 0) {
            j = kmp[j - 1] + 1;
        } else {
            i++;
        }
    }
    return ret;
}
void print_v(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << endl;
}
int main() {
    // test 失效函数
    print_v(f("aaaaaa"));
    print_v(f("abaabcac"));
    // test kmp
    string s = "ABABDABACDABABCABAB";
    string t = "ABABCABAB";
    print_v(f("ABABCABAB")); // -1, -1, 0, 1, -1, 0, 1, 2, 3,
    vector<int> v = find(s, t);
    print_v(v);
    return 0;
}