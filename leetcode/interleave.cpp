#include "./stdc++.h"

using namespace std;

class Solution {
public:
	map<pair<int, pair<int, int> >, bool> m;
    bool isInterleave(string &s1, int i1, string &s2, int i2, string &s3, int i3) {
    	pair<int, pair<int, int> > p(i1, pair<int, int>(i2, i3));
    	if (m.count(p) > 0) {
    		return m[p];
    	}
        if (i1 == s1.length() && i2 == s2.length() && i3 == s3.length()) {
            return true;
        }
        if (i3 == s3.length()) {
        	return false;
        }
        bool f1 = true, f2 = true;
        if (i1 == s1.length()) {
        	f1 = false;
        }
        if (i2 == s2.length()) {
        	f2 = false;
        }
        if (f1 && s1[i1] == s3[i3] && ((f2 && s2[i2] != s3[i3]) || !f2)) {
        	bool b = isInterleave(s1, i1 + 1, s2, i2, s3, i3 + 1);
            return m[p] = b;
        } else if ((!f1 || (f1 && s1[i1] != s3[i3])) && f2 && s2[i2] == s3[i3]) {
            bool b = isInterleave(s1, i1, s2, i2 + 1, s3, i3 + 1);
            return m[p] = b;
        } else if (f1 && s1[i1] == s3[i3] && f2 && s2[i2] == s3[i3]) {
        	bool b = (isInterleave(s1, i1 + 1, s2, i2, s3, i3 + 1) || isInterleave(s1, i1, s2, i2 + 1, s3, i3 + 1));
            return m[p] = b;
        } else {
            return false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
    	m.clear();
        return isInterleave(s1, 0, s2, 0, s3, 0);
    }
};

int main() {
	Solution *s = new Solution();
	cout << s->isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
	cout << s->isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
	cout << s->isInterleave("", "", "") << endl;
	cout << s->isInterleave("", "", "1") << endl;
	cout << s->isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa",
"babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab",
"babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab") << endl;
	return 0;
}