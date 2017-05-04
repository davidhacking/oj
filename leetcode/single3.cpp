#include "./stdc++.h"

using namespace std;

/*
https://leetcode.com/problems/single-number-iii/#/description
一些位运算：n&(n-1)消除最后一个一，通过这个可以做很多事情，判断是不是2的n次方，n里面有多少个一
n &= -n得到n中的最后一个一
如果 a != b交换可以这样做，a = a ^ b, b = a ^ b, a = a ^ b，第一个式子得到了a和b的信息，第二个消去了b的信息这身下之前a的信息了
第三个，消去了之前a的信息只剩下之前b的了
这一题就可以用上，后两个来做，如果我们需要找的两个数是a和b那么我们有a^b的信息，并且这个值是不为零的，那么就只需要
用其中最后一个位去区分就行了
*/

class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums) {
    	int vector<int> ret(2, 0);
    	int diff = 0;
    	for (int i = 0; i < nums.size(); i++) diff ^= nums[i];
    	diff &= -diff;
    	for (int i = 0; i < nums.size(); i++)
    		if (nums[i] & diff)
    			ret[0] ^= nums[i];
    		else
    			ret[1] ^= nums[i];
    	return ret;
    }
    
};

int main() {
	return 0;
}