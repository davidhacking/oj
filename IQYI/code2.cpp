#include "./stdc++.h"

using namespace std;

int getMax(int k, vector<int> &v, int i) {
	int b = v[i] / 2;
	int count = 2;
	v[i] = b;
	v.push_back(v[i] - b);
	sort(v.begin(), v.end());
	if (count >= k) {
		return b;
	}
	for (int x = 0; x < v.size(); x++) {
		if (v[x] >= b) {
			count++;
			if (count >= k) {
				return b;
			}
		}
	}
	return getMax(k, v, v.size() - 1);
}
int main() {
	freopen("data2", "r", stdin);
	int k;
	scanf("%d", &k);
	int t;
	vector<int> v;
	int sum = 0;
	while (scanf("%d", &t) != EOF) {
		if (t > 0) {
			sum += t;
		}
		v.push_back(t);
	}
	if (sum < k) {
		cout << 0 << endl;
	} else if (sum == k) {
		cout << 1 << endl;
	}
	sort(v.begin(), v.end());
	cout << getMax(k, v, v.size() - 1) << endl;
	return 0;
}