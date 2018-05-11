#include "CalculatorConsoleView.h"
#include <iostream>
using namespace std;
 void CalculatorConsoleView::showWelcome()
 {
    //Send a welcome message to the user (e.g., console screen).
    cout << "Welcome to simple calculator" << endl;
 }
 void CalculatorConsoleView::showGoodBye()
 {
     //Send a good bye message to the user (e.g., console screen).
    cout << "thank you for using simple caclulator bye" << endl;
 }
 bool CalculatorConsoleView::more()
 {
     /* Asks the user whether to continue or not. The result is a Boolean value to indicate the
user’s decision. The user interaction must handle both upper case and lower case
responses */
    char choice;
    cout << "Do you wish to continue? [Y/N]: ";
    cin >> choice;
    cout << endl;
    if (choice == 'y' || choice == 'Y')
    {
        return true;
    }
    return false;
 }
 char CalculatorConsoleView::selectOperation()
 {
     /* This user interface method asks the user to select an operation. It should check for valid
responses (or guarantee them) and return the selected operation as a character. Valid
operation characters are: ‘+’, ‘-’, ‘*’, and ‘/’. */
    char operation;
    cout << "Select operation ( +, -, *, /): ";
    cin >> operation;
    cout << endl;
    return operation;
 }
 int CalculatorConsoleView::getOperand( std::string aOperandName )
 {
     /* This method requests an integer value from the user. It also indicates which operand is
to be given. The method takes one string argument indicating the required operand. */
    int number;
    cout << "enter the " << aOperandName << " number: ";
    cin >> number;
    return number;
 }
 void CalculatorConsoleView::showResult( int aValue )
 {
     //This user interface method displays the result passed to the method in its argument.
    cout << "Result = " << aValue << endl;
 }