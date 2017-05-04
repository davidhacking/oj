#include "./stdc++.h"
/*
dp的方法
生成i对括号和生成i-1对括号的关系，就是在i-1对括号中再加入一对括号，有如下加法(将开括号定在第一个位置)
f(0) ""
f(1) (f(0))
f(2) (f(0))f(1) (f(1))
f(3) (f(0))f(2) (f(1))f(1) (f(2))
f(i) (f(0))f(i-1) (f(1))f(i-2) (f(2))f(i-3) ... (f(j))f(i-1-j) ... (f(i-1))
*/

using namespace std;

class Solution {
public:
	vector<string> result;
	vector<string> generateParenthesis3(int n) {
	    helper("", n, 0);
	    return result;
	}

	/*  this hepler function insert result strings to "vector<string> result"
		When number of '(' less than "n", can append '(';
		When number of '(' is more than number of ')', can append ')';

		string s : current string;
		int leftpare_need : number of '(' that have not put into "string s";
		int moreleft : number of '(' minus number of ')' in the "string s";
	*/

	void helper(string s, int leftpare_need, int moreleft)
	{
		if(leftpare_need == 0 && moreleft == 0)
		{
		    result.push_back(s);
		    return;
		}
		if(leftpare_need > 0)
			helper(s + "(", leftpare_need - 1, moreleft+1);
		if(moreleft > 0)
			helper(s + ")", leftpare_need, moreleft - 1);
	}
    vector<string> generateParenthesis2(int n) {
        vector<vector<string> > fr;
        fr.push_back(vector<string>());
        fr[0].push_back("");
        // cout << fr[0][0] << endl;
        for (int i = 1; i <= n; i++) {
        	fr.push_back(vector<string>());
        	for (int j = 0; j <= i - 1; j++) {
        		for (int x = 0; x < fr[j].size(); x++) {
        			for (int y = 0; y < fr[i - 1 - j].size(); y++) {
        				fr[i].push_back("(" + fr[j][x] + ")" + fr[i - 1 - j][y]);
        			}
        		}
        	}
        }
        return fr[n];
    }

    vector<string> ret;
    void empty_v(string& v, int n) {
		v.erase(v.begin() + n);
	}
    void dfs(string& v, int n, int left, int right) {
		// 剪枝
		if (left < right) {
			return;
		}
	    if (2 * n == left + right) {
	    	ret.push_back(v);
	        return;
	    }
	    if (left < n) {
	        v.push_back('(');
	        dfs(v, n, left + 1, right);
	        empty_v(v, left + right);
	    }
	    if (right < left) {
	        v.push_back(')');
	        dfs(v, n, left, right + 1);
	        empty_v(v, left + right);
	    }
	}
	vector<string> generateParenthesis(int n) {
		string v = "";
		dfs(v, n, 0, 0);
		return ret;
	}
};

void print_vs(std::vector<string> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}

int main() {
	Solution *s = new Solution();
	const clock_t begin_time1 = clock();
	// print_vs(s->generateParenthesis(7));
	// 12 0.2s 15 13.0s 20可能会out of memory
	s->generateParenthesis(12);
	std::cout << float( clock () - begin_time1 ) /  CLOCKS_PER_SEC << endl;

	const clock_t begin_time2 = clock();
	s->generateParenthesis2(12);
	std::cout << float( clock () - begin_time2 ) /  CLOCKS_PER_SEC << endl;

	const clock_t begin_time3 = clock();
	s->generateParenthesis2(12);
	std::cout << float( clock () - begin_time3 ) /  CLOCKS_PER_SEC << endl;
	return 0;
}