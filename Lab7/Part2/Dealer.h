#pragma once
#include "Deck.h"
#include <string>
class Dealer
{
    private:
        Deck fDeck;
    public:
        Dealer();
        void startNewGame();
        void dealCards( Card aCardArray[5], int aNumberOfCards = 5 );
        int replaceCards( Card aCardArray[5], const std::string& aHoldString );
};