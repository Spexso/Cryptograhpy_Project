#pragma once
#include <iostream>

using namespace std;

class MillerRabin
{
public:
	MillerRabin();
	~MillerRabin();

	bool IsPrime(int n, int k);
	bool Base(int d, int n);
	int Power(int x, unsigned int y, int p);
	void Print(int LimitNumber);
};
