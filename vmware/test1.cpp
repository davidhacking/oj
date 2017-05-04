#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;


#define INF INT_MAX
long n;

long f(long x)
{
    long r = 0, s = 5;
    while(s <= x){
        r += x / s;
        s *= 5;
    }
    return r;
}

long my_binary_search(long l, long r, long k)
{
    while(l <= r) {
        long mid = (l + r) / 2;
        if (f(mid) == k && f(mid-1) < k) {
        	return mid;
        } else if(f(mid) < k) {
        	l = mid + 1;
        }
         else { 
        	r = mid - 1;
        }
    }
    return -1;
}

int main() {
	while (scanf("%ld", &n) != EOF)
		printf("%ld\n", my_binary_search(1, INF, n));
	return 0;
}