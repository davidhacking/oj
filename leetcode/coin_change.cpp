#include "./stdc++.h"

using namespace std;

/*
https://leetcode.com/problems/coin-change/#/description
dp，f(0) = 0, f(1) = f(0) + 1, f(i) = min{f(i-1) + 1, f(i-2) + 1, f(i-5) + 1}
dfs, 要慢很多
*/

bool compare(const int a, const int b){
	return a > b;
}

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	if (coins.size() <= 0 && amount == 0) {
    		return 0;
    	}
    	if (coins.size() <= 0) {
    		return -1;
    	}
    	vector<int> ret;
    	ret.push_back(0);
        for (int i = 1; i <= amount; i++) {
        	int min = -1;
        	for (int j = 0; j < coins.size(); j++) {
        		if (i - coins[j] >= 0 && ret[i - coins[j]] != -1) {
        			if (min == -1) {
        				min = ret[i - coins[j]] + 1;
        			} else if (ret[i - coins[j]] + 1 < min) {
						min = ret[i - coins[j]] + 1;
        			}
        		}
        	}
        	ret.push_back(min);
        }
        return ret[amount];
    }

    int dfs(std::vector<int> &v, int amount) {
    	if (amount == 0) {
    		return 0;
    	}
    	if (amount > 0) {
    		int min = -1;
    		for (int i = 0; i < v.size(); i++) {
    			int tmp = amount - v[i];
    			if (tmp >= 0) {
    				int tmp_min = dfs(v, tmp);
    				if (tmp_min == -1) {
    					continue;
    				}
    				tmp_min += 1;
    				if (min == -1 || min > tmp_min) {
	    				min = tmp_min;
	    			}
    			}
    		}
    		return min;
    	}
    	return -1;
    }

    int coinChange2(vector<int>& coins, int amount) {
    	if (coins.size() <= 0 && amount == 0) {
    		return 0;
    	}
    	if (coins.size() <= 0) {
    		return -1;
    	}
    	sort(coins.begin(), coins.end(), compare);
    	return dfs(coins, amount);
    }
};

int main() {
	int a[] = {1, 2, 5};
	std::vector<int> v(a, a + 3);
	Solution *s = new Solution();
	cout << s->coinChange(v, 11) << endl;
	return 0;
}