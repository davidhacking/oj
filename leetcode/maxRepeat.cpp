#include "./stdc++.h"

using namespace std;


/*
the strings S1 and S2, where S1=[s1,n1] and S2=[s2,n2]. 
Find the maximum integer M such that [S2,M] can be obtained from S1.
*/
class Solution {
public:
	int getRemainStr(string s1, string &s2, string &rem) {
		if (s1.length() < s2.length()) {
			rem = s1;
			return 0;
		}
		int x = 0, j = 0, count = 0;
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] == s2[j]) {
				j++;
			}
			if (j == s2.length()) {
				count++;
				x = i;
				j = 0;
			}
		}
		rem = s1.substr(x, s1.length() - x);
		return count;
	}
	bool check(string &s1, string &s2, int &size) {
		map<char, bool> m;
        int f1 = 0;
        for (int i = 0; i < s2.length(); i++) {
        	if (m.count(s2[i]) <= 0) {
        		m[s2[i]] = true;
        		f1++;
        	}
        }
        bool f = true;
        for (int i = 0; i < s1.length(); i++) {
        	if (m.count(s1[i]) > 0) {
        		if (m[s1[i]]) f1--;
        		m[s1[i]] = false;
        	} else {
        		f = false;
        	}
        }
        if (f)
        	size = m.size();
        return f1 == 0;
	}
	int getMaxRepetitions(string s1, int n1, string s2, int n2) {
		int size = 0;
		if (!check(s1, s2, size) || ((int)s1.length() * n1 / (int)s2.length() / n2) <= 0) return 0;
		if (size == 1) return ((int)s1.length() * n1 / (int)s2.length() / n2);
		int count = 0, loop = 0, T, countPerLoop;
		map<string, pair<int, int> > m;
		string rem = "";
		do {
			count += getRemainStr(rem + s1, s2, rem);
			// cout << "count: " << count << " rem: " << rem << endl;
			n1--;
			if (m.count(rem) <= 0) {
				m[rem] = pair<int, int>(++loop, count);
			} else {
				T = ++loop - m[rem].first;
				countPerLoop = count - m[rem].second;
				// count = m[rem].second;
				break;
			}
		} while (n1 >= 0);
		// cout << count << endl;
		// cout << n1 << endl;
		// cout << T << endl;
		// cout << countPerLoop << endl;
		// cout << n2 << endl;
		return (count + (n1 / T) * countPerLoop) / n2;
	}
    int getMaxRepetitions2(string s1, int n1, string s2, int n2) {
        map<char, queue<int> > m;
        int f1 = 0;
        for (int i = 0; i < s2.length(); i++) {
        	if (m.count(s2[i]) <= 0) {
        		m[s2[i]] = queue<int>();
        		f1++;
        	}
        }
        for (int i = 0; i < s1.length(); i++) {
        	if (m.count(s1[i]) > 0) {
        		if (m[s1[i]].size() <= 0) f1--;
        		m[s1[i]].push(i);
        	}
        }
        // cout << "f1: " << f1 << endl;
        if (f1 != 0) return 0;
        int n = 1, count2 = 0, curr = -1, f2 = 0;
        map<char, queue<int> > t = m;
        while (f2 == 0) {
        	// cout << "f2: " << f2 << endl;
        	// cout << "count2: " << count2 << endl;
        	// cout << "n: " << n << endl;
        	// if (count2 > 0 && n > 1) {
        	// 	break;
        	// }
	        for (int i = 0; i < s2.length(); i++) {
	        	if (t[s2[i]].size() <= 0) {
	        		f2 = 1;
	        		break;
	        	}
	        	while (!t[s2[i]].empty() && curr >= t[s2[i]].front()) {
	        		t[s2[i]].pop();
	        	}
	        	if (t[s2[i]].empty()) {
	        		n++;
	        		if (n > n1) {
	        			f2 = 2;
	        			break;
	        		}
	        		t = m;
	        	}
	        	curr = t[s2[i]].front();
	        	// cout << "curr: " << curr << endl;
	        	t[s2[i]].pop();
	        }
	        if (f2 == 0)
	        	count2++;
	    }
        // cout << "f2: " << f2 << endl;
        // cout << "count2: " << count2 << endl;
        // cout << "n: " << n << endl;
        if (count2 == 0) return 0;
        return (double) n1 / ((double) n / count2) / n2;
    }
};

int main() {
	Solution *s = new Solution();
	/*
Input:
s1="acb", n1=4
s2="ab", n2=2

Return:
2
	*/
	// cout << s->getMaxRepetitions("acb", 4, "ab", 2) << endl;
	/*
"niconiconi"
99981
"nico"
81
	*/
cout << s->getMaxRepetitions("niconiconi", 99981, "nico", 81) << endl;//2468
cout << s->getMaxRepetitions("lovelivenanjomusicforever", 100000, "nanjo", 10) << endl;//10000
cout << s->getMaxRepetitions("nlhqgllunmelayl", 2, "lnl", 1) << endl;//3
/*
"phqghumeay"
100
"lnl"
1
*/
cout << s->getMaxRepetitions("phqghumeay", 100, "lnl", 1) << endl;//0
/*
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
1000000
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
103
*/
cout << s->getMaxRepetitions("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 1000000, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 103) << endl;//5620	
	return 0;
}