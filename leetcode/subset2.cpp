#include "./stdc++.h"

using namespace std;

void print_vv(vector<vector<int> > &v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << ", ";
		}
		cout << endl;
	}
	cout << endl;
}

class Solution {
public:
	void subsetsWithDup(int total, vector<int>& nums, vector<vector<int> > &ret, int *t, int ti, int s, int e, int m) {
        // cout << "s: " << s << " e: " << e << " ti: " << ti << " m: " << m << endl;

        if(s > e || m <= 0) {
        	if (ti == total) {
        		ret.push_back(vector<int>(t, t + ti));
        	}
        	return;
        }
        int tmp = ti;
        t[ti++] = nums[s];
        subsetsWithDup(total, nums, ret, t, ti, s + 1, e, m - 1);
        ti = tmp;
        s++;
        while (nums[s] == nums[s - 1]) s++;
        subsetsWithDup(total, nums, ret, t, ti, s, e, m);
    }
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ret(1, vector<int>());
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= nums.size(); i++) {
        	// cout << i << endl;
    		int t[i];
    		subsetsWithDup(i, nums, ret, t, 0, 0, nums.size() - 1, i);
        }
        return ret;
    }
};

int main() {
	int a[] = {1,2,3,4,4};
	vector<int> v(a, a + 5);
	Solution *s = new Solution();
	vector<vector<int> > ret = s->subsetsWithDup(v);
	print_vv(ret);
	return 0;
}