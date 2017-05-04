#include "./stdc++.h"
using namespace std;

class Solution {
public:
	// 超时 18 79, 包含太多的已计算的问题
	bool canIWin(vector<bool> &v, int desiredTotal) {
		// cout << "desiredTotal: " << desiredTotal << endl;
		// copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
		// cout << endl;
		int max = 0;
		for (int i = v.size() - 1; i >= 0; i--) {
			if (!v[i]) {
				max = i + 1;
			}
		}
		if (max >= desiredTotal) {
			return true;
		}
        for (int i = v.size() - 1; i >= 0; i--) {
        	if (!v[i]) {
        		v[i] = true;
        		if ((desiredTotal - i - 1) <= 0) {
        			v[i] = false;
        			return true;
        		}
        		int j = 0;
        		for (; j < v.size(); j++) {
        			if (!v[j]) {
        				v[j] = true;
        				if ((desiredTotal - i - j - 2) <= 0) {
        					v[j] = false;
        					break;
        				}
        				max = 0;
						for (int k = v.size() - 1; k >= 0; k--) {
							if (!v[k]) {
								max = k + 1;
							}
						}
						bool ij = false;
						if (max >= desiredTotal) {
							ij = true;
						} else if (2 * max > desiredTotal) {
							ij = false;
						} else {
							ij = canIWin(v, desiredTotal - i - j - 2);
						}
        				if (!ij) {
        					v[j] = false;
        					break;
        				}
        				v[j] = false;
        			}
        		}
        		if (j == v.size()) {
        			v[i] = false;
        			return true;
        		}
        		v[i] = false;
        	}
        }
        return false;
    }
    bool canIWin2(int maxChoosableInteger, int desiredTotal) {
    	if (maxChoosableInteger >= desiredTotal) 
    		return true;
    	else if (2 * maxChoosableInteger > desiredTotal)
    		return false;
    	vector<bool> v(maxChoosableInteger, false);
        return canIWin(v, desiredTotal);
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
    	if (maxChoosableInteger >= desiredTotal) 
    		return true;
    	else if (maxChoosableInteger *( maxChoosableInteger + 1) / 2 < desiredTotal)
    		return false;
    	map<string, bool> m;
    	string s(maxChoosableInteger, '0');
        return canIWin(m, s, desiredTotal);
    }
    bool canIWin(map<string, bool> &m, string &s, int desiredTotal) {
    	if (desiredTotal <= 0) return false;
    	if (m.count(s) <= 0) {
    		for (int i = 0; i < s.length(); i++) {
    			if (s[i] == '0') {
    				s[i] = '1';
					if (!canIWin(m, s, desiredTotal - i - 1)) {
						m[s] = false;
						s[i] = '0';
						return true;
					}
					m[s] = true;
    				s[i] = '0';
    			}
    		}
    		m[s] = false;
    	}
    	return m[s];
    }
};

int main() {
	Solution *s = new Solution();
	cout << s->canIWin(10, 11) << endl; // false
	cout << s->canIWin(10, 20) << endl; // true
	cout << s->canIWin(4, 8) << endl; // true
	cout << s->canIWin(4, 6) << endl; // true
	cout << s->canIWin(18, 79) << endl; // true
	cout << s->canIWin(10, 40) << endl; // false
	return 0;
}