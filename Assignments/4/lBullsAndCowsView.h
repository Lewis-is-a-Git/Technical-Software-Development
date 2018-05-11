#pragma once
#include <string>
class lBullsAndCowsView
{
public:
 virtual ~lBullsAndCowsView() {}
 virtual std::string guess() = 0;
 virtual void showGuess( int aBulls, int aCows ) = 0;
 virtual void welcome() = 0;
 virtual void startNewGame() = 0;
 virtual bool continueGame() = 0;
 virtual void endGame() = 0;
};