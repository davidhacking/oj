#include "./stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        if (s.size() < p.size() || p.size() <= 0) {
            return ret;
        }
        int m[255];
        memset(m, INT_MIN, 255 * sizeof(int));
        int left = 0, right = 0, count = p.size();
        for (int i = 0; i < p.size(); i++) {
        	if (m[p[i]] == INT_MIN) {
				m[p[i]] = 1;
				continue;
        	}
        	m[p[i]]++;
        }
        while (right < s.size()) {
        	if (m[s[right]] != INT_MIN)
        		m[s[right]]--;
        	if (m[s[right]] >= 0) {
        		count--;
        	}
        	if (count == 0) {
        		ret.push_back(left);
        	}
        	// cout << "left: " << left << " right: " << right << " count: " << count << endl;
        	// cout << endl;
        	if (right - left + 1 == p.size()) {
        		if (m[s[left]] != INT_MIN) {
					m[s[left]]++;
					if (m[s[left]] > 0)
	        			count++;
        		}
        		left++;
        	}
        	right++;
        }
        return ret;
    }
};

int main() {
	Solution *s = new Solution();
	//                                 0123456789     
	// vector<int> ret = s->findAnagrams("cbaebabacd", "abc");
	vector<int> ret = s->findAnagrams("baa", "aa");
	copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;
	return 0;
}