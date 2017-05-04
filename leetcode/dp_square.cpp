#include "./stdc++.h"

using namespace std;

/*
https://leetcode.com/problems/maximal-square/#/description
dp[i] = min(左, 上, 左上) 第二个为上一层的值
*/

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
    	if (matrix.size() <= 0) 
    		return 0;
        int n = matrix[0].size();
        vector<int> dp(n, 0);
        int max = 0;
        for (int i = 0; i < matrix[0].size(); i++) {
        	dp[i] = matrix[0][i] - '0';
        	max = std::max(dp[i], max);
        }

        for (int i = 1; i < matrix.size(); i++) {
        	int t = dp[0];
        	dp[0] = matrix[i][0] - '0';
        	max = std::max(dp[0], max);
        	for (int j = 1; j < matrix[i].size(); j++) {
        		int tmp = dp[j];
        		if (matrix[i][j] == '0') {
        			dp[j] = 0;
        		} else {
        			dp[j] = std::min(std::min(dp[j - 1], dp[j]), t) + 1;
	        		max = std::max(dp[j], max);
	        	}
        		t = tmp;
        	}
        }
        return max * max;
    }
};

int main() {
	// char a0[] = {'1','0','1','0','0'};
	// char a1[] = {'1','0','1','1','1'};
	// char a2[] = {'1','1','1','1','1'};
	// char a3[] = {'1','0','0','1','0'};
	// vector<char> v0(a0, a0 + 5);
	// vector<char> v1(a1, a1 + 5);
	// vector<char> v2(a2, a2 + 5);
	// vector<char> v3(a3, a3 + 5);
	// vector<vector<char> > v;
	// v.push_back(v0);
	// v.push_back(v1);
	// v.push_back(v2);
	// v.push_back(v3);

	char a0[] = {'0','0','0','0','0'};
	char a1[] = {'1','0','0','0','0'};
	char a2[] = {'0','0','0','0','0'};
	char a3[] = {'0','0','0','0','0'};
	vector<char> v0(a0, a0 + 5);
	vector<char> v1(a1, a1 + 5);
	vector<char> v2(a2, a2 + 5);
	vector<char> v3(a3, a3 + 5);
	vector<vector<char> > v;
	v.push_back(v0);
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	Solution *s = new Solution();
	cout << s->maximalSquare(v) << endl;
	return 0;	
}