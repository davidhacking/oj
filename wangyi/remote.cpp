# include <stdio.h>
# include <iostream>
# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>

using namespace std;

int main() {
	freopen("/Users/david/myFile/OJ/wangyi/remote_data", "r", stdin);
	char a[256];
	memset(a, 256, 0);
	while (scanf("%s", a) != EOF) {
		printf("%s\n", a);
	}
	return 0;
}