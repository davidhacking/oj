#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 10000 + 16
 
// 先生成MAX_PRIME内的素数表
#define MAX_PRIME MAX_N
vector<int> primes;
vector<bool> is_prime;
void init_primes()
{
	is_prime = vector<bool>(MAX_PRIME + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= MAX_PRIME; ++i)
	{
		if (is_prime[i])
		{
			primes.push_back(i);
			for (int j = i * 2; j <= MAX_PRIME; j += i)
			{
				is_prime[j] = false;
			}
		}
	}
}
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
	init_primes();
	const int size = primes.size();
	int n;
	while (cin >> n && n)
	{
		int l = 0, r = 0, sum = 0, result = 0;
		for (;;)
		{
			while (sum < n && r < size)
			{
				sum += primes[r++];
			}
			if (sum < n)
			{
				break;
			}
			else if (sum == n)
			{
				++result;
			}
			sum -= primes[l++];
		}
		cout << result << endl;
	}
	return 0;
}