#include "Card.h"

using namespace std;

static string gCardSuits(" CDHS");
static string gCardValues("  23456789TJQKA");
Card::Card()
{
    fSuit = Blank;
    fValue = 0;
}

Card::Card(string aName)
{
    fSuit = (CardSuit)gCardSuits.find( aName[1]);
    fValue = gCardValues.find( aName[0]);
}

Card::Card(CardSuit aSuit, int aValue)
{
    fSuit = aSuit;
    fValue = aValue;
}
ostream& operator << (ostream& aOStream, const Card& aCard)
{
    aOStream << aCard.getName();

    return aOStream;
}
CardSuit Card::getSuit() const
{
    return fSuit;
}
int Card::getValue() const
{
    return fValue;
}
string Card::getName() const
{
    string Result;
    Result += gCardValues[fValue];
    Result += gCardSuits[fSuit];
}
bool Card::operator==(const Card& aOtherCard) const
{
    return fSuit == aOtherCard.fSuit && fValue == aOtherCard.fValue;
}
bool Card::operator>(const Card& aOtherCard) const
{
    //enable sorting based on value followed by suit
    if (fValue == aOtherCard.fValue)
    {
        return fSuit > aOtherCard.fSuit;
    }
    return fValue > aOtherCard.fValue;
}