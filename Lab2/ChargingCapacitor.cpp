//Charging and discharging a capacitor
#include <iostream>
#include <cmath>

//process with the equations
    //charging
        //Vc(t)=Vb*(1-e^(-t/(RC)))
double computeVoltageCharging(double Resistance, double Capacitance, double Voltage_Battery, double time_index){
    return Voltage_Battery * (1-exp(-time_index/(Resistance * Capacitance)));
}
        //Ic(t) = Vb/R * e^(-t/(RC))
double computeCurrentCharging(double Resistance, double Capacitance, double Voltage_Battery, double time_index){
    return Voltage_Battery/Resistance * exp(-time_index/(Resistance*Capacitance));
}
    //discharging
        //Vc(t)=Vb*e^(-t/(RC))
double computeVoltageDischarging(double Resistance, double Capacitance, double Voltage_Battery, double time_index){
    return Voltage_Battery * exp(-time_index/(Resistance * Capacitance));
}
        //Ic(t) = -Vb/R * e^(-t/(RC))
double computeCurrentDischarging(double Resistance, double Capacitance, double Voltage_Battery, double time_index){
    return -Voltage_Battery/Resistance * exp(-time_index/(Resistance*Capacitance));
}

int main(){
    //input R, C, V, t
    long double Resistance = 56000;
    long double Capacticance = 0.00047;
    double Voltage_Battery = 9.0;
    double time_index = 26.0;

    //output Vc(t) and Ic(t)
    double Voltage_Charging = computeVoltageCharging(Resistance, Capacticance, Voltage_Battery, time_index);
    double Voltage_Discharging = computeVoltageDischarging(Resistance, Capacticance, Voltage_Battery, time_index);
    double Current_Charging = computeCurrentCharging(Resistance, Capacticance, Voltage_Battery, time_index);
    double Current_Discharging = computeCurrentDischarging(Resistance, Capacticance, Voltage_Battery, time_index);

    std::cout << "Charging Vc(t) = " << Voltage_Charging << std::endl;
    std::cout << "Charging Ic(t) = " << Current_Charging << std::endl;
    std::cout << "Discharging Vc(t) = " << Voltage_Discharging << std::endl;
    std::cout << "Discharging Ic(t) = " << Current_Discharging << std::endl;
    return 0;
}