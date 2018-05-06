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
    if (aObject.getValue() < 0.000000001)
    {
        aOStream << aObject.getValue() * 1000000000000 << "pF"; 
    }
    else if (aObject.getValue() < 0.000001)
    {
        aOStream << aObject.getValue() * 1000000000 << "nF"; 
    }
    else if (aObject.getValue() < 0.001)
    {
        aOStream << aObject.getValue() * 1000000 << "uF"; 
    }
    else if (aObject.getValue() < 1)
    {
        aOStream << aObject.getValue() * 1000 << "mF"; 
    }
    else
    {
        aOStream << aObject.getValue() << "F"; 
    }
    return aOStream;
}
