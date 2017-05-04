
/*
https://leetcode.com/problems/k-diff-pairs-in-an-array/#/description
*/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.size() <= 1) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ret = 0, i = 0, t = nums[0];
        for (int j = 1; j < nums.size() && i <= j;) {
            if (i == j) {
                j++;
            }
            if (nums[j] - nums[i] == k) {
                if (nums[i] != t || i == 0) {
                    ret++;
                    t = nums[i];
                    if (i == 0) {
                        i++;
                    }
                }
                j++;
            } else if (nums[j] - nums[i] < k) {
                //if (j < nums.size() - 1)
                    j++;
            } else if (nums[j] - nums[i] > k) {
                i++;
            }
        }
        return ret;
    }
};