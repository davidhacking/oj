#include "./stdc++.h"

using namespace std;

struct Data
{
	int num;
	int step;
	int from;
	Data(int n, int s, int f): num(n), step(s), from(f) {}
};

int main() {
	vector<Data> v;
	v.push_back(Data(0, 0, -1));
	v.push_back(Data(0, 0, -1));
	int n = 38, min = -1, t, f;
	for (int i = 2; i <= n; i++) {
		min = -1;
		for (int k = 1; k <= i - 1; k++) {
			int max;
			if (k > (v[i - k].num + 1)) {
				max = k;
				f = -1;
			} else {
				max = v[i - k].num + 1;
				f = i - k;
			}
			if (min == -1 || min > max) {
				min = max;
				t = k;
				// print step
				// int x = k, j = 1;
				// while (x != 0) {
				// 	cout << "step" << j++ << ": " << x << ", ";
				// 	x = v[i - x];
				// }
				// cout << endl;
			}
		}
		v.push_back(Data(min, t, f));
	}
	for (int i = 1; i <= n; i++) {
		cout << i << "(" << v[i].num << ", " << v[i].step << ", " << v[i].from << "), ";
	}
	cout << endl;
}