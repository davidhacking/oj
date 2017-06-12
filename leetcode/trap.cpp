#include "./stdc++.h"

using namespace std;

/*

算法思路，左右指针法
左指针小于右指针的值，说明当前左指针能够产生trap并且trap的计算是maxleft-left
因为maxleft的产生是一定小于maxright的产生的
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0, left = 0, right = height.size() - 1, maxl = 0, maxr = 0;
        while (left <= right) {
        	if (height[left] <= height[right]) {
        		if (height[left] > maxl) {
        			maxl = height[left];
        		} else {
        			ret += maxl - height[left];
        		}
        		left++;
        	} else {
        		if (height[right] > maxr) {
        			maxr = height[right];
        		} else {
        			ret += maxr - height[right];
        		}
        		right--;
        	}
        }
        return ret;
    }
};

int main() {
	int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};//6
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	Solution *s = new Solution();
	cout << s->trap(v) << endl;
	return 0;
}