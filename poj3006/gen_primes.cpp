#include <stdio.h>
#include <iostream>
#include <string.h>


using namespace std;

#define MAX_N 1000000
#define MAX_PRIME_NUM 78498
#define ll long long

int prime[MAX_PRIME_NUM];
bool not_prime[MAX_N];
int prime_count;

void gen_prime(int n)
{
	for (ll i = 2; i <= n; i++)
	{
		if (!not_prime[i])
		{
			prime[prime_count++] = i;
			for (ll j = i * i; j <= n; j += i) 
				not_prime[j] = true;
		}
	}
}


bool is_prime(int num) {
	if (num == 1) {
		return false;
	}
	return !not_prime[num];
}

int main() {
	memset(not_prime, 0, MAX_N * sizeof(bool));
	memset(prime, 0, MAX_PRIME_NUM * sizeof(int));
	gen_prime(1e6);
	// freopen("/Users/david/tmp/test.txt", "r", stdin);
	while (true) {
		int a, d, n;
		scanf("%d %d %d", &a, &d, &n);
		if (a == 0 || d == 0 || n == 0) {
			return 0;
		}
		int i = 0;
		if (is_prime(a)) {
			i++;
		}
		while (i < n) {
			a += d;
			if (is_prime(a)) {
				i++;
			}
		}
		cout << a << endl;
	}
	return 0;
}