/**
* Purpose: Simple calculator to demonstrate Model-View-Controller paradigm
* Created: 11 May 2018
* Author: Lewis Brockman-Horsley
**/

#include "CalculatorConsoleView.h"
#include "SimpleCalculator.h"
#include "CalculatorController.h"
using namespace std;
int main()
{
    CalculatorConsoleView lView;
    SimpleCalculator lModel;
    CalculatorController lController( lModel, lView );
    lController.run();
    return 0;
}
