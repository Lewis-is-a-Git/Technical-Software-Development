
/**
 * This is a simple console Video Poker program.
 *
 * @author Convener
 * @version v1.1 (SWE20004, 2017)
 *
 */

#include "Card.h"
#include "Deck.h"
#include "Dealer.h"
#include "Hand.h"

#include <iostream>
#include <string>

using namespace std;

/**
 * The function filterHoldString takes a string argument and
 * performs a soundness analysis. It filters out all characters
 * but '1', '2', '3', '4', and '5' as well as all duplicates.
 *
 * @param aHoldString 	A constant reference to the hold string
 *
 * @return A new string containing unique positions 1-5.
 *
 */
string filterHoldString( const string& aHoldString )
{
	string Result;

	for ( int i = 0; i < 5; i++ )
	{
		if ( aHoldString.find( '1' + i ) != string::npos )
			Result += '1' + i;
	}

	return Result;
}

/*
 * The main entry point. It contains the "game loop."
 *
 * Video Poker is an interactive game, hence, there are no command arguments.
 *
 */

int main()
{
	Dealer lDealer;
	Hand lHand;
	Card lCardTray[5];
	string lHoldString;
	bool lContinue = true;

	cout << "Welcome to Console Video Poker" << endl;

	while ( lContinue )
	{
		cout << "New game" << endl;

		lDealer.startNewGame();
		lDealer.dealCards( lCardTray );

		lHand.initialize( lCardTray );
		cout << "Hand: " << lHand << endl;

		cout << "Select to cards to hold [12345]: ";
		cin >> lHoldString;

		lHoldString = filterHoldString( lHoldString );

		lDealer.replaceCards( lCardTray, lHoldString );
		lHand.replaceCards( lCardTray, lHoldString );

		cout << "Hand: " << lHand << endl;
		cout << "Score: " << lHand.getScoreTitle() << endl;

		cout << "New game, Y/N? ";
		cin >> lHoldString;
		if ( lHoldString[0] != 'Y' )
		{
			lContinue = lHoldString[0] == 'y';
		}
	}

	cout << "Game over. Good bye." << endl;

	return 0;
}
