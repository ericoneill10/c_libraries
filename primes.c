#include "primes.h"
#include <math.h>

// ensure last_prime is 1 or larger
int is_prime(int n)
{
	int i;
	int sqrt_n = (int)sqrt((double)n);

	

	if (n ==2) return 1;
	if (n % 2 == 0) return 0;
	for (i = 3; i <= sqrt_n + 1; i+=2)
	{
		if (n%i == 0) return 0;
	}
	return 1;
}

int find_nth_prime(int n)
{
	int i = 2;
	int primes_found = 0;
	while (primes_found < n)
	{

		//TODO: REMEMBER LAST PRIME, NO NEED TO START FROM 3 EVERY TIME
		if (is_prime(i))
		{
			primes_found++;
			if (primes_found == n) break;
		}
		i++;
	}
	return i;
}