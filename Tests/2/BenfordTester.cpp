/**
 * @author Lewis Brockman-Horlsey 101533222
 */

#include "BenfordTester.h"

BenfordTester::BenfordTester()
{
    for (int i = 0; i < 9; i++)
    {
        fLeadingDigitCount[i] = 0;
    }
    
    fNumberOfDataEntries = 0;
}
void BenfordTester::collectData(std::istream &aIStream)
{
    int number;
    while (aIStream >> number)
    {
        while (number > 9)
        {
            number = number / 10;
        }
        fLeadingDigitCount[number - 1]++;
        fNumberOfDataEntries++;
    }
}

//getter for data set size
long BenfordTester::getDataSize() const
{
    return fNumberOfDataEntries;
}

//gettter for leading digit count
long BenfordTester::getLeadingDigitCount(unsigned int aLeadingDigit) const
{
    return fLeadingDigitCount[aLeadingDigit];
}

std::ostream &operator<<(std::ostream &aOStream, const BenfordTester &aObject)
{
    for (int i = 0; i < 9; i++)
    {
        aOStream << i + 1 << ": " << aObject.getLeadingDigitCount(i) / aObject.getDataSize() * 100
                 << "%" << std::endl; 
    }
    return aOStream;
}
