/**
* Specification of BullsAndCowsConsoleView
* Subclass of lBullsAndCowsView.h
* @author convenor
*/
#pragma once
#include "lBullsAndCowsView.h"
class BullsAndCowsConsoleView : public lBullsAndCowsView
{
	public:
		virtual std::string guess();
		virtual void showGuess( int aBulls, int aCows );
		virtual void welcome();
		virtual void startNewGame();
		virtual bool continueGame();
		virtual void endGame();
};