#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

struct range {
	double x1;
	double x2;
} pointers[1024];

// struct range {
// 	double x1;
// 	double x2;
// } pointers[1024], result_range[1024];

bool compare(range p1, range p2) {
	return p1.x1 < p2.x1;
}

int main() {
	int n, d;
	int _case = 0;
	while (true) {
		if (scanf("%d %d", &n, &d) == EOF) {
			return 0;
		}
		_case++;
		bool flag = false;

		if (n <= 0) {
			return 0;
		}
		if (d < 0) {
			flag = true;
		}
		
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			if (y > d) {
				flag = true;
			}
			pointers[i].x1 = x - sqrt(d * d - y * y);
			pointers[i].x2 = x + sqrt(d * d - y * y);
		}
		if (flag) {
			cout << "Case " << _case << ": -1" << endl;
			continue;
		}
		sort(pointers, pointers + n, compare);

		int range_index = 0;
		double tmp = pointers[0].x2;
		for (int i = 1; i < n; i++) {
			if (tmp >= pointers[i].x2) {
				tmp = pointers[i].x2;
			} else {
				if (tmp < pointers[i].x1) {
					// result_range[range_index].x2 = tmp;
					// result_range[range_index].x1 = pointers[i - 1].x1;
					range_index++;
					tmp = pointers[i].x2;
				}
			}
		}
		// result_range[range_index].x2 = tmp;
		// result_range[range_index].x1 = pointers[n - 1].x1;
		range_index++;
		// for (int i = 0; i < range_index; i++) {
		// 	cout << result_range[i].x1 << ", " << result_range[i].x2 << endl;
		// }
		cout << "Case " << _case << ": " << range_index << endl;
	}
	return 0;
}

