#include "./stdc++.h"

using namespace std;

int main() {
	map<int, int> m;
	int a[] = {1000, 9, 8, 200, 80, 9}, max = 0;
	for (int i = 0; i < 6; i++) {
		m[a[i]] = 1;
	}
	map<int, int>::iterator i = m.begin();
	int last = i->first;
	for (i++; i != m.end(); i++) {
		max = std::max(max, i->first - last);
		last = i->first;
	}
	cout << max << endl;
	return 0;
}
