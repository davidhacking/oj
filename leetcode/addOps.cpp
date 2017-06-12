#include "./stdc++.h"

using namespace std;
/*
题目说的是一个字符串然后在这些数字中间加上加减乘使得等于目标数字
*/
void print_c(vector<char> &op) {
	copy(op.begin(), op.end(), ostream_iterator<char>(cout, ", "));
	cout << endl;
}

class Solution {
public:
	long long targetNum;
	vector<string> ret;
	string pnum;
    void parseExp(vector<char> &op) {
        string t;
        int i = 0;
        for (; i < op.size(); i++) {
            t.push_back(pnum[i]);
            if (op[i] != 'x') t.push_back(op[i]); 
        }
        t.push_back(pnum[i]);
        cout << "\"" << t << "\"," << endl;
        ret.push_back(t);
    }
	void addOps(vector<char> &op, long long left, long long curr, int k) {
        // string t;
        // int i = 0;
        // for (; i < k - 1; i++) {
        //     t.push_back(pnum[i]);
        //     if (op[i] != 'x') t.push_back(op[i]); 
        // }
        // t.push_back(pnum[i]);
        // cout << left << " " << curr  << " " << left + curr << endl;
        // cout << "\"" << t << "\"," << endl;
        // getchar();
		if (k >= pnum.size()) {
			if ((left + curr) == targetNum) {
                cout << left << " " << curr  << " " << left + curr << endl;
                parseExp(op);
                // print_c(op);
            }
			return;
		}
        long long n = 0;
		for (int i = k; i < pnum.size(); i++) {
            n = n * 10 + pnum[i] - '0';
            // 不加符号
            // addOps(op, left, curr * 10 + pnum[i] - '0', i + 1);
        	op[k - 1] = '+';// 这里使用的是k作为index
        	addOps(op, left + curr, n, i + 1);
        	op[k - 1] = '-';
        	addOps(op, left + curr, -n, i + 1);
        	op[k - 1] = '*';
        	addOps(op, left, curr * n, i + 1);
        	op[k - 1] = 'x';
            if (pnum[i] == '0') break;
        }
	}
    vector<string> addOperators(string num, int target) {
    	targetNum = target;
    	pnum = num;
    	ret.clear();
        if (num.length() <= 0) return ret;
        vector<char> op(num.size() - 1, 'x');
        long long n = 0;
        for (int i = 0; i < pnum.size(); i++) {
            n = n * 10 + pnum[i] - '0';
            addOps(op, 0, n, i + 1);
            if (n == 0) break;
        }
        return ret;
    }
};

int main() {
    // freopen("/Users/david/myFile/OJ/leetcode/output_data", "w", stdout);
	Solution *s = new Solution();
 //    s->addOperators("232", 8);
 //    s->addOperators("00", 0);
	// s->addOperators("105", 5);
    // s->addOperators("123456789", 45);
    // s->addOperators("1234", 10);
    /*
"2147483648"
-2147483648
    */
    s->addOperators("2147483648", -2147483648);
	return 0;
}