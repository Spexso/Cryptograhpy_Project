#pragma once
#include <iostream>
#include <vector>

using namespace std;

class SieveAtkin
{

public:

	SieveAtkin();
	~SieveAtkin();
	void Base(int LimitNumber);
	void Print(vector<bool> prime, int LimitNumber);
};

