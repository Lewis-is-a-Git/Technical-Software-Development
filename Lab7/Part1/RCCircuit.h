#pragma once
#include <ostream>
class RCCircuit
{
    private:
        //data memebers
        double fResistorValue;
        double fCapacitorValue;
        double fTimeConstant;
    public:
    //accessible from main
        //methods
        RCCircuit(double aResistorValue, double aCapacitorValue);
        double computeVoltageCharging(int aTimeStamp, double aBatteryVoltage) const;
        double computeCurrentCharging(int aTimeStamp, double aBatteryVoltage) const;
        double computeVoltageDischarging(int aTimeStamp, double aBatteryVoltage) const;
        double computeCurrentDischarging(int aTimeStamp, double aBatteryVoltage) const;
        void chargeFor(std::ostream& aOStream, double aBatteryVoltage, int aSeconds) const;
        void dischargeFor(std::ostream& aOStream, double aBatteryVoltage, int aSeconds) const;
        void chargeTo(std::ostream& aOStream, double aBatteryVoltage, double aMaxVoltage) const;
        void dischargeTo(std::ostream& aOStream, double aBatteryVoltage, double aMinVoltage) const;
};