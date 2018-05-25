#include <iostream>
#include <algorithm>
#include "ArraySorter.h"
ArraySorter::ArraySorter(int aArray[10])
{
    for (int i = 0; i < 10; i++)
    {
        fArray[i] = aArray[i];
    }
}

void shuffle(int aArray[10])
{
    int n = 10;
    while (n > 1)
    {
        int k = rand() % n;
        n--;
        std::swap(aArray[n], aArray[k]);
    }
}

long ArraySorter::sortByFisherAndYates()
{
    long lTestCount = 0;
    bool lIsSorted;
    do
    {
        lIsSorted = true;
        for (int i = 0; i < 9; i++) // run from 0 to N-2
        {
            lTestCount++;
            if (fArray[i] > fArray[i + 1])
            {
                lIsSorted = false;
                break;
            }
        }
        if (lIsSorted != true)
        {
            shuffle(fArray);
        }

    } while (lIsSorted != true);

    return lTestCount;
}
long ArraySorter::sortByBubbleSort()
{
    long lTestCount = 0;
    for (int i = 9; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            lTestCount++;
            if (fArray[j] > fArray[j + 1])
            {
                std::swap(fArray[j], fArray[j + 1]);
            }
        }
    }
    return lTestCount;
}
int ArraySorter::getElement(unsigned int aIndex) const
{
    return fArray[aIndex];
}

std::ostream& operator<<( std::ostream& aOStream, const ArraySorter& aObject )
{
    aOStream << "{ ";
    for (int i = 0; i < 10; i++)
    {
        aOStream << aObject.getElement(i) << " ";
    }
    aOStream << "}";
    return aOStream;
}