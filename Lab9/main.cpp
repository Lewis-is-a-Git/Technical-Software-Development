#include "capacitor.h"

using namespace std;

int main()
{
    Resistor lR1(56);
    cout << "Resistor: " << lR1 << endl;
    cout << "Current at 9.0V: " << lR1.getCurrent(9.0) << "A" << endl;
    cout << "Voltage at 200mA: " << lR1.getPotential(0.2) << "V" << endl;

    Capacitor lC1(0.0000047);
    cout << "Capacitor: " << lC1 << endl;
    cout << "XC at 60Hz: " << Resistor(lC1.getValueAtFrequency(60)) << endl;
    cout << "Current at 9V and 60Hz: " << lC1.getCurrentAtFrequency(9.0, 60)
         << "A" << endl;
    cout << "Voltage at 2mA and 60Hz: " << lC1.getPotentialAtFrequency(0.002, 60)
         << "V" << endl;

    cout << "Time Series Capacitor" << endl;
    int i = 0;
    Capacitor lC2(0.00022);
    while ( Resistor(lC2.getValueAtFrequency(i)).getValue() > 10)
    {
        cout << "XC at " << i << "Hz: " << Resistor(lC2.getValueAtFrequency(i)) << endl;
        i += 50;
    }
    return 0;
}