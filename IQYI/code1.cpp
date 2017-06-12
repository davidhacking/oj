//#include <bits/stdc++.h>
#include "./stdc++.h"

using namespace std;

struct Data {
	int a, b;
	Data(int a, int b): a(a), b(b) {}
};

int _max;

int getMax(int curr, int sum, vector<Data> &v, string &f, map<string, int> &m) {
	if (sum <= 0) return curr; 
	if (m.count(f) > 0) {
		return m[f];
	}
	int m2 = 0;
	for (int i = 0; i < v.size(); i++) {
		if (f[i] == '0' && sum >= v[i].a) {
			f[i] = '1';
			curr += v[i].b;
			if (m.count(f) > 0) {
				if (m[f] > _max) {
					_max = m[f];
					m2 = _max;
					f[i] = '0';
					curr -= v[i].b;
					continue;
				}
			}
			int ret = getMax(curr, sum - v[i].a, v, f, m);
			m[f] = ret;
			if (ret > _max) {
				_max = ret;
				m2 = _max;
			}
			f[i] = '0';
			curr -= v[i].b;
		} else {
			if (_max < curr) {
				_max = curr;
			}
		}
	}
	return m2;
}

int main() {
	// freopen("data1", "r", stdin);
	int sum;
	scanf("%d ", &sum);
	int a, b;
	vector<Data> v;
	string f;
	map<string, int> m;
	while (scanf("%d %d", &a, &b) != EOF) {
		v.push_back(Data(a, b));
		f.push_back('0');
	}
	_max = 0;
	getMax(0, sum, v, f, m);
	cout << _max << endl;
	return 0;
}