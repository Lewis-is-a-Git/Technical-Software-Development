#include "BullsAndCows.h"
#include "BullsAndCowsConsoleView.h"
#include "BullsAndCowsController.h"
using namespace std;
int main()
{
    BullsAndCowsConsoleView lView;
    BullsAndCows lModel;
    BullsAndCowsController lController(lModel, lView);
    lController.run();
    return 0;
}