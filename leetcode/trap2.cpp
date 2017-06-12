#include "./stdc++.h"

using namespace std;

/*

算法思路，左右指针法
左指针小于右指针的值，说明当前左指针能够产生trap并且trap的计算是maxleft-left
因为maxleft的产生是一定小于maxright的产生的
*/

int getMax(vector<vector<int> >& heightMap, int i, int j) {
    int max1 = INT_MIN, max2 = INT_MIN;
    for (int t = 0; t < i; t++) {
        max1 = std::max(max1, heightMap[t][j]);
    }
    for (int t = i + 1; t < heightMap.size(); t++) {
        max2 = std::max(max2, heightMap[t][j]);
    }
    return std::min(max1, max2);
}

class Solution {
public:
    int trap(vector<int>& height, vector<vector<int> >& heightMap, int i) {
        int ret = 0, left = 0, right = height.size() - 1, maxl = 0, maxr = 0;
        while (left <= right) {
        	if (height[left] <= height[right]) {
        		if (height[left] > maxl) {
        			maxl = height[left];
        		} else {
                    int t = std::min(maxl, getMax(heightMap, i, left)) - height[left];
        			ret += t > 0 ? t : 0;
        		}
        		left++;
        	} else {
        		if (height[right] > maxr) {
        			maxr = height[right];
        		} else {
                    int t = std::min(maxr, getMax(heightMap, i, right)) - height[right];
        			ret += t > 0 ? t : 0;
        		}
        		right--;
        	}
        }
        return ret;
    }
    int trapRainWater(vector<vector<int> >& heightMap) {
        if (heightMap.size() <= 2) {
            return 0;
        }
        int ret = 0;
        for (int i = 1; i < ((int) heightMap.size() - 1); i++) {
            int t = trap(heightMap[i], heightMap, i);
            cout << t << endl;
            ret += t;
        }
        return ret;
    }
};

int main() {
    Solution *s = new Solution();
    vector<vector<int> > v;


    /*
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]
4
    */
 //    int a[] = {1,4,3,1,3,2};
 //    v.push_back(vector<int>(a, a+sizeof(a)/sizeof(a[0])));
 //    int a1[] = {3,2,1,3,2,4};
 //    v.push_back(vector<int>(a1, a1+sizeof(a1)/sizeof(a1[0])));
 //    int a2[] = {2,3,3,2,3,1};
 //    v.push_back(vector<int>(a2, a2+sizeof(a2)/sizeof(a2[0])));
	// cout << s->trapRainWater(v) << endl;
    /*
[[12,13,1,12],[13,4,13,12],[13,8,10,12],[12,13,12,12],[13,13,13,13]]
15
14
    */
    int a[] = {12,13,1,12};
    v.push_back(vector<int>(a, a+sizeof(a)/sizeof(a[0])));
    int a1[] = {13,4,13,12};
    v.push_back(vector<int>(a1, a1+sizeof(a1)/sizeof(a1[0])));
    int a2[] = {13,8,10,12};
    v.push_back(vector<int>(a2, a2+sizeof(a2)/sizeof(a2[0])));
    int a3[] = {12,13,12,12};
    v.push_back(vector<int>(a3, a3+sizeof(a3)/sizeof(a3[0])));
    int a4[] = {13,13,13,13};
    v.push_back(vector<int>(a4, a4+sizeof(a4)/sizeof(a4[0])));
    cout << s->trapRainWater(v) << endl;
	return 0;
}