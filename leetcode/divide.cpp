/*
https://leetcode.com/problems/divide-two-integers/#/description
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
    	// 如果divisor是零则会溢出
    	/*
		INT_MAX = ~(1 << 31) = 0x7fffffff
		INT_MIN = (1 << 31) = 0x80000000
		即min是只有符号位，max符号位为零其余位位一
		所以max的绝对值比min小一min／-1也会发生溢出
    	*/
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
            return INT_MAX;
        }
        bool f = true, s = true;
        if (dividend < 0) {
            f = false;
        }
        if (divisor < 0) {
            s = false;
        }
        // 以免运算过程中发生溢出
        long long dd = labs(dividend);
        long long tmp, dv = tmp = labs(divisor);
        
        int ret = 0, multi = 1;
        /*
		每次将除数有移进行扩大，用被除数减去除数
		步骤：
		1.如果被除数大于除数则被除数减去除数能扩大的最大倍数
		2.结果加上倍数
		3.反复进行步骤1，2，直到被除数小于除数

        */
        while (dd >= tmp) {
            while (dd >= (tmp << 1)) {
                tmp <<= 1;
                multi <<= 1;
            }
            dd -= tmp;
            ret += multi;
            tmp = dv, multi = 1;
        }
        return !(f^s) ? ret : -ret;
    }
};