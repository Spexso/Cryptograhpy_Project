#include "SieveEratosthenes.h"


SieveEratosthenes::SieveEratosthenes()
{
	// Default Constructor
}

SieveEratosthenes::~SieveEratosthenes()
{
	// Default Destructor
}

void SieveEratosthenes::Base(int LimitNumber)
{
	vector<bool> prime(LimitNumber + 1, true);

	// Mark numbers based on 2, 3, 5, 7
	// rule of Sieve of Eratosthenes Algorithm
	for (int t = 2; t * t <= LimitNumber; t++)
	{
		if (prime[t] == true)
		{
			for (int i = t * t; i <= LimitNumber; i += t)
				prime[i] = false;
		}
	}

	Print(prime, LimitNumber);
}

void SieveEratosthenes::Print(vector<bool> prime, int LimitNumber)
{
	// Print all prime numbers
	cout << "All Prime numbers smaller than " << LimitNumber << " -> \n";
	for (int i = 2; i <= LimitNumber; i++)
	{
		if (prime[i])
			cout << i << " ";
	}

	cout << "\n";
}
