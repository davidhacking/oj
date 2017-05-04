/*
完全没理解题目意思
看这个AC代码题目的意思有以下几个
1. freddy在给的1号点上，fiona在给的2号点上
2. 从1跳到2，frdddy只跳离自己最近的，跳过的不跳
3. 只要这个过程中跳到了2号点就算成功
4. 返回在这个过程中的最大值
*/

#include <iostream>
#include <math.h>
#define MAX 201

#define sq(a)  ((a)*(a))
float dis[MAX][MAX];
typedef struct node {
    int x, y;

} Node;
long int INF = 99999999;
bool inTree[MAX];
Node nodes[MAX];
void ptable(int count) {
    int i, j;
    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++)
            printf("(%d,%d)%10f", i, j, dis[i][j]);
        printf("\n");
    }
}
bool allInTree(int count) {

    for (int i = 0; i < count; i++)
        if (!inTree[i])return false;
    return true;
}
int prim(int v, int n) {
    int i, j, ti, tj;
    float mindis, maxdis = -1;
    memset(inTree, false, sizeof(inTree));
    inTree[0] = true;
    while (!allInTree(n)) {
        mindis = INF;

        //找到最小权值
        for (i = 0; i < n; i++)
        {
            if (inTree[i]) {
                for (j = 0; j < n; j++)
                    if (i != j && !inTree[j] && dis[i][j] <= mindis) {
                        mindis = dis[i][j];
                        ti = i;
                        tj = j;
                    }
            }
        }
        if (mindis > maxdis)maxdis = mindis;
        //找到终点
        if (ti == 1 || tj == 1) {

            return maxdis;
        }
        //printf("%d %d\nIntree:",ti,tj);
        //inTree[ti]=true;
        inTree[tj] = true;

        //for(int k=0;k<n;k++)
        //if(inTree[k])printf("%d ",k);
        //printf("\n");
        //ptable(n);
    }




    return maxdis;
}
int main(int argc, char* argv[])
{
    //freopen("i://t.txt","r",stdin);
    //freopen("i://out.txt","w",stdout);
    int count, i, j, c = 1;
    while (scanf("%d", &count) && count) {



        for (i = 0; i < count; i++)
        {
            scanf("%d%d", &nodes[i].x, &nodes[i].y);
            for (j = 0; j < i; j++) {
                dis[i][j] = sq(nodes[i].x - nodes[j].x) + sq(nodes[i].y - nodes[j].y);
                dis[j][i] = dis[i][j];
            }
            dis[i][i] = 0;
        }
        printf("Scenario #%d\n", c++);
        printf("Frog Distance = %.3lf\n\n", sqrt((float)prim(0, count)));




    }
    return 0;
}