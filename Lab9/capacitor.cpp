#include <cmath>
#include "capacitor.h"
Capacitor::Capacitor(double aValue) : Resistor(aValue){}
double Capacitor::getValueAtFrequency(double aFrequency) const
{
    const double PI = 4.0 * atan(1.0);
    return 1 / ( 2 * PI * aFrequency * getValue());
}
std::ostream &operator<<(std::ostream &aOStream, const Capacitor &aObject)
{
    aOStream << aObject.getValue() << "F"; 
    return aOStream;
}