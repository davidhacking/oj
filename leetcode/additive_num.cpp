#include "./stdc++.h"

using namespace std;

/*
https://leetcode.com/problems/additive-number/#/description
使用i j两个指针将字符串分割成三份，分别check就行了，对于第三个字符串采用递归check
*/

string addNumber(string a, string b) {
	int i = a.size() - 1, j = b.size() - 1, carry = 0;
	string ret;
	while (i >= 0 || j >= 0) {
		int t = carry + ((i >= 0) ? a[i--] - '0' : 0) + ((j >= 0) ? b[j--] - '0' : 0);
		ret.push_back(t % 10 + '0');
		carry = t / 10;
	}
	if (carry) {
		ret.push_back(carry + '0');
	}
	reverse(ret.begin(), ret.end());
	if (ret == "0") {
		return ret;
	}
	int k = 0;
	for (; k < ret.size(); k++) {
		if (ret[k] != '0') {
			break;
		}
	}
	ret = ret.substr(k, ret.size() - k);
	return ret;
}

bool check(string a, string b, string sum) {
	if (a.size() <= 0 || b.size() <= 0) {
		return false;
	}
	if ((a.size() > 1 && a[0] == '0') || (b.size() > 1 && b[0] == '0')) {
		return false;
	}
	string t = addNumber(a, b);
	if (t.size() > sum.size() || t.compare(sum.substr(0, t.size())) != 0) {
		return false;
	}
	if (t.size() == sum.size()) {
		return true;
	}
	return check(b, t, sum.substr(t.size(), sum.size() - t.size()));
}

class Solution {
public:
	
    bool isAdditiveNumber(string num) {
    	if (num.size() < 3) {
    		return false;
    	}
    	for (int i = 1; i <= num.size() / 2; i++) {
    		for (int j = i + 1; j <= i + (num.size() - i) / 2; j++) {
    			cout << num.substr(0, i) << ", " << num.substr(i, j - i) << ", " << num.substr(j, num.size() - j) << endl;
    			if (check(num.substr(0, i), num.substr(i, j - i), num.substr(j, num.size() - j))) {
    				return true;
    			}
    		}
    	}
        return false;
    }
};

int main() {
	Solution *s = new Solution();
	cout << s->isAdditiveNumber("211738") << endl;
	return 0;
}