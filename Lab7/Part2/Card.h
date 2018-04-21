#pragma once
#include <string>
#include <iostream>
enum CardSuit { Blank, Club, Diamond, Heart, Spade };
class Card
{
    private:
        CardSuit fSuit;
        int fValue;
    public:
        Card();
        Card( CardSuit aSuit, int aValue );
        Card( std::string aName );
        CardSuit getSuit() const;
        int getValue() const;
        std::string getName() const;
        bool operator==( const Card& aOtherCard ) const;
        bool operator>( const Card& aOtherCard ) const;
};