 #include "SimpleCalculator.h"

 /**
 * Constructor: Instantiates an object of class SimpleCalculator.
 * The constructor sets all instance variables to 0.
 */
 SimpleCalculator::SimpleCalculator()
 {
    int fLeftOperand = 0;
    int fRightOperand = 0;
    int fResult = 0;
 }
 /**
 * This method computes fResult = fOperandA + fOperandB.
 */
 void SimpleCalculator::performAddition()
 {
    fResult = fLeftOperand + fRightOperand;
 }
 /**
 * This method computes fResult = fOperandA - fOperandB.
 */
 void SimpleCalculator::performSubtraction()
 {
     fResult = fLeftOperand - fRightOperand;
 }
 /**
 * This method computes fResult = fOperandA * fOperandB.
 */
 void SimpleCalculator::performMultiplication()
 {
     fResult = fLeftOperand * fRightOperand;
 }
 /**
 * This method computes fResult = fOperandA / fOperandB.
 * We ignore division by zero.
 */
 void SimpleCalculator::performDivision()
 {
    fResult = fLeftOperand / fRightOperand;
 }
 /**
 * Setter for left operand.
 *
 * @param aLeftOperand is the value for the left operand.
 */
 void SimpleCalculator::setLeftOperand( int aLeftOperand )
 {
    fLeftOperand = aLeftOperand;
 }
 /**
 * Setter for right operand.
 *
 * @param aRightOperand is the value for the right operand.
 */
 void SimpleCalculator::setRightOperand( int aRightOperand )
 {
    fRightOperand = aRightOperand;
 }
 /**
 * Getter for result of last operation.
 *
 * @return the value of fResult.
 */
 int SimpleCalculator::getResult() const
 {
     return fResult;
 }