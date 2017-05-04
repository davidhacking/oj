#include "./stdc++.h"

using namespace std;

int coinNums(vector<int>& coins, int amount) {
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

int main() {
    int a[] = {1, 2, 5};
    std::vector<int> v(a, a + 3);
    cout << coinNums(v, 11) << endl;
    return 0;
}