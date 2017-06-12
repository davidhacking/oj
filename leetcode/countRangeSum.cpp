#include "./stdc++.h"

using namespace std;

void print_v(vector<long> &s) {
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << ", ";
	}
	cout << endl;
}

class Solution {
public:
	long lo, up;
	void copyArray(vector<long> &s, vector<long> &d, int start) {
		int k = start;
		for (int i = 0; i < s.size(); i++) {
			d[k++] = s[i];
		}
	}
	int merge(vector<long> &sum, int start, int mid, int end) {
		int i = start, j = mid + 1, k = 0, count = 0, x, y;
		vector<long> s(sum.begin() + start, sum.begin() + end + 1);
		// for (int z = start; z <= end; z++) s.push_back(sum[z]);
		x = y = j;
		for (; i <= mid; i++, k++) {
			while (x <= end && (sum[x] - sum[i]) < lo) x++;
			while (y <= end && (sum[y] - sum[i]) <= up) y++;
			count += y - x;
			while (j <= end && (sum[i] > sum[j])) s[k++] = sum[j++];
			s[k] = sum[i];
		}
		copyArray(s, sum, start);
		return count;
	}
	int split(vector<long> &sum, int start, int end) {
		if (start >= end) return 0;
		int count = 0, mid = start + (end - start) / 2;
		count += split(sum, start, mid);
		count += split(sum, mid + 1, end);
		count += merge(sum, start, mid, end);
		return count;
	}
    int countRangeSum(vector<int>& nums, int lower, int upper) {
    	lo = lower;
    	up = upper;
        vector<long> sum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
        	sum[i + 1] = sum[i] + nums[i];
        }
        return split(sum, 0, sum.size() - 1);
    }
};

int main() {
	int a[] = {-2, 5, -1};
	vector<int> v(a, a+3);
	Solution *s = new Solution();
	cout << s->countRangeSum(v, -2, 2) << endl;
	return 0;
}