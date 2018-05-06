/**
* Inheritance and Method Overiding
* Purpose: Simulate a Single Stage Common Emitter Amplifier Circuit.
* @author: Lewis Brockman-Horlsey
* Date Created: 4/5/2018
*/

#include "capacitor.h"

using namespace std;

int main()
{
    Resistor lR1(56); //create a resistor
    cout << "Resistor: " << lR1 << endl;
    cout << "Current at 9.0V: " << lR1.getCurrent(9.0) << "A" << endl;
    cout << "Voltage at 200mA: " << lR1.getPotential(0.2) << "V" << endl;

    Capacitor lC1(0.0000047); // create an equivalent resistor using the impedance of a capacitor
    cout << "Capacitor: " << lC1 << endl;
    cout << "XC at 60Hz: " << Resistor(lC1.getValueAtFrequency(60)) << endl;
    cout << "Current at 9V and 60Hz: " << lC1.getCurrentAtFrequency(9.0, 60)
         << "A" << endl;
    cout << "Voltage at 2mA and 60Hz: " << lC1.getPotentialAtFrequency(0.002, 60)
         << "V" << endl;
    //Create a time series printout to roughly deteremine the frequency that the capacitor has an impedance of 10ohms
    cout << "Time Series Capacitor" << endl; 
    int i = 50;
    Capacitor lC2(0.00022);
    while ( Resistor(lC2.getValueAtFrequency(i)).getValueAtFrequency(i) > 10); 
    {
        cout << "XC at " << i << "Hz: " << Resistor(lC2.getValueAtFrequency(i)) << endl;
        i += 50;
    }
    return 0;
}
