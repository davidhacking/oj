#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

//https://leetcode.com/problems/wiggle-sort-ii/#/description
/*
这道题有一个技巧，就是(2*i+1) % (n|1)，这样对下标重新接线使得只要将接线后的数组排序就行了
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size(), x = 0, y = 0, z = n - 1, mid;
		nth_element(nums.begin(), nums.begin() + n/2, nums.end());
		mid = *(nums.begin() + n/2);
		/*
		Accessing A(0) actually accesses nums[1].
		Accessing A(1) actually accesses nums[3].
		Accessing A(2) actually accesses nums[5].
		Accessing A(3) actually accesses nums[7].
		Accessing A(4) actually accesses nums[9].
		Accessing A(5) actually accesses nums[0].
		Accessing A(6) actually accesses nums[2].
		Accessing A(7) actually accesses nums[4].
		Accessing A(8) actually accesses nums[6].
		Accessing A(9) actually accesses nums[8].
		*/
		#define rewire(i) (nums[(2*i+1) % (n|1)])
		while (y <= z)
		{
			if (rewire(y) == mid)
			{
				y++;
			} else if (rewire(y) < mid)
			{
				swap(rewire(y), rewire(z--));
			} else if (rewire(y) > mid)
			{
				swap(rewire(x++), rewire(y++));
			}
		}
    }
};

void print_v(vector<int> &v) {
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;
}

#define random(x) (rand() % x)

int main() {
	vector<int> v;
	int size = 10;
	for (int i = 0; i < size; i++)
	{
		v.push_back(random(100));
	}
	print_v(v);
	Solution *s = new Solution();
	s->wiggleSort(v);
	print_v(v);
	return 0;
}
 