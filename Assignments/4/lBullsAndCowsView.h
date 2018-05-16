/*
* Specification of lBullsAndCowsView
* Abstract class that serves an interface to decouple the model and view
* @author convenor
*/
#pragma once
#include <string>
class lBullsAndCowsView
{
	public:
		// Destructor
		virtual ~lBullsAndCowsView() {}
		/*This method interacts with the user.It asks the user to guess the 
		secret number.The user input is returned as result.We assume a 
		reasonable player and omit error checking.This method expects a 
		string with 4 different numbers and once the user has enter it, 
		this string is returned. */
		virtual std::string guess() = 0;
		// This method prints the number of bulls and cows guessed. This 
		// information is available through the corresponding parameter values.
		virtual void showGuess( int aBulls, int aCows ) = 0;
		// This method sends a greeting to the user. 
		virtual void welcome() = 0;
		// This method announces that a new game has started (console output).
		virtual void startNewGame() = 0;
		// This method interacts with the user and requires a Yes/No response
		virtual bool continueGame() = 0;
		// This indicates that the game has ended.
		virtual void endGame() = 0;
};