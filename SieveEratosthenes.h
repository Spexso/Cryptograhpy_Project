#pragma once
#pragma once

#include <iostream>
#include <vector>

using namespace std;

class SieveEratosthenes
{

public:

	SieveEratosthenes();
	~SieveEratosthenes();
	void Base(int LimitNumber);
	void Print(vector<bool> prime, int LimitNumber);
};

