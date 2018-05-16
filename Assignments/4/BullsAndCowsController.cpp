/**
* Implementation of BullsAndCowsController
* @author Lewis Brockman-Horsley
*/
#include "BullsAndCowsController.h"
#include <string>
#include <iostream>
using namespace std;

void BullsAndCowsController::startNewGame()
{
	fGameView.welcome(); //welcome message
	fGameModel.start(); //creates the random solution array
	fGameView.startNewGame(); //new game message
}
/**
* This method implements the guessing phase. It has to request a guess
* from the user interface and test it with the model. The result should
* be displayed in the user interface.
* @return true if the number of correctly guessed bulls is 4.
*/
bool BullsAndCowsController::guess()
{
	return fGameModel.getBulls() == 4;
}
/**
* Constructor: Instantiates an object of class BullsAndCowsController.
* The constructor establishes the references to model
* and view objects. This is done by using a member
* initializer for each.
*/
BullsAndCowsController::BullsAndCowsController(BullsAndCows& aGameModel, 
	lBullsAndCowsView& aGameView) : 
		fGameModel(aGameModel), fGameView(aGameView) {}
/**
* This method implements the "game loop". 
* Selecting “n” as response to the question “New game, Y/N?”
* breaks the “game loop”. In this case, the application has to
* gracefully terminate with a “Game over, Good bye.” message.
*/
void BullsAndCowsController::run()
{
	do
	{
		startNewGame(); //creates the array and prints the welcome messages
		do
		{
			//calcualte the number of cows and bulls based on the players guess
			fGameModel.guess(fGameView.guess()); 
			//print the number of bulls and cows to the console
			fGameView.showGuess(fGameModel.getBulls(), fGameModel.getCows()); 
		} while (!guess()); //if the player has not won yet, continue the game
	} while (fGameView.continueGame()); //ask the player to start a new game
	fGameView.endGame(); //game over message
}