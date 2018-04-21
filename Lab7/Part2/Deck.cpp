#include "Deck.h"

#include <cstdlib>
#include <stdexcept>

using namespace std;

Deck::Deck()
{
    int iCard = 0;
    for (int iSuit = Club; iSuit <= Spade; iSuit++)
    {
        for (int iValue = 2; iValue <= 14; iValue++)
        {
            fCards[iCard++] = Card((CardSuit)iSuit, iValue);
        }
    }
    fCardIndex = 0;
}
void Deck::shuffle()
{
    //Fisher and yates shuffling
    int n = 52;
    while (n > 1)
    {
        //new random index
        int k = rand() % n;
        n--;
        swap(fCards[n], fCards[k]);
    }
    fCardIndex = 0;
}
const Card& Deck::drawCard()
{
    if (fCardIndex < 52)
        return fCards[fCardIndex++];
    else
        throw out_of_range("Invalid Index");
}