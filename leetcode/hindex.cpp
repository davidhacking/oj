#include "./stdc++.h"

using namespace std;
//非常奇怪，如果return a>=b的话将会导致leetcode的double free or corruption，本地是正常的
bool comp(int a, int b) {
	return a > b;
}

class Solution {
public:
	int bin_search(vector<int> &v, int fromIndex, int toIndex) {
		if (v.size() <= 0) {
			return -1;
		}

		int low = fromIndex;
	    int high = toIndex;
	    int max = 0;

	    while (low <= high && (low >= fromIndex && low <= toIndex) && (high >= fromIndex && high <= toIndex)) {
	    	// cout << "low: " << low << " high: " << high << endl;
	        int mid = (low + high) >> 1;
	        if (mid + 1 > v[mid]) {
	            high = mid - 1;
	        } else if (mid + 1 <= v[mid]) {
	            low = mid + 1;
	        	if (max < mid + 1) {
	        		max = mid + 1;
	        	}
	        }
	    }
	    return max;  // key not found.
	}
	
    int hIndex(vector<int>& citations) {
    	int ret = 0;
    	if (citations.size() <= 0) {
    		return ret;
    	}
    	sort(citations.begin(), citations.end(), comp);
        ret = bin_search(citations, 0, citations.size() - 1);
        return ret;
    }
};

int main() {
	int a[] = {3, 0, 6, 1, 5};
	vector<int> v(a, a + 5);
	
	int a1[] = {10, 8, 5, 4, 3};
	vector<int> v1(a1, a1 + 5);
	
	int a2[] = {25, 8, 5, 3, 3};
	vector<int> v2(a2, a2 + 5);

	int a3[] = {25};
	vector<int> v3(a3, a3 + 1);

	int a4[] = {0};
	vector<int> v4(a4, a4 + 1);

	int a5[] = {230,217,203,120,50,177,118,236,209,98,156,15,126,4,15,113,49,173,25,88,115,73,46,152,64,47,160,111,194,119,234,72,79,89,37,14,31,15,21,77,246,192,230,53,14,200,190,40,74,227};
	vector<int> v5(a5, a5 + 50);

	Solution *s = new Solution();
	cout << s->hIndex(v) << endl;
	cout << s->hIndex(v1) << endl;
	cout << s->hIndex(v2) << endl;
	cout << s->hIndex(v3) << endl;
	cout << s->hIndex(v4) << endl;
	cout << s->hIndex(v5) << endl;
	return 0;
}