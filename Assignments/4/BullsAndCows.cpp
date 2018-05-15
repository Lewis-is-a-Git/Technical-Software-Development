/**
* Implementation of class BullsAndCows.
* @author convener
* @version v5 (SWE20004, 2018)
*/																			// 2/2

#include "BullsAndCows.h"													// 2
#include <iostream>															// 2
#include <cstdlib>															// 2/6
#include <time.h>

using namespace std;
/**
* Constructor: Instantiates an object of class BullsAndCows.
* 				The constructor sets up an array of 9 unique
* 				integers between 1 and 9.
*/																			// 2
BullsAndCows::BullsAndCows()
{
	for (int i = 0; i < 9; i++)											// 3
		fSecretNumbers[i] = i + 1;											// 3/8
}
/**
* This method rearranges the numbers in the internal
* integer array. This way we create a new "secret number."
* We use the Fisher&Yates shuffling method for this purpose, where
* n is 9.
*/																			// 2
void BullsAndCows::start()
{
	srand(time(NULL));
	// Fisher & Yates shuffling
	int n = 9;
	while (n > 1)
	{
		// new random index in the range 0 to n
		int k = rand() % n;
		n--;					// n last pertinent index
		swap(fSecretNumbers[n], fSecretNumbers[k]);	// algorithm library
	}																		// 5/7
}
/**
* This method determines the number of Bulls and Cows in the player's
* 4-digit guessed number.
* @param aNumberString		The player's guessed 4-digit number.
*
*/																			// 2
void BullsAndCows::guess(string aNumberString)
{
	// fresh start
	fBulls = 0;                                                             // 2
	fCows = 0;                                                              // 2

	for (int i = 0; i < 4; i++)											// 3
	{
		int lTest = aNumberString[i] - '0';									// 3

		if (fSecretNumbers[i] == lTest)									// 2
		{
			fBulls++;														// 1
		}
		else
		{
			for (int j = 0; j < 4; j++)									// 3
			{
				if (fSecretNumbers[j] == lTest)							// 2
				{
					fCows++;												// 1
																			// finished with lTest
					break;													// 1/22
				}
			}
		}
	}
}
/**
* Getter for number of bulls in last guess.
* @return The number of bulls (correctly placed digits).
*/                                                                         // 2
int BullsAndCows::getBulls() const
{
	return fBulls;                                                          // 1/3
}
/**
* Getter for number of cows in last guess.
* @return The number of cows (correctly guessed digits).
*/                                                                         // 2
int BullsAndCows::getCows() const
{
	return fCows;                                                           // 1/3
}
