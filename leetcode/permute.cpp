#include "./stdc++.h"

using namespace std;


class Solution {
public:
	void getPermutation(vector<vector<int> > &ret, int start, int end, vector<int> nums) {
		if (start == end) {
			ret.push_back(nums);
			return;
		}
		for (int i = start; i <= end; i++) {
			if (nums[i] == nums[start] && i != start) continue;
			swap(nums[i], nums[start]);
			getPermutation(ret, start + 1, end, nums);
		}
	}
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > ret;
        if (nums.size() <= 0) {
        	return ret;
        }
        sort(nums.begin(), nums.end());
        getPermutation(ret, 0, nums.size() - 1, nums);
        return ret;
    }
};

void print_vv(vector<vector<int> > &ret) {
	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j] << ", ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	/*
1,2,3
1,3,2
2,1,3
2,3,1
3,1,2
3,2,1

1,2,3
2,1,3
3,2,1

1,3,2

2,1,3
3,1,2

1,2,3,4
2,1,3,4
3,2,1,4
4,2,3,1
	
	*/
	Solution *s = new Solution();
	int a[] = {3, 2, 3};
	std::vector<int> v(a, a + 3);
	vector<vector<int> > ret = s->permuteUnique(v);
	print_vv(ret);
	return 0;
}