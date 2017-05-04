#include "./stdc++.h"

/*
比较简单的做法是将区间分成两段，对于每段求最大利益，复杂度是n平方

另一种线性复杂度的算法，采用每次试探oneBuy第一次买哪个，oneSell第一次在哪里卖，twoBuy在做了一次生意的情况
下第二次买什么，twoSell第二次在那里卖
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
    int maxProfit2(vector<int>& prices) {
        int profit1 = 0, profit2 = 0, profit = 0, buy = 0, sell = 0, t = 0, b = 0;
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
        	profit1 = maxProfit2(prices, 0, t);
        	profit2 = maxProfit2(prices, t + 1, prices.size() - 1);
       		// cout << "profit1: " << profit1 << " profit2: " << profit2 << endl;
        	if (profit < profit1 + profit2) {
        		profit = profit1 + profit2;
        	}
        }
        return profit;
    }

    int maxProfit(vector<int>& prices) {
	    int oneBuy = INT_MIN;
	    int oneBuyOneSell = 0;
	    int twoBuy = INT_MIN;
	    int twoBuyTwoSell = 0;
	    for(int i = 0; i < prices.size(); i++) {
	        oneBuy = std::max(oneBuy, -prices[i]);//we set prices to negative, so the calculation of profit will be convenient
	        oneBuyOneSell = std::max(oneBuyOneSell, prices[i] + oneBuy);
	        twoBuy = std::max(twoBuy, oneBuyOneSell - prices[i]);//we can buy the second only after first is sold
	        twoBuyTwoSell = std::max(twoBuyTwoSell, twoBuy + prices[i]);
	    }
	    return std::max(oneBuyOneSell, twoBuyTwoSell);
	}

    int maxProfit2(vector<int>& p, int s, int e) {
    	// max 计算一段区间内的最大值，如果出现小于零的情况则归零，maxsofar到目前为止的最大值
    	int max = 0, maxSoFar = 0;
    	for (int i = s + 1; i <= e; i++) {
    		max = std::max(0, max += p[i] - p[i - 1]);
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

	int a6[] = {1,2,4,2,5,7,2,4,9,0};
	vector<int> v6(a6, a6+10);
	cout << s->maxProfit(v6) << endl;

	int a9[] = {1,2};
	vector<int> v9(a9, a9+2);
	cout << s->maxProfit(v9) << endl;
	return 0;
}