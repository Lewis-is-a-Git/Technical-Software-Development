#include "BullsAndCowsConsoleView.h"
#include <iostream>
using namespace std;
string BullsAndCowsConsoleView::guess()
{
    string playerGuess;
    cout << "Make a guess: ";
    cin >> playerGuess;
    cout << endl;
    return playerGuess;
}
void BullsAndCowsConsoleView::showGuess( int aBulls, int aCows )
{
    cout << "Number of Bulls: " << aBulls << ", number of Cows :" << aCows << endl;
}
void BullsAndCowsConsoleView::welcome()
{
    cout << "Bulls and Cows, brought to you by Lewis Brockman-Horlsey (101533222)" << endl;
}
void BullsAndCowsConsoleView::startNewGame()
{
    cout << "New Game" << endl;
}
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
void BullsAndCowsConsoleView::endGame()
{
    cout << "Game Over. Good bye";
}
