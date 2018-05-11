#pragma once
#include "lCalculatorView.h"
class CalculatorConsoleView : public lCalculatorView
{
public:
 virtual void showWelcome();
 virtual void showGoodBye();
 virtual bool more();
 virtual char selectOperation();
 virtual int getOperand( std::string aOperandName );
 virtual void showResult( int aValue );
};