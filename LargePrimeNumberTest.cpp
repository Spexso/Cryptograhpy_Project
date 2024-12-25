// LargePrimeNumberTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <chrono>
#include "Helpers.h"
#include "MillerRabin.h"
#include "SieveAtkin.h"
#include "SieveEratosthenes.h"

using String = std::string;
using namespace std;

void EasyPrint(String Text);
void Menu();


int main()
{
	int opt = 0;
	int SelectedNumber = 0;

	int32_t test[4] = { 2, 4, 12, 55 };
	MillerRabin* MillerRabinAlgorithm = new MillerRabin();
	SieveAtkin* SieveOfAtkinAlgorithm = new SieveAtkin();
	SieveEratosthenes* SieveOfEratosthenesAlgorithm = new SieveEratosthenes();

	// Input: Enter your Number
	//EasyPrint("Enter the Number: ");
	//cin >> SelectedNumber;

	// Input: Ask for user's Option

	while (opt != -1)
	{
		EasyPrint("\n");
		EasyPrint("\n");

		EasyPrint("Enter the Number: ");
		cin >> SelectedNumber;

		EasyPrint("\n");

		Menu();
		EasyPrint("Select your Algorithm: ");
		cin >> opt;

		switch (opt)
		{
		case 1:
			MillerRabinAlgorithm->Print(SelectedNumber);
			break;
		case 2:
			SieveOfAtkinAlgorithm->Base(SelectedNumber);
			break;
		case 3:
			SieveOfEratosthenesAlgorithm->Base(SelectedNumber);
			break;

		default:
			opt = -1;
			break;
		}
	}
}

void EasyPrint(String Text)
{
	cout << Text << "\n";

	return;
}


void Menu()
{
	EasyPrint("\n");
	EasyPrint("1- Miller Rabin");
	EasyPrint("2- Sieve of Atkin");
	EasyPrint("3- Sieve of Eratosthenes");
	EasyPrint("\n");
}















// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
