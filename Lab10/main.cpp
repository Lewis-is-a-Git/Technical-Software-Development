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