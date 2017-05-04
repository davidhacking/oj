#include "./stdc++.h"

using namespace std;

class Solution {
public:
	// 题目是小于n的，没有等于
    int countPrimes(int n) {
        if (n <= 1) return 0;
        int count = n - 1;
        vector<int> v(n + 1, 0);
        for (int i = 2; i <= sqrt(n); i++) {
            if (v[i] == 0) {
            	v[i] = 1;
                for (int j = 2 * i; j <= n; j += i) {
                    if (v[j] == 0) 
                    	count--;
                    v[j] = 1;
                }
            }
        }
        return count;
    }
};

/*
最快的方法
public int countPrimes(int n) {
    if (n < 3)
        return 0;
        
    boolean[] f = new boolean[n];
    // 不会超过这个数的一半的数量
    int count = n / 2;
    // 2的倍数的数据不用考虑
    for (int i = 3; i * i < n; i += 2) {
        if (f[i])
            continue;
        // i倍之前的被标记过了
        for (int j = i * i; j < n; j += 2 * i) {
            if (!f[j]) {
                --count;
                f[j] = true;
            }
        }
    }
    return count;
}
*/


/*

index	x				pi(x)
1		10				4	 
2		100				25	 
3		1,000			168	 
4		10,000			1,229	 
5		100,000			9,592	 
6		1,000,000		78,498	 
7		10,000,000		664,579	 
8		100,000,000		5,761,455	 
9		1,000,000,000	50,847,534
*/

int main() {
	Solution *s = new Solution();
	cout << s->countPrimes(10) << endl;
	cout << s->countPrimes(100) << endl;
	cout << s->countPrimes(1000) << endl;
	cout << s->countPrimes(10000) << endl;
	return 0;
}