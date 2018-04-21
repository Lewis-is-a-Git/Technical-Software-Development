#include "Dealer.h"

#include <stdexcept>
#include <iostream>

using namespace std;

Dealer::Dealer()
{
    //initially empty
}
void Dealer::startNewGame()
{
    fDeck.shuffle();
}

void Dealer::dealCards( Card aCardArray[5], int aNumberOdCards)
{
    try
    {
        for (int i = 0; i < aNumberOdCards; i++)
        {
            aCardArray[i] = fDeck.drawCard();
        }
    }
    catch (const std::exception& e)
    {
        cerr << "Out of Range error: " << e.what() << endl;
    }
}

int Dealer::replaceCards(Card aCardArray[5], const string& aHoldString)
{
    int lNumberOfCards = 5 - aHoldString.length();
    dealCards(aCardArray, lNumberOfCards);
    return lNumberOfCards;
}