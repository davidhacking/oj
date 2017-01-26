#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	if (primes_index == 0) {
		return 0;
	}
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

int main(int argc, char *argv[]) {
	int input = 0;
	int max_prime = 1229 * sizeof(int);
	primes = (int *) malloc(max_prime);
	if (primes == NULL) {
		goto terminal;
	}
	memset(primes, 0, max_prime);
	while(true) {
		scanf("%d", &input);
		if (input == 0) {
			goto terminal;
		}
		if (input > 10000) {
			goto terminal;
		}
		
		gen_primes(input);
		int count = 0;
		int tmp_index = find_between(input);

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
		printf("%d\n", count);
	}
terminal:
	if (primes) {
		free(primes);
	}
	return 0;
}