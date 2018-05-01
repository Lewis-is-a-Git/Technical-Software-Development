#include "BullsAndCows.h"
#include <cstdlib>
#include <algorithm>
using namespace std;

BullsAndCows::BullsAndCows()
{
    for (int i = 0; i < 9; i++)
    {
        fSecretNumbers[i] = i + 1;
    }   
}
void BullsAndCows::start()
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
void BullsAndCows::guess( std::string aNumberString )
{
    fBulls = 0;
    fCows = 0;
    for (int i = 0; i < 4; i++)
    {
        int lTest = aNumberString[i] - '0';
        if (fSecretNumbers[i] == lTest)
        {
            fBulls = fBulls + 1;
        }
        else
        {
            for (int j = 0; j < 4; j++)
            {
                if (fSecretNumbers[j] == lTest)
                {
                    fCows = fCows + 1;
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