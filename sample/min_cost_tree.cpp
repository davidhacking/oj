#include "./stdc++.h"
#include <unordered_map>

using namespace std;

void print_vv(vector<vector<int> > &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

void print_v(vector<int> &v) {
    for (int j = 0; j < v.size(); j++) {
        cout << v[j] << ", ";
    }
    cout << endl;
}

// dfs
// 貌似是不行的，这个算法设计的是一个环
void dfs(vector<vector<int> > &g, vector<int> &path, int &count, int &ret, int &curr) {
	print_v(path);
	if (count >= g.size() - 1) {

		ret = std::min(ret, curr);
		// if (ret == 64) {
		// 	print_v(path);
		// }
		return;
	}
	int x = 0;
	while (!(path[x] == -1 && g[x][x] == INT_MAX)) {
		x = path[x];
	}
	count++;
	g[x][x] = 0;
	for (int i = 0; i < g.size(); i++) {
		if (i == x || g[i][i] == 0 || g[x][i] == INT_MAX) {
			continue;
		}
		count++;
		curr += g[x][i];
		path[x] = i;
		g[i][i] = 0;
		dfs(g, path, count, ret, curr);
		count--;
		curr -= g[x][i];
		path[x] = -1;
		g[i][i] = INT_MAX;
	}
	count--;
	g[x][x] = INT_MAX;
}

struct Data {
	int w;
	pair<int, int> p;
	Data(int x, int y, int w): w(w), p(pair<int, int>(x, y)) {}
};

struct Comp {
	bool operator () (Data a, Data b) {
		return a.w > b.w;
	}
};
int minCost(vector<vector<int> > &g, vector<pair<int, int> > &e) {
	int ret = 0;
	int count = 0;
	unordered_map<int, bool> m;
	priority_queue<Data, vector<Data>, Comp> q;

	for (int i = 0; i < g[0].size(); i++) {
		if (g[0][i] != INT_MAX) {
			q.push(Data(0, i, g[0][i]));
		}
	}
	m[0] = true;
	while (m.size() < g.size()) {
		cout << m.size() << endl;
		while (m.count(q.top().p.second) > 0) {
			q.pop();
		}
		e.push_back(q.top().p);
		ret += q.top().w;
		int x = q.top().p.second;
		q.pop();
		for (int i = 0; i < g[x].size(); i++) {
			if (g[x][i] != INT_MAX && m.count(i) <= 0) {
				q.push(Data(x, i, g[x][i]));
			}
		}
		m[x] = true;
	}
	return ret;
}
/*
prim算法：
http://www.cnblogs.com/biyeymyhjob/archive/2012/07/30/2615542.html
*/
void prim() {
	vector<vector<int> > v(9, vector<int>(9, INT_MAX));
	v[0][1] = 10; v[0][5] = 11;
	v[1][0] = 10; v[1][2] = 18; v[1][6] = 16; v[1][8] = 12;
	v[2][3] = 22;v[2][8] = 8;
	v[3][2] = 22;v[3][4] = 20;v[3][7] = 16;v[3][8] = 21;
	v[4][3] = 20;
	v[4][5] = 26;
	v[4][7] = 7;
	v[5][0] = 11;
	v[5][4] = 26;
	v[5][6] = 17;
	v[6][1] = 16;
	v[6][5] = 17;
	v[6][7] = 19;
	v[7][3] = 16;
	v[7][4] = 7;
	v[7][6] = 19;
	v[8][1] = 12;
	v[8][2] = 8;
	v[8][3] = 21;
	vector<pair<int, int> > e;
	cout << minCost(v, e) << endl;
}

int main() {
	prim();
	return 0;
}