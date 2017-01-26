#include <iostream>
#include <algorithm>
#include <stdio.h>
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
	return !not_prime[num];
}

int main(void) {
	memset(not_prime, 0, MAX_N * sizeof(bool));
	memset(prime, 0, MAX_PRIME_NUM * sizeof(int));
	gen_prime(1e6);
	while (true) {
		int input = 0;
		scanf("%d", &input);
		if (input == 0 || input > 1e6 || input < 6) {
			return 0;
		}
		int end = (input + 1) / 2;
		bool flag = false;
		for (int i = 2; i <= end; i++) {
			if (flag) {
				break;
			}
			if (is_prime(i)) {
				int j = input - i;
				if (is_prime(j)) {
					cout << input << " = " << i << " + " << j << endl;
					flag = true;
				}
			}
		}
		if (flag == false) {
			cout << "Goldbach's conjecture is wrong.\n";
			return 0;
		}
	}
	return 0;
}