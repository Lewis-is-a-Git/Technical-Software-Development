#pragma once
#include "BullsAndCows.h"
#include "lBullsAndCowsView.h"
class BullsAndCowsController
{
private:
 BullsAndCows& fGameModel; // reference to model object
 lBullsAndCowsView& fGameView; // reference to view object
 /**
 * This private method should be called by run to start a new game.
 * It must start a new game with both the view and the controller.
 */
 void startNewGame();
 /**
 * This method implements the guessing phase. It has to request a guess
 * from the user interface and test it with the model. The result should
 * be displayed in the user interface.
 *
 * @return true if the number of correctly guessed bulls is 4.
 */
 bool guess();
public:
 /**
 * Constructor: Instantiates an object of class BullsAndCowsController.
 * The constructor establishes the references to model
 * and view objects. This is done by using a member
 * initializer for each.
 */
 BullsAndCowsController( BullsAndCows& aGameModel, lBullsAndCowsView& aGameView );
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
 void run();
};