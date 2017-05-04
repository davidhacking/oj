//#include <bits/stdc++.h>
#include "stdc++.h"
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        bool flag = 0;
        int ai = a.size() - 1, bi = b.size() - 1;

        while (ai >= 0 || bi >= 0) {
        	bool af = 0;
        	bool bf = 0;
        	if (ai >= 0 && a[ai] == '1') {
        		af = 1;
        	}
        	if (bi >= 0 && b[bi] == '1') {
        		bf = 1;
        	}
        	if (af && bf && flag) {
        		ret.insert(0, "1");
        		flag = 1;
        	} else if ((af && bf) || (af && flag) || (bf && flag)) {
        		ret.insert(0, "0");
        		flag = 1;
        	} else if (af || bf || flag) {
        		ret.insert(0, "1");
        		flag = 0;
        	} else {
        		ret.insert(0, "0");
        		flag = 0;
        	}
        	ai--;
        	bi--;
        }
        if (flag) {
        	ret.insert(0, "1");
        }
        return ret;
    }
};
int main() {
	Solution *s = new Solution();
	cout << s->addBinary("100", "1000") << endl;
	return 0;
}