#include "./stdc++.h"

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right && nums[left] >= nums[right]) {
            // cout << "left: " << left << " right: " << right << endl;
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[left]) {
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else if (nums[mid] == nums[left] || nums[mid] == nums[right]) {
                int min = nums[left];
                for (int i = left + 1; i <= right; i++) {
                    if (nums[i] < min) {
                        min = nums[i];
                        return min;
                    }
                }
                return min;
            }
        }
        return nums[left];
    }
};

int main() {
    int a[] = {1,1,0,1,1};
    std::vector<int> v(a, a + 5);

    int a2[] = {1,2,0,1,1};
    std::vector<int> v2(a2, a2 + 5);

    int a3[] = {3,1,3};
    std::vector<int> v3(a3, a3 + 3);

    int a4[] = {1,1};
    std::vector<int> v4(a4, a4 + 2);

    int a5[] = {3,1,1};
    std::vector<int> v5(a5, a5 + 3);

    Solution *s = new Solution();
    cout << s->findMin(v) << endl;
    cout << s->findMin(v2) << endl;
    cout << s->findMin(v3) << endl;
    cout << s->findMin(v4) << endl;
    cout << s->findMin(v5) << endl;
    return 0;
}