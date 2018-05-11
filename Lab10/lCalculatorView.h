#pragma once
#include <string>
class lCalculatorView
{
public:
 virtual ~lCalculatorView() {}
 virtual void showWelcome() =0;
 virtual void showGoodBye() =0;
 virtual bool more() =0;
 virtual char selectOperation() =0;
 virtual int getOperand( std::string aOperandName ) =0;
 virtual void showResult( int aValue ) =0;
};