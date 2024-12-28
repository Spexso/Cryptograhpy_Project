#include "SieveAtkin.h"

SieveAtkin::SieveAtkin()
{
	// Default Constructor
}

SieveAtkin::~SieveAtkin()
{
	// Default Destructor
}

void SieveAtkin::Base(int LimitNumber)
{
	// Initialize the sieve vector
	vector<bool> sieve(LimitNumber + 1, false);

	// 2 and 3 are initial primes
	if (LimitNumber > 2)
		sieve[2] = true;
	if (LimitNumber > 3)
		sieve[3] = true;

	for (int x = 1; x * x <= LimitNumber; x++)
	{
		for (int y = 1; y * y <= LimitNumber; y++)
		{

			// Condition 1
			int n = (4 * x * x) + (y * y);
			if (n <= LimitNumber && (n % 12 == 1 || n % 12 == 5))
				sieve[n] = true;

			// Condition 2
			n = (3 * x * x) + (y * y);
			if (n <= LimitNumber && n % 12 == 7)
				sieve[n] = true;

			// Condition 3
			n = (3 * x * x) - (y * y);
			if (x > y && n <= LimitNumber && n % 12 == 11)
				sieve[n] = true;
		}
	}

	// Mark all multiples of squares as non-prime
	for (int r = 5; r * r <= LimitNumber; r++)
	{
		if (sieve[r])
		{
			for (int i = r * r; i <= LimitNumber; i += r * r)
				sieve[i] = false;
		}
	}

	Print(sieve, LimitNumber);
}

void SieveAtkin::Print(vector<bool> prime, int LimitNumber)
{
	// Print all prime numbers
	cout << "All Prime numbers smaller than " << LimitNumber << " -> \n";
	for (int i = 2; i <= LimitNumber; i++)
	{
		if (prime[i])
			cout << "-" << i << endl;
	}

	cout << "\n";
}
