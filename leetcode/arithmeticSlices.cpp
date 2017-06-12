#include "./stdc++.h"
// #include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/arithmetic-slices/#/description
A sequence of number is called arithmetic 
if it consists of at least three elements 
and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

两两相减，找到连续多少个数相同，再计算等产生多少对
*/

class Solution {
public:
	std::vector<int> v;
	void print_vector(std::vector<int> _v) {
		for (int i = 0; i < _v.size(); i++) {
			cout << _v[i] << ", ";
		}
		cout << endl;
	}
	int compute(int x) {
		return x * (x - 1) / 2;
	}
    int numberOfArithmeticSlices(vector<int>& A) {
    	if (A.size() <= 2) {
    		return 0;
    	}
        vector<int> d;
        for (int i = 0; i < A.size() - 1; i++) {
        	d.push_back(A[i + 1] - A[i]);
        }
        // print_vector(d);
        int i = 0;
        int count = 1;
        while (i <= d.size() - 2) {
        	if (d[i] == d[i + 1]) {
        		count++;
        	} else {
        		if (count > 1) {
	        		v.push_back(count);
	        	}
	        	count = 1;
        	}
        	i++;
        }
        if (count > 1) {
    		v.push_back(count);
    	}
        // print_vector(v);

        int sum = 0;
        for (int j = 0; j < v.size(); j++) {
        	sum += compute(v[j]);
        }
        return sum;
    }
};

/*
3.30 20:11
*/
int main() {
	Solution *s = new Solution();
	int a[] = {1,2,3,4,5,6}; // 1
	vector<int> test(a, a + 6);
	cout << s->numberOfArithmeticSlices(test) << endl;
	return 0;
}