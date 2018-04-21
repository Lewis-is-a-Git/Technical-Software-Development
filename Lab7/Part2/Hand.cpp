
// SWE20004, Tutorial 7, 2017

#include "Hand.h"
#include "Card.h"

#include <cstdlib>

using namespace std;

/**
 * The method isFlush tests if the card array aCards contains
 * five cards of the same suit. In Poker terms, this is a Flush.
 *
 * Example: 9S 3S QS TS AS
 *
 * @param aCards	An array of five (sorted) Card objects.
 *
 * @return True, if the five cards all have the same suit.
 */
bool isFlush( Card aCards[5] )
{
	CardSuit lSuit = aCards[0].getSuit();

	for ( int i = 1; i < 5; i++ )
	{
		if ( aCards[i].getSuit() != lSuit )
		{
			return false;
		}
	}

	return true;
}

/**
 * The method isStraight tests if the sorted card array aCards contains
 * five cards in a consecutive order. In Poker terms, this is a Straight.
 *
 * Example: 8C 9S TC JC QH
 *
 * @param aCardsSorted	An array of five sorted Card objects.
 *
 * @return True, if the five cards constitute a Straight.
 */
bool isStraight( Card aCardsSorted[5] )
{
	for ( int i = 0; i < 4; i++ )
	{
		if ( aCardsSorted[i].getValue() + 1 != aCardsSorted[i+1].getValue() )
		{
			return false;
		}
	}

	return true;
}

/**
 * The method isStraightFromAce tests if the sorted card array aCards contains
 * five cards in a consecutive order, where an ace is the first card.
 * In Poker terms, this is a Straight from the ace.
 *
 * Note, the ace occurs as the last element in the array aCardSorted.
 *
 * Example: AC 2H 3D 4C 5C
 *
 * @param aCardsSorted	An array of five sorted Card objects.
 *
 * @return True, if the five cards constitute a Straight.
 *
 * @see isStraight( Card aCardsSorted[5] )
 */
bool isStraightFromAce( Card aCardsSorted[5] )
{
	return aCardsSorted[0].getValue() == 2 &&
		   aCardsSorted[1].getValue() == 3 &&
		   aCardsSorted[2].getValue() == 4 &&
		   aCardsSorted[3].getValue() == 5 &&
		   aCardsSorted[4].getValue() == 14;
}

/**
 * The method isFourOfAKind tests if the sorted card array aCards contains
 * four cards with the same face value. In Poker terms, this is a Four of a Kind.
 *
 * Note, there are two possible groupings: 0-3 and 1-4
 *
 * Example: 5C 5D 5H 5S QH
 *
 * @param aCardsSorted	An array of five sorted Card objects.
 *
 * @return True, if the five cards contain four cards with the same face value.
 */
bool isFourOfAKind( Card aCardsSorted[5] )
{
	return
		( aCardsSorted[0].getValue() == aCardsSorted[1].getValue() &&
		  aCardsSorted[1].getValue() == aCardsSorted[2].getValue() &&
		  aCardsSorted[2].getValue() == aCardsSorted[3].getValue() )
		||
		( aCardsSorted[1].getValue() == aCardsSorted[2].getValue() &&
		  aCardsSorted[2].getValue() == aCardsSorted[3].getValue() &&
		  aCardsSorted[3].getValue() == aCardsSorted[4].getValue() );
}

/**
 * The method isFullHouse tests if the sorted card array aCards contains
 * two groups: three cards with the same face value and any pair (two cards
 * with the same face value). In Poker terms, this is a Full House.
 *
 * Note, there are two possible groupings: 0-2 and 3,4
 *                                         0,1 and 2-4
 *
 * Example: 8C 8S KC KH KD
 *
 * @param aCardsSorted	An array of five sorted Card objects.
 *
 * @return True, if the five cards three cards with the same face value and
 * any pair (two cards with the same face value).
 */
bool isFullHouse( Card aCardsSorted[5] )
{
	return
		( aCardsSorted[0].getValue() == aCardsSorted[1].getValue() &&
		  aCardsSorted[1].getValue() == aCardsSorted[2].getValue() &&
		  aCardsSorted[3].getValue() == aCardsSorted[4].getValue() )
		||
		( aCardsSorted[0].getValue() == aCardsSorted[1].getValue() &&
		  aCardsSorted[2].getValue() == aCardsSorted[3].getValue() &&
		  aCardsSorted[3].getValue() == aCardsSorted[4].getValue() );
}

/**
 * The method isThreeOfAKind tests if the sorted card array aCards contains
 * three cards with the same face value. In Poker terms, this is a Three of a Kind.
 *
 * Note, there are two possible groupings: 0-2, 1-3, and 2-4
 *
 * Example: 4C 4D 4S TD QH
 *
 * @param aCardsSorted	An array of five sorted Card objects.
 *
 * @return True, if the five cards three cards with the same face value.
 */
bool isThreeOfAKind( Card aCardsSorted[5] )
{
	return
		( aCardsSorted[0].getValue() == aCardsSorted[1].getValue() &&
		  aCardsSorted[1].getValue() == aCardsSorted[2].getValue() )
		||
		( aCardsSorted[1].getValue() == aCardsSorted[2].getValue() &&
		  aCardsSorted[2].getValue() == aCardsSorted[3].getValue() )
		||
		( aCardsSorted[2].getValue() == aCardsSorted[3].getValue() &&
		  aCardsSorted[3].getValue() == aCardsSorted[4].getValue() );
}

/**
 * The method isTwoPairs tests if the sorted card array aCards contains two pairs
 * (two cards with the same face value) In Poker terms, this is a Two Pairs.
 *
 * Note, there are two possible groupings: 0-1 and 2-3
 * 										   0-1 and 3-4
 * 										   1-2 and 3-4
 *
 * In addition, this method returns true also, if the two pairs have the same face
 * value (i.e., Four of a Kind). Hence, when computing the score of a hand, the
 * method isFourOfAKind has to be called before this method is invoked.
 *
 * Example: 7C 7D QH QS AC
 *
 * @param aCardsSorted	An array of five sorted Card objects.
 *
 * @return True, if the five cards contain two pairs.
 *
 * @see isFourOfAKind( Card aCardsSorted[5] )
 */
bool isTwoPairs( Card aCardsSorted[5] )
{
	return
		( aCardsSorted[0].getValue() == aCardsSorted[1].getValue() &&
		  aCardsSorted[2].getValue() == aCardsSorted[3].getValue() )
		||
		( aCardsSorted[0].getValue() == aCardsSorted[1].getValue() &&
		  aCardsSorted[3].getValue() == aCardsSorted[4].getValue() )
		||
		( aCardsSorted[1].getValue() == aCardsSorted[2].getValue() &&
		  aCardsSorted[3].getValue() == aCardsSorted[4].getValue() );
}

/**
 * The method isJacksOrBetter tests if the sorted card array aCards contains at least
 * two cards with the same face value better than 10.
 * In Poker terms, this is a Jacks or Better.
 *
 * Note, there are two possible groupings: 0,1
 * 										   1,2
 * 										   2-3
 * 										   3,4
 *
 *
 * Example: 7C 8D QH QS AC
 *
 * @param aCardsSorted	An array of five sorted Card objects.
 *
 * @return True, if the five cards contain a pair Jacks or better.
 */
bool isJacksOrBetter( Card aCardsSorted[5] )
{
	return
		( aCardsSorted[0].getValue() > 10 &&
		  aCardsSorted[0].getValue() == aCardsSorted[1].getValue() )
		||
		( aCardsSorted[1].getValue() > 10 &&
		  aCardsSorted[1].getValue() == aCardsSorted[2].getValue() )
		||
		( aCardsSorted[2].getValue() > 10 &&
		  aCardsSorted[2].getValue() == aCardsSorted[3].getValue() )
		||
		( aCardsSorted[3].getValue() > 10 &&
		  aCardsSorted[3].getValue() == aCardsSorted[4].getValue() );
}

/**
 * The method sortCards takes an array with five Card objects and
 * uses bubble sort to arrange the Card objects in increasing order
 * according to the Card operator >.
 *
 * @param aCards	An array of five unsorted Card objects.
 *
 * @see bool Card::operator>( const Card& aOtherCard ) const
 */
void sortCards( Card aCards[5] )
{
	// bubble sort
	for ( int high = 1; high < 5; high++ )
	{
		for( int low = 0; low < high; low++ )
		{
			if( aCards[low] > aCards[high] )
			{
				swap( aCards[low], aCards[high] );
			}
		}
	}
}

/**
 * The method sortCards takes an array with five Card objects and
 * computes the score according to the scoring table:
 *
 * Royal Flush:		10	A straight to the ace in the same suit
 * Straight Flush:	9	A straight in the same suit
 * Four of a Kind:	8	Four cards of the same face value
 * Full House:		7	Three of a kind with any pair
 * Flush:			6	5 cards of the same suit
 * Straight:		5	5 cards with consecutive face values
 * Three of a Kind:	4	Three cards of the same face value
 * Two Pairs:		3	Any pair with any pair
 * Jacks or Better:	2	A pair of jacks, queens, kings, or aces
 *
 * @param aCards	An array of five unsorted Card objects.
 *
 * @return The score assigned to the five Card objects.
 *
 * @see isFlush( Card aCards[5] )
 * @see isStraight( Card aCardsSorted[5] )
 * @see isStraightFromAce( Card aCardsSorted[5] )
 * @see isFourOfAKind( Card aCardsSorted[5] )
 * @see isFullHouse( Card aCardsSorted[5] )
 * @see isThreeOfAKind( Card aCardsSorted[5] )
 * @see isTwoPairs( Card aCardsSorted[5] )
 * @see isJacksOrBetter( Card aCardsSorted[5] )
 */
int calculateScore( Card aCards[5] )
{
	Card lSortedCards[5];

	for ( int i = 0; i < 5; i++ )
	{
		lSortedCards[i] = aCards[i];
	}

	sortCards( lSortedCards );

	bool lIsFlush = isFlush( lSortedCards);
	bool lIsStraight = isStraight( lSortedCards );
	bool lIsTopStraight = lIsStraight && lSortedCards[4].getValue() == 14;

	// royal flush...
	if ( lIsTopStraight && lIsFlush )
		return 10;

	// straight flush...
	if ( lIsStraight && lIsFlush )
		return 9;

	// four of a kind...
	if ( isFourOfAKind( lSortedCards ) )
		return 8;

	// full house...
	if ( isFullHouse( lSortedCards ) )
		return 7;

	// flush...
	if ( lIsFlush )
		return 6;

	// straight...
	if ( lIsStraight )
		return 5;

	// three of a kind...
	if ( isThreeOfAKind( lSortedCards ) )
		return 4;

	// two pairs...
	if ( isTwoPairs( lSortedCards ) )
		return 3;

	// jacks or better...
	if ( isJacksOrBetter( lSortedCards ) )
		return 2;

	return 0;
}

// Hand methods

string HandScores[] =
{
	"No Score",
	"",
	"Jacks or Better",
	"Two Pairs",
	"Three of a Kind",
	"Straight",
	"Flush",
	"Full House",
	"Four of a Kind",
	"Straight Flush",
	"Royal Flush"
};

Hand::Hand()
{
	fScore = -1;
}
void Hand::initialize( Card aCards[5])
{
	for (int i = 0; i < 5; i++)
	{
		fCards[i] = aCards[i];
	}
	fScore = -1;
}
void Hand::replaceCards( Card aCards[], const string& aHoldString)
{
	int n = 0;
	for (int i = 0; i < 5; i++)
	{
		if (aHoldString.find('1' + i) == string::npos)
		{
			fCards[i] = aCards[n++];
		}
	}
}
string Hand::getHandString() const
{
	string Result;
	for (int i = 0; i < 5; i++)
	{
		Result += fCards[i].getName();
		if (i < 4)
		{
			Result += " ";
		}
	}
	return Result;
}
int Hand::getScore()
{
	if (fScore < 0)
	{
		fScore = calculateScore(fCards);
	}
	return fScore;
}
const string& Hand::getScoreTitle()
{
	return HandScores[getScore()];
}
ostream& operator<<(std::ostream& aOStream, const Hand& aHand)
{
	aOStream << aHand.getHandString();

	return aOStream;
}