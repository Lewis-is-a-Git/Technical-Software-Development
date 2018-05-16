/**
* Implementation of class BullsAndCows.
* @author convener
* @version v5 (SWE20004, 2018)
*/
#include "BullsAndCows.h"								
#include <iostream>							
#include <cstdlib>														
#include <time.h>

using namespace std;
/**
* Constructor: Instantiates an object of class BullsAndCows.
* 			   The constructor sets up an array of 9 unique
* 			   integers between 1 and 9.
*/							
BullsAndCows::BullsAndCows()
{
	for (int i = 0; i < 9; i++)					
		fSecretNumbers[i] = i + 1;						
}
/**
* This method rearranges the numbers in the internal
* integer array. This way we create a new "secret number."
* We use the Fisher&Yates shuffling method for this purpose, where
* n is 9.
*/																
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
	}												
}
/**
* This method determines the number of Bulls and Cows in the player's
* 4-digit guessed number.
* @param aNumberString		The player's guessed 4-digit number.
*/															
void BullsAndCows::guess(string aNumberString)
{
	// fresh start
	fBulls = 0;                                          
	fCows = 0;                                      

	for (int i = 0; i < 4; i++)							
	{
		int lTest = aNumberString[i] - '0';				

		if (fSecretNumbers[i] == lTest)					
		{
			fBulls++;									
		}
		else
		{
			for (int j = 0; j < 4; j++)								
			{
				if (fSecretNumbers[j] == lTest)				
				{
					fCows++;										
					break;		
				}
			}
		}
	}
}
/**
* Getter for number of bulls in last guess.
* @return The number of bulls (correctly placed digits).
*/                                                   
int BullsAndCows::getBulls() const
{
	return fBulls;                                   
}
/**
* Getter for number of cows in last guess.
* @return The number of cows (correctly guessed digits).
*/                                                         
int BullsAndCows::getCows() const
{
	return fCows;                                     
}
