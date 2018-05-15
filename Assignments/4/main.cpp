#include "BullsAndCows.h"
#include "BullsAndCowsConsoleView.h"
#include "BullsAndCowsController.h"
using namespace std;
int main()
{
	BullsAndCowsConsoleView lView; //creates view object
	BullsAndCows lModel; //creates model object
	//creates controller object to interface view and model
	BullsAndCowsController lController(lModel, lView); 
	lController.run();
	return 0;
}
