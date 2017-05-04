#include "./stdc++.h"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        /*
        abx ab
        001 10
        101 01
        011 00

        000 00
        100 10
        010 01
		
        x=0 ab保持原值
        这是真值表达式转逻辑表达式的计算了
        一种方法是将真值为1的结果写成 表达式加的形式，其中表达式是参数表中为零的取反与上为一的
        a = ~a~bx + a~b~x = ~b(~ax + a~x) = ~b & (a ^ x)
        */
        for (int i = 0; i < nums.size(); i++) {
            a = (a ^ nums[i]) & ~b;
            b = (b ^ nums[i]) & ~a;
        }
        return a;
    }
};

int main() {
	Solution *s = new Solution();
	int a[] = {1, 2,2,2};
	std::vector<int> v(a, a+4);
	cout << s->singleNumber(v) << endl;
	return 0;
}