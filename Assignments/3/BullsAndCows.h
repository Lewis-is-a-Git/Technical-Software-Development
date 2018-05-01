#include <string>
class BullsAndCows
{
  private:
    int fSecretNumbers[9];
    int fBulls;
    int fCows;

  public:
    BullsAndCows();
    void start();
    void guess(std::string aNumberString);
    int getBulls() const; // getter for bulls
    int getCows() const;  // getter for cows
};