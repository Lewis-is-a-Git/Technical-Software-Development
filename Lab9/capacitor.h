#include "resistor.h"
class Capacitor : public Resistor
{
  public:
    Capacitor(double aValue);
    virtual double getValueAtFrequency(double aFrequency) const;
};
std::ostream &operator<<(std::ostream &aOStream, const Capacitor &aObject);