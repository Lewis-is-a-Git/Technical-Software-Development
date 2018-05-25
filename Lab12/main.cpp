#include <cstdlib>
#include <ctime>
#include <iostream>
#include "ArraySorter.h"
using namespace std;
void shuffleTest()
{
    cout << "Using Fisher & Yates :" << endl;
    for (int i = 0; i < 20; i++)
    {
        int lArray[10] = {5, 1, 0, 25, 350, 4, 75, 99, 3, 56};
        ArraySorter lSorter(lArray);
        time_t lStartTime = time(NULL);
        long lCount = lSorter.sortByFisherAndYates();
        time_t lEndTime = time(NULL);
        cout << "Array : " << lSorter << endl;
        cout << "Time elapsed : " << lEndTime - lStartTime << endl;
        cout << "Tests required : " << lCount << endl;
    }
}
void bubbleTest()
{
    cout << "Using Bubble Sort: " << endl;
    for (int i = 0; i < 20; i++)
    {
        int lArray[10] = {5, 1, 0, 25, 350, 4, 75, 99, 3, 56};
        ArraySorter lSorter(lArray);
        time_t lStartTime = time(NULL);
        long lCount = lSorter.sortByBubbleSort();
        time_t lEndTime = time(NULL);
        cout << "Array : " << lSorter << endl;
        cout << "Time elapsed : " << lEndTime - lStartTime << endl;
        cout << "Tests required : " << lCount << endl;
    }
}
int main()
{
    int lArray[] = {5, 1, 0, 25, 350, 4, 75, 99, 3, 56};
    srand((unsigned int)time(NULL));
    shuffleTest();
    bubbleTest();

    return 0;
}