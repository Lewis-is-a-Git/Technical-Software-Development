#pragma once
#include <istream>
#include <ostream>
class BenfordTester
{
  private:
    long fLeadingDigitCount[9];
    long fNumberOfDataEntries;

  public:
    BenfordTester(); //constructor
    void collectData(std::istream &aIStream);

    //getter for data set size
    long getDataSize() const;

    //gettter for leading digit count
    long getLeadingDigitCount(unsigned int aLeadingDigit) const;
};
std::ostream &operator<<(std::ostream &aOStream, const BenfordTester &aObject);