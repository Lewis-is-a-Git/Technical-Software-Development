#include "resistor.h"
#include <cmath>
const double PI = 4.0 * atan(1.0);

Resistor::Resistor(double aValue)
{
    fValue = aValue;
}
double Resistor::getValue() const
{
    return fValue;
}
double Resistor::getValueAtFrequency(double aFrequency) const
{
    return 1/(2 * PI * aFrequency * fValue);
}
double Resistor::getPotential(double aCurrent) const
{
    return aCurrent * fValue;
}
double Resistor::getCurrent(double aVoltage) const
{
    return aVoltage / fValue;
}
double Resistor::getPotentialAtFrequency(double aCurrent, double aFrequency) const
{
    return aCurrent * 1/(2 * PI * aFrequency * fValue);
}
double Resistor::getCurrentAtFrequency(double aVoltage, double aFrequency) const
{
    return aVoltage / 1/(2 * PI * aFrequency * fValue);
}
std::ostream &operator<<(std::ostream &aOStream, const Resistor &aObject)
{
    if (aObject.getValue() >= 1000000)
    {
        aOStream << aObject.getValue() / 1000000 << "MOhms"; 
    }
    else if (aObject.getValue() >= 1000)
    {
        aOStream << aObject.getValue() / 1000 << "KOhms"; 
    }
    else
    {
        aOStream << aObject.getValue() << "Ohms"; 
    }
    return aOStream;
}
