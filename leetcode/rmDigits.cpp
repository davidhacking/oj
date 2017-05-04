#include "./stdc++.h"

using namespace std;

/*
https://leetcode.com/problems/remove-k-digits/#/description
解法每次将增大序列的最值删除
*/

class Solution {
public:
	string rmLeadingZero(string num) {
		// remove leading zero
        int i = 0;
        for (; i < num.size(); i++) {
        	if (num[i] != '0') {
        		break;
        	}
        }
        if (i == num.size()) {
        	return "0";
        }
        return num.substr(i, num.size());
	}
	int findMaxIncrese(string num) {
		int tmp = num[0], i = 1;
		for (; i < num.size(); i++) {
			if (num[i] - tmp < 0) {
				return i - 1;
			}
			tmp = num[i];
		}
		if (i == num.size()) {
			return num.size() - 1;
		}
		return 0;
	}
    string removeKdigits(string num, int k) {
    	if (k == 0) {
    		return num;
    	}
        if (num.length() == k) {
        	return "0";
        }

        for (int x = 0; x < k; x++) {
        	int i = findMaxIncrese(num);
        	// cout << "i: " << i << endl;
        	num = num.substr(0, i) + num.substr(i + 1, num.size());
        	num = rmLeadingZero(num);
        }
        return num; 
    }
};

int main () {
	// num = "1432219", k = 3
	Solution *s = new Solution();
	cout << ((s->removeKdigits("112", 1)) == "11") << endl; // 11
	cout << ((s->removeKdigits("10", 1)) == "0") << endl; // 0
	cout << ((s->removeKdigits("1432219", 3)) == "1219") << endl;
	cout << ((s->removeKdigits("10200", 1)) == "200") << endl;
	cout << ((s->removeKdigits("000", 1)) == "0") << endl;
	// num = "10200", k = 1
	// num = "10", k = 2
	// num = "000", k = 1
}