#include "./stdc++.h"

using namespace std;

void print_v(vector<int> &ret) {
	copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;
}

class Solution {
public:
	// merge
	void merge(vector<int>& nums, vector<int>& index, vector<int>& t, vector<int> &ret,
    		int start, int mid, int end) {		
		int k = start, j = mid + 1;
		// print_v(t);
		int count = 0;
		for (int i = start; i <= mid; i++, k++) {
			while (j <= end && nums[t[i]] > nums[t[j]]) {
				index[k++] = t[j++];
				count++;
			}
			ret[t[i]] += count;
			index[k] = t[i];
		}
		
		for (int i = k; i <= end; i++) {
			index[i] = t[i];
		}
	}
	// split
    void countWithMergeSort(vector<int>& nums, vector<int>& index, vector<int>& t, vector<int> &ret,
    		int start, int end) {
        if (start >= end) return;
        int mid = start + (end - start) / 2;
        countWithMergeSort(nums, t, index, ret, start, mid);
        countWithMergeSort(nums, t, index, ret, mid + 1, end);
        merge(nums, index, t, ret, start, mid, end);
    }
    vector<int> countSmaller(vector<int>& nums) {
    	vector<int> ret(nums.size(), 0), index(nums.size(), 0), t(nums.size(), 0);
    	for (int i = 0; i < nums.size(); i++) {
    		index[i] = i;
    		t[i] = i;
    	}
    	countWithMergeSort(nums, index, t, ret, 0, nums.size() - 1);
    	// print_v(index);
        return ret;
    }
};

int main() {
	int a[] = {5, 2, 6, 1};
	vector<int> v(a, a+4);
	Solution *s = new Solution();
	vector<int> ret = s->countSmaller(v);
	print_v(ret);
	return 0;
}