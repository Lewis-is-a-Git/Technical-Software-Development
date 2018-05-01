#include <iostream> // include standard IO library
#include "BullsAndCows.h" // include Bulls and Cows class

using namespace std;

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
