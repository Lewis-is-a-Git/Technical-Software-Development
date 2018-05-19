/**
 * @author Lewis Brockman-Horlsey 101533222
 */
#include "BenfordTester.h"
#include <fstream>
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    if (argc != 2)
	{
		cerr << "Need an input file." << endl;
		return 1;
	}
    
    //set up input stream
    ifstream lInput;
    lInput.open(argv[1], ifstream::in);

    if (!lInput.good()){
        //operation failed
        cerr << "Cannot open file " << argv[1] << endl;
        return 2;
    }

    cout << "Results testing: " << argv[1] << endl;

    BenfordTester BenTest;
    BenTest.collectData(lInput);

    cout << BenTest;

    lInput.close();
    return 0;
}