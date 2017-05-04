#include "./stdc++.h"

using namespace std;

/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/#/description
我的方法是每次找到极值点，相减再加起来
其实这个方法有一个更加省力的方法就是只要前一个数大于后一个数就加起来，其实就是我的方法
int maxProfit(vector<int> &prices) {
    int ret = 0;
    for (size_t p = 1; p < prices.size(); ++p) 
      ret += max(prices[p] - prices[p - 1], 0);    
    return ret;
}
*/

class Solution {
public:
	int findMin(vector<int>& p, int s, int e) {
		int t = s;
		for (int i = s + 1; i <= e; i++) {
			if (p[t] >= p[i]) {
				t = i;
			}
			if (p[t] < p[i]) {
				break;
			}
		}
		return t;
	}
	int findMax(vector<int>& p, int s, int e) {
		int t = s;
		for (int i = s + 1; i <= e; i++) {
			if (p[t] <= p[i]) {
				t = i;
			}
			if (p[t] > p[i]) {
				break;
			}
		}
		return t;
	}
    int maxProfit(vector<int>& prices) {
        int profit = 0, buy = 0, sell = 0, t = 0, b = 0;
        if (prices.size() <= 1) {
        	return 0;
        }
        while (t < prices.size() - 1) {
        	if (b == 0) {
        		t = findMin(prices, t, prices.size() - 1);
        		buy = t;
        		b = 1;
        	}
        	if (b == 1) {
        		t = findMax(prices, t, prices.size() - 1);
        		sell = t;
        		b = 0;
        	}
        	// cout << "buy: " << buy << " sell: " << sell << endl;
        	profit += prices[sell] - prices[buy];
        }
        return profit;
    }

    int maxProfit2(vector<int>& prices) {
    	// max 计算一段区间内的最大值，如果出现小于零的情况则归零，maxsofar到目前为止的最大值
    	int max = 0, maxSoFar = 0;
    	for (int i = 1; i < prices.size(); i++) {
    		max = std::max(0, max += prices[i] - prices[i - 1]);
    		maxSoFar = std::max(max, maxSoFar);
    	}
    	return maxSoFar;
    }
};

int main() {
	Solution *s = new Solution();
	int a[] = {7, 1, 5, 3, 6, 4};
	vector<int> v(a, a+6);
	cout << s->maxProfit(v) << endl;

	
	int a2[] = {7, 6, 4, 3, 1};
	vector<int> v2(a2, a2+5);
	cout << s->maxProfit(v2) << endl;

	int a4[] = {2, 1, 4};
	vector<int> v4(a4, a4+3);
	cout << s->maxProfit(v4) << endl;

	int a3[] = {2, 4, 1};
	vector<int> v3(a3, a3+3);
	cout << s->maxProfit(v3) << endl;

	int a5[] = {3,3,5,0,0,3,1,4};
	vector<int> v5(a5, a5+8);
	cout << s->maxProfit(v5) << endl;
	return 0;
}