// #include <bits/stdc++.h>
#include "./stdc++.h"

using namespace std;


int main() {
	freopen("data1", "r", stdin);
	int y, m, d;
	int md[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	while (scanf("%d-%d-%d", &y, &m, &d) != EOF) {
		if (y > 10000 || m < 1 || m > 12 || d < 1 || d > 31 || y < 1) {
			cout << "invalid input" << endl;
			return -1;
		}
		// 判断闰年
		/*
		1、普通年能被4整除且不能被100整除的为闰年.（如2004年就是闰年,1901年不是闰年）
		2、世纪年能被400整除的是闰年.(如2000年是闰年,1900年不是闰年)
		*/
		bool flag = false;
		if (y % 100 == 0) {
			if (y % 400 == 0)
				flag = true;
		} else if (y % 4 == 0) {
			flag = true;
		}
		if (m != 2 && md[m - 1] < d) {
			cout << "invalid input" << endl;
			return -1;
		}
		if (m == 2) {
			if (flag && (md[m - 1] + 1) < d) {
				cout << "invalid input" << endl;
				return -1;
			} else if (!flag && md[m - 1] < d) {
				cout << "invalid input" << endl;
				return -1;
			}
		}
		int sum = 0;
		for (int i = 0; i < m - 1; i++) {
			if (i == 1 && flag == true) {
				sum += 1;
			}
			sum += md[i];
		}
		sum += d;
		// 2000-2-28 is the No.59 day of 2000.
		cout << y << "-" << m << "-" << d << " is the No." << sum << " day of " << y << "." << endl;
	}
	return 0;
}