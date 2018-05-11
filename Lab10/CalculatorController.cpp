#include "CalculatorController.h"

 /**
 * Constructor: Instantiates an object of class CalculatorController.
 * The constructor establishes the references to model
 * and view objects. This is done by using a member
 * initializer for each.
 */
 CalculatorController::CalculatorController( SimpleCalculator& aModel, lCalculatorView& aView ):
    fModel(aModel), fView(aView)
 {
 }
 
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
 void CalculatorController::run()
 {
    do
    {
        fView.showWelcome();
        fModel.setLeftOperand(fView.getOperand("left"));
        fModel.setRightOperand(fView.getOperand("right"));
        char lOperation = fView.selectOperation();
        switch (lOperation)
        {
            case '+':
                fModel.performAddition();
                break;
            case '-':
                fModel.performSubtraction();
                break;
            case '*':
                fModel.performMultiplication();
                break;
            case '/':
                fModel.performDivision();
                break;
        }
        fView.showResult(fModel.getResult());
    }
    while(fView.more());
 }