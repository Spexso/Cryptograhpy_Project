#include "MillerRabin.h"

MillerRabin::MillerRabin()
{
	// Default Constructor
}

MillerRabin::~MillerRabin()
{
	// DefaultDestructor
}

// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool MillerRabin::IsPrime(int n, int k)
{
	// Corner cases
	if (n <= 1 || n == 4)  return false;
	if (n <= 3) return true;

	// Find r such that n = 2^d * r + 1 for some r >= 1
	int d = n - 1;
	while (d % 2 == 0)
		d /= 2;

	// Iterate given number of 'k' times
	for (int i = 0; i < k; i++)
		if (!Base(d, n))
			return false;

	return true;
}

bool MillerRabin::Base(int d, int n)
{
	// Pick a random number in [2..n-2]
	// Corner cases make sure that n > 4
	int a = 2 + rand() % (n - 4);

	// Compute a^d % n
	int x = Power(a, d, n);

	if (x == 1 || x == n - 1)
		return true;

	// Keep squaring x while one of the following doesn't
	// happen
	// (i)   d does not reach n-1
	// (ii)  (x^2) % n is not 1
	// (iii) (x^2) % n is not n-1
	while (d != n - 1)
	{
		x = (x * x) % n;
		d *= 2;

		if (x == 1)      return false;
		if (x == n - 1)    return true;
	}

	// Return composite
	return false;
}

int MillerRabin::Power(int x, unsigned int y, int p)
{
	int res = 1;      // Initialize result
	x = x % p;

	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res * x) % p;

		// y should be even
		y = y >> 1; // y = y/2
		x = (x * x) % p;
	}
	return res;
}

void MillerRabin::Print(int LimitNumber)
{
	int k = 4;  // Number of iterations

	cout << "All Prime numbers smaller than " << LimitNumber << " -> \n";
	for (int n = 1; n < LimitNumber; n++)
	{
		if (IsPrime(n, k))
			cout << "-" << n << endl;
	}

	cout << "\n";
}
