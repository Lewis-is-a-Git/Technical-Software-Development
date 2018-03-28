//Charging and discharging a capacitor
#include <iostream>
#include <cmath>

//process with the equations
    //charging
        //Vc(t)=Vb*(1-e^(-t/(RC)))
double computeVoltageCharging(double res, double cap, double bat_vol, double ti){
    return bat_vol * (1-exp(-ti/(res * cap)));
}
    //discharging
        //Vc(t)=Vb*e^(-t/(RC))
double computeVoltageDischarging(double res, double cap, double bat_vol, double ti){
    return bat_vol * exp(-ti/(res * cap));
}
// print a list of values for each second
void printTimeSeriesVoltage(bool charging, double bat_vol, double res, double cap, int ti){
    std::cout << "printTimeSeriesVoltage" << std::endl;
    for (int i = 0; i <= ti; i++){
        //if the capacitor is charging
        if (charging){
            std::cout << "Vc(" << i << ") = " << computeVoltageCharging(res, cap, bat_vol, i) << std::endl;
        }
        //if the capacitor is discharging
        else{
            std::cout << "Vc(" << i << ") = " << computeVoltageDischarging(res, cap, bat_vol, i) << std::endl;
        }
    }
}

void printTimeSeriesVoltageCharging(double bat_vol, double res, double cap, double max_vol){
    double i = 0;
    double voltage = 0;
    std::cout << "printTimeSeriesCharging" << std::endl;
    do {
        voltage = computeVoltageCharging(res, cap, bat_vol, i);
        std::cout << "Vc(" << i << ") = " << voltage << std::endl;
        i++;
    }while(voltage < max_vol);
}

void printTimeSeriesVoltageDischarging(double bat_vol, double res, double cap, double min_vol){
    double i = 0;
    double voltage = bat_vol;
    std::cout << "printTimeSeriesDischarging" << std::endl;
    do {
        voltage = computeVoltageDischarging(res, cap, bat_vol, i);
        std::cout << "Vc(" << i << ") = " << voltage << std::endl;
        i++;
    }while (voltage > min_vol);
}

int main(){

    printTimeSeriesVoltage(true, 9.0, 56000, 0.00047, 30);
    printTimeSeriesVoltage(false, 9.0, 56000, 0.00047, 30);
    printTimeSeriesVoltageCharging(9.0, 56000, 0.00047, 5.5);
    printTimeSeriesVoltageDischarging(9.0, 56000, 0.00047, 2.6);
    
    return 0;
}