/**
 * ProbSolve.cpp
 * @author Lewis Brockman-Horsley
 * 
 * Program to check if a sudoku puzzle is correct
 * Checks for any duplicates on a row, column and square
 * Created: 6/4/18
 * */
#include <iostream>
using namespace std;
bool checkRow(int aBoard[9][9], int aRowIndex)
{
    int checkArray[9] = {0};        //check by making a running tally of the numbers on each row
    for (int i = 0; i < 9; i++)
    {
        checkArray[aBoard[aRowIndex][i]]++;
    }
    for (int j = 1; j < 9; j++)
    {
        if (checkArray[j] > 1)      //check if the amount of each number is more than 1
        {
            return false;
        }
    }

    return true;
}
bool checkColumn(int aBoard[9][9], int aColumnIndex)
{
    int checkArray[9] = {0};        //makes a running tally of the numbers in a column
    for (int i = 0; i < 9; i++)
    {
        checkArray[aBoard[i][aColumnIndex]]++;
    }
    for (int j = 1; j < 9; j++)
    {
            if (checkArray[j] > 1)  //checks to make sure there are no duplicates
            {
                return false;
            }
    }

    return true;
}
bool checkSquare(int aBoard[9][9], int aTopLeftRowIndex, int aTopLeftColumnIndex)
{

    int checkArray[9] = {0};        //makes a running tally of the numbers in one of the 9 3x3 squares
    for (int i = aTopLeftRowIndex; i < 3; i++)
    {
        for (int k = aTopLeftColumnIndex; k < 3; k++)
        {
            checkArray[aBoard[i][k]]++;
        }
        
    }
    for (int j = 1; j < 9; j++)
    {
            if (checkArray[j] > 1)  //checks the amount of each number in the sqaure
            {
                return false;
            }
    }
    return true;
}
bool checkBoard(int aBoard[9][9])
{
    for (int i = 0; i < 9; i++)     //checks all 9 rows
    {
        if (!checkRow(aBoard, i))
        {
            
            cout << "Failed Row " << i << endl;
            return false;
        }
    }
    for (int j = 0; j < 9; j++)
    {
        if (!checkRow(aBoard, j))   //checks all the columns
        {
            cout << "Failed Column " << j << endl;
            return false;
        }
    }
    for (int l = 0; l < 3; l++)     //checks 3 squares on a row
    {
        for (int m = 0; m < 3; m++) //checks 3 squares on each column
        {
            if (!checkSquare(aBoard, (l*3), (m*3)))
            {
                cout << "Failed Square " << l << " " << m << endl;
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int lBoard[9][9] = {
        { 5, 0, 0, 8, 0, 0, 7, 9, 0 },
        { 0, 0, 0, 1, 0, 0, 0, 3, 0 },
        { 0, 6, 9, 0, 0, 0, 8, 0, 0 },
        { 0, 4, 0, 6, 3, 0, 0, 0, 0 },
        { 1, 0, 2, 0, 0, 0, 3, 0, 6 },
        { 0, 0, 0, 0, 5, 1, 0, 7, 0 },
        { 0, 0, 1, 0, 0, 0, 9, 2, 0 },
        { 0, 2, 0, 0, 0, 4, 0, 0, 0 },
        { 0, 9, 6, 0, 0, 3, 0, 0, 8 }
        };
    
    if(checkBoard(lBoard))
    {
        cout << "Passes";
    }
    else
    {
        cout << "Found Double";
    }
    cout << endl;

    return 0;
}