#include "./stdc++.h"

using namespace std;

void print_p(vector<int> &v, vector<pair<int, int> > &ret) {
	for (int i = 0; i < v.size(); i++) {
		cout << "(" << ret[v[i]].first << ", " << ret[v[i]].second << ")" << ", ";
	}
	cout << endl;
}

void print_p(vector<pair<int, int> > &ret) {
	for (int i = 0; i < ret.size(); i++) {
		cout << "(" << ret[i].first << ", " << ret[i].second << ")" << ", ";
	}
	cout << endl;
}

/*
Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

struct Comp {
	vector<pair<int, int> >& p;
	Comp(vector<pair<int, int> >& p): p(p) {}
	bool operator() (int a, int b) {
		if (p[a].second != p[b].second) {
			return p[a].second < p[b].second;
		} else {
			return p[a].first > p[b].first;
		}
	}
};

class Solution {
public:
	/*
	（h，k）
插入法，排序people，先按k排序，同一个k按h大的排，顺序插入ret，插入时按照规则，插入到满足规则的最后一个位置
	*/
    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
    	// print_p(people);
        vector<pair<int, int> > ret;
        Comp comp(people);
        vector<int> v(people.size(), 0);
        // 浪费时间
        for (int i = 0; i < people.size(); i++) {
        	v[i] = i;
        }
        sort(v.begin(), v.end(), comp);
        // print_p(v, people);
        for (int i = 0; i < v.size(); i++) {
        	vector<pair<int, int> >::iterator iter = ret.begin();
        	int count = 0;
        	// 其实只要 ans.insert(ans.begin() + p.second, p);
        	while (iter != ret.end() && count <= people[v[i]].second) {
        		if (people[v[i]].first <= iter->first) {
        			count++;
        		}
        		iter++;
        	}
        	// if (iter != ret.begin()) ret.insert(--iter, people[v[i]]);
        	// else ret.insert(iter, people[v[i]]);
        	if (count > people[v[i]].second) {
        		iter--;
        	}
        	ret.insert(iter, people[v[i]]);
        }
        return ret;
    }
};

int main() {
	Solution *s = new Solution();
	vector<pair<int, int> > p;
	//[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]
	p.push_back(pair<int, int>(7,0));
	p.push_back(pair<int, int>(4,4));
	p.push_back(pair<int, int>(7,1));
	p.push_back(pair<int, int>(5,0));
	p.push_back(pair<int, int>(6,1));
	p.push_back(pair<int, int>(5,2));
	vector<pair<int, int> > ret = s->reconstructQueue(p);
	print_p(ret);
	return 0;
}