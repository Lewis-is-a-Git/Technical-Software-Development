#include "BullsAndCows.h"
#include <cstdlib>
#include <algorithm>
using namespace std;

BullsAndCows::BullsAndCows()
{
    for (int i = 0; i < 9; i++)
    {
        fSecretNumbers[i] = i + 1; // constructor initalises an array from 1 to 9
    }   
}
void BullsAndCows::start() //scrambles the array
{
    srand(time(NULL));
    int n = 9;
    while (n > 1)
    {
        int k = rand() % n;
        n--;
        swap(fSecretNumbers[n], fSecretNumbers[k]);
    }
}
void BullsAndCows::guess( std::string aNumberString ) //string of guesses
{
    fBulls = 0;
    fCows = 0;
    for (int i = 0; i < 4; i++)
    {
        int lTest = aNumberString[i] - '0';
        if (fSecretNumbers[i] == lTest)
        {
            fBulls = fBulls + 1; //check if any numbers are in the correct place
        }
        else
        {
            for (int j = 0; j < 4; j++)
            {
                if (fSecretNumbers[j] == lTest)
                {
                    fCows = fCows + 1; //check if any numbers are correct but in the wrong place
                }
            }
        }   
    }
}
int BullsAndCows::getBulls() const
{
    return fBulls;
}
int BullsAndCows::getCows() const
{
    return fCows;
}
