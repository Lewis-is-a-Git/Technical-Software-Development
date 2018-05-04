#include <iostream>
class Resistor
{
  private:
    double fValue;

  public:
    Resistor(double aValue);
    virtual ~Resistor() {} // needed to allow for inheritance
    double getValue() const;
    virtual double getValueAtFrequency(double aFrequency) const;
    double getPotential(double aCurrent) const;
    double getCurrent(double aVoltage) const;
    double getPotentialAtFrequency(double aCurrent, double aFrequency) const;
    double getCurrentAtFrequency(double aVoltage, double aFrequency) const;
};
std::ostream &operator<<(std::ostream &aOStream, const Resistor &aObject);