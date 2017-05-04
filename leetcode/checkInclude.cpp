#include "./stdc++.h"

using namespace std;

void print_v(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i])
            cout << "(" << ((char) (i + 'a')) << ", " << v[i] << ")" << ", ";
    }
    cout << endl;
}

class Solution {
public:
    bool check(string t, vector<int> &v) {
        for (int i = 0; i < t.length(); i++) {
            v[((int) t[i] - 'a') % 26]--;
        }
        return check2(v);
    }
    bool check2(vector<int> &v) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.length() <= 0) return true;
        if (s1.length() > s2.length()) return false;
        string t(1, s1[0]);
        vector<int> pos;
        for (int i = 0; i < s2.length(); i++) {
            if (s2[i] == s1[0])
                pos.push_back(i);
        }
        int cm[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            cm[((int) s1[i] - 'a') % 26]++;
        }
        int len = s1.length();
        for (int i = 0; i < pos.size(); i++) {
            int j = pos[i] + 1 - len;
            bool flag = false;
            vector<int> v(cm, cm + 26);
            for (; j <= pos[i]; j++) {
                if (j >= 0 && (len - 1 + j) <= ((int) s2.length() - 1)) {
                    if (!flag) {
                        if (check(s2.substr(j, len), v))
                            return true;
                        flag = true;
                    } else {
                        v[((int) s2[j - 1] - 'a') % 26]++;
                        v[((int) s2[len - 1 + j] - 'a') % 26]--;
                        if (check2(v))
                            return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
	Solution *s = new Solution();
    cout << s->checkInclusion("ab", "eidbaooo") << endl;
    cout << s->checkInclusion("ab", "ab") << endl;
    cout << s->checkInclusion("ab", "acbc") << endl;
	cout << s->checkInclusion("osmzg", "diyhaywtgpzosgmuxvidndouo") << endl;
	return 0;
}