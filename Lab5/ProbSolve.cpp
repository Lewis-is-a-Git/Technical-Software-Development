#include <iostream>
using namespace std;
bool checkRow(int aBoard[9][9], int aRowIndex)
{
    int checkArray[9] = {0};
    for (int i = 0; i < 9; i++)
    {
        checkArray[aBoard[aRowIndex][i]]++;
    }
    for (int j = 1; j < 9; j++)
    {
        if (checkArray[j] > 1)
        {
            return false;
        }
    }

    return true;
}
bool checkColumn(int aBoard[9][9], int aColumnIndex)
{
    int checkArray[9] = {0};
    for (int i = 0; i < 9; i++)
    {
        checkArray[aBoard[i][aColumnIndex]]++;
    }
    for (int j = 1; j < 9; j++)
    {
            if (checkArray[j] > 1)
            {
                return false;
            }
    }

    return true;
}
bool checkSquare(int aBoard[9][9], int aTopLeftRowIndex, int aTopLeftColumnIndex)
{

    int checkArray[9] = {0};
    for (int i = aTopLeftRowIndex; i < 3; i++)
    {
        for (int k = aTopLeftColumnIndex; k < 3; k++)
        {
            checkArray[aBoard[i][k]]++;
        }
        
    }
    for (int j = 1; j < 9; j++)
    {
            if (checkArray[j] > 1)
            {
                return false;
            }
    }
    return true;
}
bool checkBoard(int aBoard[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        if (!checkRow(aBoard, i))
        {
            
            cout << "Failed Row " << i << endl;
            return false;
        }
    }
    for (int j = 0; j < 9; j++)
    {
        if (!checkRow(aBoard, j))
        {
            cout << "Failed Column " << j << endl;
            return false;
        }
    }
    for (int l = 0; l < 3; l++)
    {
        for (int m = 0; m < 3; m++)
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