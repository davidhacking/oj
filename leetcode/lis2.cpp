/*
其实我也想到了，
dp维护到第i个元素位置最长的递增序列
对于这个元素
首先二分搜索可以插入的位置，然后插入，可能出现的情况就是插入的直接替换了原来的，如果不是最后一个元素的话，这
并没有关系，因为这不影响元素个数，如果刚好替换的是最后一个，这其实是我们想要的，因为这样让最后一个元素变小了，
分析一下就会知道最后一个元素一定是递增序列最大的，但是如果太大之后的元素就不容易插入
*/

#include "./stdc++.h"

using namespace std;

class Solution {
public:
	void print_v(std::vector<int>& v) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ", ";
		}
		cout << endl;
	}
	int bin_search(vector<int> &v, int fromIndex, int toIndex, int key) {
		if (v.size() <= 0) {
			return -1;
		}

		int low = fromIndex;
        int high = toIndex;

        while (low <= high) {
            int mid = (low + high) >> 1;
            int midVal = v[mid];

            if (midVal < key)
                low = mid + 1;
            else if (midVal > key)
                high = mid - 1;
            else
                return mid; // key found
        }
        return -(low + 1);  // key not found.
	}
    int lengthOfLIS(vector<int>& nums) {

    	std::vector<int> v;
    	for (int i = 0; i < nums.size(); i++) {
    		int b = bin_search(v, 0, (int) v.size() - 1, nums[i]);
    		if (b < 0) b = -(b + 1);
    		if (b > ((int)v.size() - 1)) {
    			v.push_back(nums[i]);
    		} else {
    			v[b] = nums[i];
    		}
    	}
    	return v.size();
    }
};

int main() {
	Solution *s = new Solution();
	int x[6] = {10,9,2,5,3,4};
	vector<int> v(x, x+6);
	cout << (s->lengthOfLIS(v)) << endl;
	return 0;
}