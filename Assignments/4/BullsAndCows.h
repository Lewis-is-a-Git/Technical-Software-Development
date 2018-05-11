
/**
 * Specification of class BullsAndCows.
 *
 * @author converner
 * @version v5 (SWE20004, 2018)
 *
 */

#pragma once

#include <string>

class BullsAndCows
{
private:
    int fSecretNumbers[9];
    int fBulls;
    int fCows;
    
public:
    /**
     * Constructor: Instantiates an object of class BullsAndCows.
     * 				The constructor sets up an array of 9 unique
     * 				integers between 1 and 9. In addition, the
     * 				instance variables fBulls and fCows are set to 0.
     */
    BullsAndCows();
    
    /**
     * This method rearranges the numbers in the internal
     * integer array. This way we create a new "secret number."
     * We use the Fisher&Yates shuffling method for this purpose, where
     * n is 9.
     */
    void start();
    
    /**
     * This method determines the number of Bulls and Cows in the player's
     * 4-digit guessed number.
     *
     * @param aNumberString		The player's guessed 4-digit number.
     *
     */
    void guess( std::string aNumberString );
    
    /**
     * Getter for number of bulls in last guess.
     *
     * @return The number of bulls (correctly placed digits).
     */
    int getBulls() const;
    
    /**
     * Getter for number of cows in last guess.
     *
     * @return The number of cows (correctly guessed digits).
     */
    int getCows() const;
};
