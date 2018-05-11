#pragma once
class SimpleCalculator
{
private:
 int fLeftOperand;
 int fRightOperand;
 int fResult;
public:
 /**
 * Constructor: Instantiates an object of class SimpleCalculator.
 * The constructor sets all instance variables to 0.
 */
 SimpleCalculator();
 /**
 * This method computes fResult = fOperandA + fOperandB.
 */
 void performAddition();
 /**
 * This method computes fResult = fOperandA - fOperandB.
 */
 void performSubtraction();
 /**
 * This method computes fResult = fOperandA * fOperandB.
 */
 void performMultiplication();
 /**
 * This method computes fResult = fOperandA / fOperandB.
 * We ignore division by zero.
 */
 void performDivision();
 /**
 * Setter for left operand.
 *
 * @param aLeftOperand is the value for the left operand.
 */
 void setLeftOperand( int aLeftOperand );
 /**
 * Setter for right operand.
 *
 * @param aRightOperand is the value for the right operand.
 */
 void setRightOperand( int aRightOperand );
 /**
 * Getter for result of last operation.
 *
 * @return the value of fResult.
 */
 int getResult() const;
};