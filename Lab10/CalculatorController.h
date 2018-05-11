#pragma once
#include "lCalculatorView.h"
#include "SimpleCalculator.h"
class CalculatorController
{
private:
 SimpleCalculator& fModel; // reference to model object
 lCalculatorView& fView; // reference to view object
public:
 /**
 * Constructor: Instantiates an object of class CalculatorController.
 * The constructor establishes the references to model
 * and view objects. This is done by using a member
 * initializer for each.
 */
 CalculatorController( SimpleCalculator& aModel, lCalculatorView& aView );
 /**
 * This method implements the "calculator loop". It repeatedly asks for
 * the operation to be performed (i.e., +, -, *, or /) and then asks for
 * the corresponding arguments. Once, the operation and the arguments have
 * been specified, the calculator (i.e., the model) computes the result
 * and the view displays it. The method run coordinates these activities.
 * Selecting “n” as response to the question “Do you wish to continue?”
 * breaks the “calculator loop”. In this case, the application has to
 * gracefully terminate with a “Good bye” message.
 */
 void run();
};