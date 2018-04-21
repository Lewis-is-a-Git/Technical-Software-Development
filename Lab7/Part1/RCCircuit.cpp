#include "RCCircuit.h"
#include <cmath>
#include <iostream>

using namespace std;

/**
 * Computes the charging voltage
 * @param aTimeStamp - time at which to calculate voltage
 * @param aBatteryVoltage - the battery viltage
 * 
 * @return The voltage accross the capacitor at time aTimeStamp
 * */

//constructor
RCCircuit::RCCircuit(double aResistorValue, double aCapacitorValue)
{
    fResistorValue = aResistorValue;
    fCapacitorValue = aCapacitorValue;
    fTimeConstant = fResistorValue * fCapacitorValue;
}
        //Vc(t)=Vb*(1-e^(-t/(RC)))
double RCCircuit::computeVoltageCharging(int aTimeStamp, double aBatteryVoltage) const {
    return aBatteryVoltage*(1-exp(-aTimeStamp/fTimeConstant));
}
        //Ic(t) = Vb/R * e^(-t/(RC))
double RCCircuit::computeCurrentCharging(int aTimeStamp, double aBatteryVoltage) const {
    return aBatteryVoltage*(1-exp(-aTimeStamp/fTimeConstant))/fResistorValue;
}
        //Vc(t)=Vb*e^(-t/(RC))
double RCCircuit::computeVoltageDischarging(int aTimeStamp, double aBatteryVoltage) const {
    return aBatteryVoltage * exp(-aTimeStamp/fTimeConstant);
}
        //Ic(t) = -Vb/R * e^(-t/(RC))
double RCCircuit::computeCurrentDischarging(int aTimeStamp, double aBatteryVoltage) const {
    return -aBatteryVoltage * exp(-aTimeStamp/fTimeConstant)/fResistorValue;
}
void RCCircuit::chargeFor(std::ostream& aOStream, double aBatteryVoltage, int aSeconds) const
{
    double i = 0;
    double voltage = 0;
    std::cout << "printTimeSeriesCharging" << std::endl;
    do {
        voltage = computeVoltageCharging(i, aBatteryVoltage);
        std::cout << "Vc(1" << i << ") = " << voltage << std::endl;
        i++;
    }while(i < aSeconds);
}
void RCCircuit::dischargeFor(std::ostream& aOStream, double aBatteryVoltage, int aSeconds) const
{
    double i = 0;
    double voltage = aBatteryVoltage;
    aOStream << "printTimeSeriesDischarging" << std::endl;
    do {
        voltage = computeVoltageDischarging(i, aBatteryVoltage);
        aOStream << "Vc(2" << i << ") = " << voltage << std::endl;
        i++;
    }while (i < aSeconds);
}
//charge to a volatage level
void RCCircuit::chargeTo(std::ostream& aOStream, double aBatteryVoltage, double aMaxVoltage) const
{
    double i = 0;
    double voltage = aBatteryVoltage;
    aOStream << "printTimeSeriesDischarging" << std::endl;
    do {
        voltage = computeVoltageCharging(i, aBatteryVoltage);
        aOStream << "Vc(3" << i << ") = " << voltage << std::endl;
        i++;
    }while (voltage < aMaxVoltage);
}
//discharge to a voltage level
void RCCircuit::dischargeTo(std::ostream& aOStream, double aBatteryVoltage, double aMinVoltage) const
{
    double i = 0;
    double voltage = aBatteryVoltage;
    aOStream << "printTimeSeriesDischarging" << std::endl;
    do {
        voltage = computeVoltageDischarging(i, aBatteryVoltage);
        aOStream << "Vc(4" << i << ") = " << voltage << std::endl;
        i++;
    }while (aMinVoltage < voltage);
}

int main()
{
 RCCircuit lCircuit( 56000, 0.00047 );
 cout << "Charging:" << endl;
 lCircuit.chargeFor( cout, 9.0, 30 );
 cout << "Discharging:" << endl;
 lCircuit.dischargeFor( cout, 9.0, 30 );
 cout << "Charging up to 8.5V:" << endl;
 lCircuit.chargeTo( cout, 9.0, 8.5 );
 cout << "Discharging to 2.6V:" << endl;
 lCircuit.dischargeTo( cout, 9.0, 2.6 );
 return 0;
}