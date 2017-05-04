#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int vis[25],maxnow;
int T,n,s,m[25],f[25][5],g[25][5];
char name[25][35];
int res[25];
void dfs(int money,int zhanli)
{
	if(zhanli>maxnow)
	{
		for(int i=1;i<=n;i++)
			res[i]=vis[i];
		maxnow=zhanli;
	}
	if(money<0)
		return;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]+1>m[i])
			continue;
		if(money>=g[i][vis[i]+1])
		{
			vis[i]++;
			dfs(money-g[i][vis[i]],zhanli+f[i][vis[i]]);
			vis[i]--;
		}
	}
}

int main()
{
//	int T,n,s,m[25],f[25][5],g[25][5];
//	char name[25][35];
//	int res[25];
	// freopen("/Users/david/myFile/OJ/wangyi/test3", "r", stdin);
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		scanf("%d%d",&n,&s);
		memset(res,0,sizeof(res));
		memset(vis,0,sizeof(vis));
		maxnow=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",name[i]);
			scanf("%d",&m[i]);
			for(int j=1;j<=m[i];j++)
			{
				scanf("%d%d",&f[i][j],&g[i][j]);
			}
		}
		dfs(s,0);
		printf("%d\n",maxnow);
		for(int i=1;i<=n;i++)
		{
			printf("%s+%d\n",name[i],res[i]);
		}
/*		for(int i=1;i<=n;i++)
		{
			printf("%s\n%d\n",name[i],m[i]);
			printf("%d %d\n",f[i][1],g[i][1]);
		}*/
	}
	return 0;
}