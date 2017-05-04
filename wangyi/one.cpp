/*#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n = 0;

int main() {
	// freopen("/Users/david/myFile/OJ/wangyi/test_data", "r", stdin);
	scanf("%d", &n);
	char a[4];
	char b[4];
	int sum = 0;
	while (n--) {
		memset(a, 4, 0);
		memset(b, 4, 0);
		scanf("%s %s %d", a, b, &sum);
		int a_len = strlen(a);
		int a_x = 0;
		int b_len = strlen(b);
		int b_x = 0;
		for (int i = 0; i < a_len; i++) {
			if (a[i] == 'x' || a[i] == 'X') {
				a_x = i;
			}
		}
		for (int j = 0; j < b_len; j++) {
			if (b[j] == 'x' || b[j] == 'X') {
				b_x = j;
			}
		}

		// if ((a_len - a_x) != (b_len - b_x)) {
		// 	printf("1\n");
		// 	continue;
		// }

		int count = 0;
		int i_init = 0;
		if (a_x == 0) {
			i_init = 1;
		}
		int j_init = 0;
		if (b_x == 0) {
			j_init = 1;
		}
		for (int i = i_init; i < 10; i++) {
			a[a_x] = i + 48;
			int a_num = atoi(a);
			b[b_x] = 48;
			int b_num = atoi(b);
			if ((a_num + b_num) > sum) {
				break;
			}
			for (int j = j_init; j < 10; j++) {
				b[b_x] = j + 48;
				b_num = atoi(b);
				if ((a_num + b_num) == sum) {
					// printf("%d %d ", a_num, b_num);
					count++;
					break;
				} else if ((a_num + b_num) > sum) {
					break;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}*/

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int res=0,cnt;
int kongge[10];

void dfs(int rest,int num)
{
	if(num==cnt)
	{
		if(rest==0)
			res++;
		return ;
	}
	for(int i=1;i<=9;i++)
		dfs(rest-kongge[num]*i,num+1);
}

int main()
{
	freopen("/Users/david/myFile/OJ/wangyi/test_data", "r", stdin);
	int T;
	scanf("%d",&T);
	char jia1[10],jia2[10],he[10];
	for(int cas=1;cas<=T;cas++)
	{
		memset(kongge,0,sizeof(kongge));
		scanf("%s%s%s",jia1,jia2,he);
		int sum1=0,sum2=0;
		cnt=0;
		res=0;
		for(int i=0;i<strlen(he);i++)
		{
			sum1=sum1*10+he[i]-'0';
		}
		int temp=1;
		for(int i=strlen(jia1)-1;i>=0;i--)
		{
			if(jia1[i]=='X')
			{
				kongge[cnt++]=temp;
				temp*=10;
				continue;
			}
			sum2+=temp*(jia1[i]-'0');
			temp*=10;
		}
		temp=1;
		for(int i=strlen(jia2)-1;i>=0;i--)
		{
			if(jia2[i]=='X')
			{
				kongge[cnt++]=temp;
				temp*=10;
				continue;
			}
			sum2+=temp*(jia2[i]-'0');
			temp*=10;
		}
		int rest=sum1-sum2;
//		printf("%d %d %d %d\n",sum1,sum2,rest,cnt);
//		for(int i=0;i<cnt;i++)
//			printf("%d\n",kongge[i]);
		dfs(rest,0);
		printf("%d\n",res);
//		printf("%d\n",sum);
	}
	return 0;
}