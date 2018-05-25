#pragma once
#include <ostream>
class ArraySorter
{
private:
 int fArray[10];
public:
 ArraySorter( int aArray[10] );
 long sortByFisherAndYates();
 long sortByBubbleSort();
 int getElement( unsigned int aIndex ) const;
};
std::ostream& operator<<( std::ostream& aOStream, const ArraySorter& aObject );