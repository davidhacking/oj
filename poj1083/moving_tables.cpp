#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct node {
	int right;
	int left;
};
bool compare(const int a, const int b){
	return a > b;
}
/*
解题思路：
用数组d[205]记录每个房间前的走廊被用过多少次，然后排个序则答案即为d[0]*10；每扫描一个点将数组这个范围内的值加1，注意，范围的确定，上限s=(a[i].left+1)/2，
下限e=(a[i].right+1)/2。还应注意输入的两个值的大小问题。
*/
int main() {
	int i, max, sum, n, t, b[205];
	node a[100005];
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a[i].left, &a[i].right);
			if (a[i].left > a[i].right) {
				int temp = a[i].left;
				a[i].left = a[i].right;
				a[i].right = temp;
			}
		}
		memset(b, 0, sizeof(b));
		for (int i = 0; i < n; i++) {
			int s = (a[i].left + 1) / 2;
			int e = (a[i].right + 1) / 2;
			while (s != e) {
				b[s++]++;
			}
			b[s]++;
		}
		sort(b, b + 205, compare);
		printf("%d\n", b[0] * 10);
	}
}