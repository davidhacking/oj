#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
char map[501][501];
bool a[501][501];
int N = 0, M = 0;

int walk(int i, int j)
{
    int value = 0;
    if(a[i][j] || map[i][j] != '#')
    {
        return value;
    }else
    {
        value += 1;
        a[i][j] = true;
    }
    
    //左上
    if((i-1)>=0 && j-1>=0 && map[i-1][j-1] == '#' && !a[i-1][j-1])
    {
        value += walk(i-1, j-1);
    }
    //上
    if((i-1)>=0 && j>=0 && map[i-1][j] == '#' && !a[i-1][j])
    {
        value += walk(i-1, j);
    }
    //右上
    if((i-1)>=0 && j+1< M && map[i-1][j+1] == '#' && !a[i-1][j+1])
    {
        value += walk(i-1, j+1);
    }
    //左
    if((i)>=0 && j-1>=0 && map[i][j-1] == '#' && !a[i][j-1])
    {
        value += walk(i, j-1);
    }
    //右
    if((i)>=0 && j+1<M && map[i][j+1] == '#' && !a[i][j+1])
    {
        value += walk(i, j+1);
    }
    //左下
    if((i+1)<N && j-1>=0 && map[i+1][j-1] == '#' && !a[i+1][j-1])
    {
        value += walk(i+1, j-1);
    }
    //下
    if((i+1)<N  && j>=0 && map[i+1][j] == '#'&& !a[i+1][j])
    {
        value += walk(i+1, j);
    }
    //右下
    if((i+1)<N && j+1< M && map[i+1][j+1] == '#' && !a[i+1][j+1])
    {
        value += walk(i+1, j+1);
    }
    
    return value;
}
int main()
{
    int n = 0;
    int t = 0;
    int e = 0;
    int s = 0;
    scanf("%d %d\n",&N,&M);
    for(int i = 0; i < N; i++)
    {
        char temp;
        for(int j = 0; j < M; j++)
        {
            scanf("%c",&map[i][j]);
            a[i][j] = false;
        }
        scanf("%c",&temp);
    }
    
   for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            int value = walk(i, j);
            
            if(value == 15)
            {
                //判断是不是N
                //printf("N\n");
                bool flag1 = false;
                bool flag2 = false;
                for(int k = 0; k < 5; k++)
                {
                    if(i+6 >= N || j+k >= M || map[i+6][j+k] != '#'){
                        flag1 = true;
                    }
                    if(j+6 >= M || i+k >= N || map[i+k][j+6] != '#'){
                        flag2 = true;
                    }
                }
                if(flag1 && flag2)
                {
                    //printf("oh\n");
                    continue;
                }else if(flag1)
                {
                    //printf("flag1\n");
                    if(j+6 >= M)
                    {
                        continue;
                    }
                    bool tmp = false;
                    for(int k = 0; k < 5; k++)
                    {
                        if(map[i+k][j+k+1] != '#' || map[i+k][j+6] != '#')
                        {
                            tmp = true;
                            break;
                        }
                    }
                    if(tmp)
                    {
                        continue;
                    }else
                    {
                        n += 1;
                    }
                }else if(flag2)
                {
                    //printf("flag2\n");
                    if(i+6 >= N)
                    {
                        continue;
                    }
                    bool tmp = false;
                    for(int k = 0; k < 5; k++)
                    {
                        if(map[i+k+1][j+k] != '#' || map[i+6][j+k] != '#')
                        {
                            tmp = true;
                            break;
                        }
                    }
                    if(tmp)
                    {
                        continue;
                    }else
                    {
                        n += 1;
                    }
                }
            }
            if(value == 11)
            {
                //判断是不是T
                bool flag1 = false;
                bool flag2 = false;
                for(int k = 1; k < 6; k++)
                {
                    if(j+k >= M || map[i][j+k] != '#')
                    {
                        flag1 = true;
                    }
                    if(i+k >= N || map[i+k][j+3] != '#')
                    {
                        if(k <= 4)
                        {
                            flag2 = true;
                        }
                    }
                }
                if(flag1 && flag2)
                {
                    //printf("oh\n");
                    continue;
                }else if(flag1)
                {
                    bool b1 = false;
                    bool b2 = false;
                    for(int p = 1; p < 5; p++)
                    {
                        if(j-p < 0 || map[i+3][j-p] != '#')
                        {
                            b1 = true;
                        }
                        if(j+p >= M || map[i+3][j+P] != '#')
                        {
                            b2 = true;
                        }
                    }
                    if(!b1 || !b2){
                        t += 1;
                    }else{
                        continue;
                    }
                }else if(flag2)
                {
                    bool b1 = false;
                    bool b2 = false;
                    for(int p = 1; p < 5; p++)
                    {
                        if(i-p < 0 || map[i-p][j+3] != '#')
                        {
                            b1 = true;
                        }
                        if(i+p >= N || map[i+p][j+3] != '#')
                        {
                            b2 = true;
                        }
                    }
                    if(!b1 || !b2){
                        t += 1;
                    }else{
                        continue;
                    }
                }
                
            }
            if(value  == 23)
            {
                //判断是不是E/S
                
            }
        }
    }
    
    printf("N: %d\n",n);
    printf("T: %d\n",t);
    printf("E: %d\n",e);
    printf("S: %d\n",s);
    
    return 0;
}