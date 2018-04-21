#pragma once
#include "Card.h"
class Deck
{
    private:
        Card fCards[52];
        int fCardIndex;
    public:
        Deck();
        void shuffle();
        const Card& drawCard();
};