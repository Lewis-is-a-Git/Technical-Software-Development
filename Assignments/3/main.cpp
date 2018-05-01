#include <iostream> // include standard IO library
#include "BullsAndCows.h" // include Bulls and Cows class
using namespace std;
/**
* Bulls and Cows is a code-breaking round-based game where the player must guess the correct numbers in the correct sequence.
* The player must enter four different integers from 1 to 9. and guess the randomly generated code to win the game.
* The format required is: 1234, no spaces, characters or brackets allowed.
*/
int main()
{
    BullsAndCows lGame;
    bool lPlayAgain = true;
    cout << "Bulls and Cows, brought to you by Lewis Brockman-Horsley (101533222)" << endl;
    while (lPlayAgain)
    {
        cout << "New game" << endl;
        lGame.start();
        string lInput;
        do
        {
            cout << "Make a guess: ";
            cin >> lInput;
            lGame.guess(lInput);

            cout << "Number of bulls: " << lGame.getBulls()
                 << ", number of cows: " << lGame.getCows() << endl;
        } while (lGame.getBulls() != 4);
        cout << "New game, Y/N? ";
        cin >> lInput;
        if (lInput[0] != 'Y')
        {
            lPlayAgain = lInput[0] == 'y';
        }
    }
    cout << "Game over. Good bye." << endl;

    return 0;
}
