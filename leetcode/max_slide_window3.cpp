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
        vector<int> ret;
        if (k == 1 || nums.size() <= 0) {
            return nums;
        }
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k - 1) {
                ret.push_back(nums[dq.front()]);
            }
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ret.push_back(nums[dq.front()]);
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