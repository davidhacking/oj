#include "./stdc++.h"

using namespace std;

/*
 Time Limit Exceeded 
*/

class NumArray {
public:
	vector<int> sum;
	vector<int> nums;
	// index, update value
	map<int, int> um;

    NumArray(vector<int> nums) {
    	this->nums = nums;
    	if (nums.size() <= 0) {
    		return;
    	}
    	sum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
        	sum.push_back(sum[i - 1] + nums[i]);
        }
    }
    
    void update(int i, int val) {
        um[i] = val;
    }
    
    int sumRange(int i, int j) {
        int ret = 0;
        if (i == j) {
        	ret = nums[i];
        	if (um.count(i)) {
        		ret = um[i];
        	}
        	return ret;
        }
        ret = sum[j] - sum[i] + nums[i];
        for (map<int, int>::iterator iter = um.begin(); iter != um.end(); iter++) {
        	if (iter->first >= i && iter->first <= j) {
        		ret -= nums[iter->first];
        		ret += iter->second;
        	}
        }
        return ret;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

int main() {
	/*
	Given nums = [1, 3, 5]
	sumRange(0, 2) -> 9
	update(1, 2)
	sumRange(0, 2) -> 8
	*/
	int a[] = {0};
	vector<int> nums(a, a + 3);
	NumArray *obj = new NumArray(nums);
	cout << obj->sumRange(0, 2) << endl;
	obj->update(1, 2);
	cout << obj->sumRange(0, 2) << endl;
	return 0;
}