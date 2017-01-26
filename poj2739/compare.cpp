#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 10000 + 16
 
// 先生成MAX_PRIME内的素数表
#define MAX_PRIME MAX_N
vector<int> primes_vector;
vector<bool> is_prime;
void init_primes()
{
	is_prime = vector<bool>(MAX_PRIME + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= MAX_PRIME; ++i)
	{
		if (is_prime[i])
		{
			primes_vector.push_back(i);
			for (int j = i * 2; j <= MAX_PRIME; j += i)
			{
				is_prime[j] = false;
			}
		}
	}
}

int *primes = NULL;
int primes_index = 0;

static bool isExist(int x) {
	for (int i = 0; i < primes_index; i++) {
		if (primes[i] == x) {
			return true;
		}
	}
	return false;
}

static int find_between(int x) {
	for (int i = 0; i < primes_index; i++) {
		if (primes[i] > x) {
			return i - 1;
		} else if (primes[i] == x) {
			return i;
		}
	}
	return primes_index - 1;
}

static void gen_primes(int max) {
	if (primes == NULL) {
		return;
	}
	bool flag = true;
	for (int i = 2; i <= max; i++) {
		if (i <= primes[primes_index - 1] || isExist(i)) {
			continue;
		}
		flag = true;
		for (int k = 2; k < i; k++) {
			if (i % k == 0) {
				flag = false;
			}
		}
		if (flag) {
			primes[primes_index++] = i;
		}
	}
}


/*

index	x				pi(x)
1		10				4	 
2		100				25	 
3		1,000			168	 
4		10,000			1,229	 
5		100,000			9,592	 
6		1,000,000		78,498	 
7		10,000,000		664,579	 
8		100,000,000		5,761,455	 
9		1,000,000,000	50,847,534

test

2
3
17
41
20
666
12
53
0


gdb display array
print *name@len
*/

static int sw(int input) {
	int count = 0;
	int max_prime = 1229 * sizeof(int);
	int tmp_index = 0;
	if (primes == NULL) {
		goto terminal;
	}
	if (input == 0) {
		goto terminal;
	}
	if (input > 10000) {
		goto terminal;
	}
	
	gen_primes(input);
	
	tmp_index = find_between(input);

	for (int i = 0; i <= tmp_index; i++) {
		int tmp = 0;
		for (int j = i; j <= tmp_index; j++) {
			tmp += primes[j];
			if (tmp == input) {
				count++;
			} else if (tmp > input) {
				break;
			}
		}
	}
terminal:
	return count;
}

int other(int n)
{
	const int size = primes_vector.size();
	int l = 0, r = 0, sum = 0, result = 0;
	for (;;)
	{
		while (sum < n && r < size)
		{
			sum += primes_vector[r++];
		}
		if (sum < n)
		{
			break;
		}
		else if (sum == n)
		{
			++result;
		}
		sum -= primes_vector[l++];
	}
	return result;
}


int main() {
	primes = (int *) malloc(1229 * sizeof(int));
	memset(primes, 0, 1229 * sizeof(int));
	init_primes();

	for (int i = 100; i < 10000; i++) {
		if (sw(i) != other(i)) {
			printf("i = %d\n", i);
		}
	}
	if (primes) {
		free(primes);
	}
	return 0;
}