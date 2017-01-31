#include <stdio.h>
#include <string.h>

#define MAXN 105

int n;
char p[MAXN];

int main() {
	while (scanf("%d %s", &n, p) != EOF) {
		if (n < 1 || n > 200) {
			return 0;
		}
	}
	return 0;
}