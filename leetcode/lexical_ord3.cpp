#include "./stdc++.h"

/*
这种题一般都是对着数据好好找规律，然后想出解决方法比较解决方法的时间和空间复杂度
720ms
*/

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
    	std::vector<int> v;
        for (int i = 1; i < 10; i++) {
        	if (i <= n) {
        		v.push_back(i);
        		dfs(i, n, v);
        	}
        }
        return v;
    }
    void dfs(int i, int n, std::vector<int> &v) {
    	for (int j = 0; j < 10; j++) {
    		if (i * 10 + j <= n) {
    			v.push_back(i * 10 + j);
    			dfs(i * 10 + j, n, v);
    		}
    	}
    }
};

void print_v(std::vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
}

int main() {
	Solution *s = new Solution();
	std::vector<int> v = s->lexicalOrder(1000);
	print_v(v);
	return 0;
}