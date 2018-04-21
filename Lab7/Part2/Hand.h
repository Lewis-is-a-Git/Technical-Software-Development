
// SWE20004, Tutorial 7, 2017

#pragma once
#include "Card.h"
#include <string>
#include <iostream>

class Hand
{
private:
	Card fCards[5];
	int fScore;

public:
	Hand();

	void initialize( Card aCards[5] );
	void replaceCards( Card aCards[], const std::string& aHoldString );

	std::string getHandString() const;

	int getScore();
	const std::string& getScoreTitle();
};

std::ostream& operator<<( std::ostream& aOStream, const Hand& aHand );
