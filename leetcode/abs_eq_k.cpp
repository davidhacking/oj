
/*
https://leetcode.com/problems/k-diff-pairs-in-an-array/#/description
Given an array of integers and an integer k, 
you need to find the number of unique k-diff pairs in the array. 
Here a k-diff pair is defined as an integer pair (i, j), 
where i and j are both numbers in the array and their absolute difference is k.
双指针法
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