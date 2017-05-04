#include "./stdc++.h"

/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/#/description
假设股票的区间是a b c三个数，理论上需要计算b-a,c-b,c-a三次，大于三个数会更多
其实只需要知道b和a的大小关系后面两个值就只需要算一次了
max = std::max(0, max += prices[i] - prices[i - 1]);
这个表达式就是巧妙在这里
*/

using namespace std;

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
        buy = 0;
        sell = prices.size() - 1;
        while (t < prices.size() - 1) {
        	cout << "buy: " << buy << " sell: " << sell << endl;
        	if (buy < sell && profit < prices[sell] - prices[buy]) {
        		profit = prices[sell] - prices[buy];
        	}
        	if (b == 0) {
        		t = findMin(prices, t, prices.size() - 1);
        		if (prices[buy] > prices[t]) {
        			buy = t;
        		}
        		b = 1;
        	}
        	if (b == 1) {
        		t = findMax(prices, t, prices.size() - 1);
        		if (prices[buy] < prices[t]) {
        			sell = t;
        		}
        		b = 0;
        	}
        }
        if (buy < sell && profit < prices[sell] - prices[buy]) {
    		profit = prices[sell] - prices[buy];
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
	cout << s->maxProfit2(v) << endl;

	
	int a2[] = {7, 6, 4, 3, 1};
	vector<int> v2(a2, a2+5);
	cout << s->maxProfit2(v2) << endl;

	int a4[] = {2, 1, 4};
	vector<int> v4(a4, a4+3);
	cout << s->maxProfit2(v4) << endl;

	int a3[] = {2, 4, 1};
	vector<int> v3(a3, a3+3);
	cout << s->maxProfit2(v3) << endl;

	int a5[] = {3,3,5,0,0,3,1,4};
	vector<int> v5(a5, a5+8);
	cout << s->maxProfit2(v5) << endl;
	return 0;
}