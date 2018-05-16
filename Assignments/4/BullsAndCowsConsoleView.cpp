/**
* Implementation of class BullsAndCowsConsoleView.
* @author Lewis Brockman-Horsley
* @version 1 (SWE20004, 2018)
*/
#include "BullsAndCowsConsoleView.h"
#include <iostream>
using namespace std;
// This method takes the input form the player
// @return the player guess string
string BullsAndCowsConsoleView::guess()
{
	string playerGuess;
	cout << "Make a guess: ";
	cin >> playerGuess;
	cout << endl;
	return playerGuess;
}
// This method displays the output result from the players guess
// @param aBulls The correct numbers in teh correct places
// @param aCows The correct numbers in the incorrect places
void BullsAndCowsConsoleView::showGuess(int aBulls, int aCows)
{
	cout << "Number of Bulls: " << aBulls 
		 << ", number of Cows: " << aCows << endl;
}
// This method displays a welcome message
void BullsAndCowsConsoleView::welcome()
{
	cout << "Bulls and Cows, "
		 << "brought to you by Lewis Brockman-Horlsey (101533222)" << endl;
}
//This method displays the new game message
void BullsAndCowsConsoleView::startNewGame()
{
	cout << "New Game" << endl;
}
// This method askes the player if they want to continue playing
// @return player wants to play again
bool BullsAndCowsConsoleView::continueGame()
{
	char lQuery;
	cout << "New Game? [Y/N]:";
	cin >> lQuery;
	cout << endl;
	if (lQuery == 'y' || lQuery == 'Y')
	{
		return true;
	}
	return false;
}
// This method displays a game over message
void BullsAndCowsConsoleView::endGame()
{
	cout << "Game Over. Good bye";
}