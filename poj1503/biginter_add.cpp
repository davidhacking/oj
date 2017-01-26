#include <stdio.h>
#include <string.h>
#define MAXN 105

int b[MAXN];
char a[MAXN];

int main() {
	int len, i, j, k;
	while (scanf("%s", a) != EOF) {
		if (strcmp(a, "0") == 0) {
			break;
		} else {
			len = strlen(a);
			for (i = 0; i < len; i++) {
				b[i] = b[i] + a[len - 1 - i] - '0';
			}
			for (j = 0; j < MAXN; j++) {
				if (b[j] >= 10) {
					b[j + 1] = b[j + 1] + b[j] / 10;
					b[j] = b[j] % 10;
				}
			}
		}
	}
	k = MAXN;
	while (b[--k] == 0);
	while (k >= 0) {
		printf("%d", b[k--]);
	}
}