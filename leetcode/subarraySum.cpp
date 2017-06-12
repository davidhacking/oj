#include "stdc++.h"
using namespace std;

class Solution {
public:
	int ret, _k;
	void merge(vector<int> &sum, vector<int> &t, int a, int mid, int b) {
		int i = a, j = mid + 1, k = a;
		while (i <= mid && j <= b) {
			if (_k >= 0)
				if (t[i] <= t[j]) {
				    sum[k++] = t[i];
	    			int x = j;
				    while (x <= b && t[i] >= (t[x] - _k)) {
				        if (t[i] == (t[x] - _k)) ret++;
				        x++;
				    }
	    			i++;
				} else sum[k++] = t[j++];
			else {
				if (t[i] >= t[j]) {
				    sum[k++] = t[i];
	    			int x = j;
				    while (x <= b && t[i] <= (t[x] - _k)) {
				        if (t[i] == (t[x] - _k)) ret++;
				        x++;
				    }
	    			i++;
				} else sum[k++] = t[j++];
			}
		}
		while (i <= mid) {
			sum[k++] = t[i++];
		}
		while (j <= b) {
			sum[k++] = t[j++];
		}
	}
	void mergeSort(vector<int> &sum, vector<int> &t, int a, int b) {
		if (a >= b) return;
		int mid = a + (b - a) / 2;
		mergeSort(t, sum, a, mid);
		mergeSort(t, sum, mid + 1, b);
		merge(sum, t, a, mid, b);
	}
    int subarraySum(vector<int>& nums, int k) {
    	ret = 0;
    	_k = k;
        vector<int> sum(nums.size()+1, 0);
        vector<int> t(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); i++) {
        	sum[i + 1] = sum[i] + nums[i];
        	t[i + 1] = sum[i + 1];
        }
		mergeSort(sum, t, 0, t.size() - 1);
		return ret;
    }
};

int main() {
	Solution *s = new Solution();
	int a[] = {1, 1,1};
	int a2[] = {0,0,0,0,0,0,0,0,0,0};
	int a3[] = {-624,-624,-624,-624,-624,-624,-624,-624,-624,-624};
	std::vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	std::vector<int> v2(a2, a2+sizeof(a2)/sizeof(a2[0]));
	std::vector<int> v3(a3, a3+sizeof(a3)/sizeof(a3[0]));

	cout << s->subarraySum(v, 2) << endl;
	cout << s->subarraySum(v2, 0) << endl;
	cout << s->subarraySum(v3, -624) << endl;
	return 0;
}