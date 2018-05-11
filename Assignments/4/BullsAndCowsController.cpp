#include "BullsAndCowsController.h"
#include <string>
#include <iostream>
using namespace std;

 void BullsAndCowsController::startNewGame()
 {

 }
 /**
 * This method implements the guessing phase. It has to request a guess
 * from the user interface and test it with the model. The result should
 * be displayed in the user interface.
 *
 * @return true if the number of correctly guessed bulls is 4.
 */
 bool BullsAndCowsController::guess()
 {
     return fGameModel.getBulls() == 4;
 }

//public:
 /**
 * Constructor: Instantiates an object of class BullsAndCowsController.
 * The constructor establishes the references to model
 * and view objects. This is done by using a member
 * initializer for each.
 */
 BullsAndCowsController::BullsAndCowsController( BullsAndCows& aGameModel, lBullsAndCowsView& aGameView ):
    fGameModel(aGameModel), fGameView(aGameView)
 {
 }
 /**
 * This method implements the "game loop". It asks the connected view to
 * to emit a welcome message and then initializes the random number generator,
 * so that the game produces different sequences every time it is played.
 * Compare with solution for problem set 3.
 * Then the game loop starts which repeatedly starts a new game and asks
 * the user to make guesses until all bulls have been found.
 * The method run coordinates these activities.
 * Selecting “n” as response to the question “New game, Y/N?”
 * breaks the “game loop”. In this case, the application has to
 * gracefully terminate with a “Game over, Good bye.” message.
 */
 void BullsAndCowsController::run()
 {
     do
     {
         fGameView.welcome();
         fGameModel.start();
         fGameView.startNewGame();
         do
         {
            fGameModel.guess(fGameView.guess());
            fGameView.showGuess(fGameModel.getBulls(), fGameModel.getCows());
         }
         while (!guess());
     }
     while (fGameView.continueGame());
     fGameView.endGame();
 }
