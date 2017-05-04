#include "./stdc++.h"
using namespace std;

/*
beats 0.48
*/

void print_multiset(multiset<int> v) {
	for (multiset<int>::iterator i = v.begin(); i != v.end(); i++) {
		cout << *i << ", ";
	}
	cout << endl;
}

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1 || nums.size() <= 0) {
        	return nums;
        }
        std::vector<int> ret;
        if (k == 2) {
        	for (int i = 0; i <= nums.size() - 2; i ++) {
        		ret.push_back(nums[i] > nums[i + 1] ? nums[i] : nums[i + 1]);
        	}
        	return ret;
        }
        multiset<int> window(nums.begin(), nums.begin() + k);
        ret.push_back(*next(window.begin(), k - 1));
        for (int i = 1; i <= nums.size() - k; i++) {
        	window.erase(window.lower_bound(nums[i - 1]));
        	window.insert(nums[i + k - 1]);
        	ret.push_back(*next(window.begin(), k - 1));
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

int main() {
	Solution  *s = new Solution();
	int nums[] = {1,3,-1,-3,5,3,6,7};
	std::vector<int> v(nums, nums + 8);
	std::vector<int> v2 = s->maxSlidingWindow(v, 3);
	print_vector(v2);
	return 0;
}