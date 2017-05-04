/*
480
3.31 10:00
*/
// #include <bits/stdc++.h>
#include "./stdc++.h"

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    	vector<double> ret;
        if (nums.size() <= 0 || k <= 0) {
        	return ret;
        }
        int fi = nums[0];
        double fk = 0.0;
        for (int i = 0; i < k; i++) {
        	fk += nums[i];
        }
        fk /= k;
        ret.push_back(fk);
        for (int i = 1; i <= nums.size() - k; i++) {
        	fi = nums[i];
        	fk = fk * k - fi + nums[i + k - 1];
        	fk /= k;
        	ret.push_back(fk);
        }
        return ret;
    }
};

template<typename T> void print_vector(std::vector<T> _v) {
	for (int i = 0; i < _v.size(); i++) {
		cout << _v[i] << ", ";
	}
	cout << endl;
}

int main () {
	Solution *s = new Solution();
	int a[] = {1,3,-1,-3,5,3,6,7};
	vector<int> nums(a, a + 8);
	print_vector(nums);
	vector<double> ret = s->medianSlidingWindow(nums, 3);
	print_vector(ret);
	return 0;
}
