#include <iostream>
#include <fstream>

using namespace std;

void encodeTextFile(ifstream& aInfile, ofstream& aOutfile)
{
    char lCharacterBuffer[4];
    char lCharacter;
    int lDataToRead = 4;

    aInfile.get(lCharacter);
    while (aInfile.good())
    {
        if (lCharacter != 13) //if not a newline character
        {
            lDataToRead--; //need to decrement because the chars are stored in reverse order
            lCharacterBuffer[lDataToRead] = lCharacter; //accessed in reverse order
            if (lDataToRead == 0) // when the buffer array is full
            {
                int lInteger32 = 0; //create an integer to encode the characters
                for (int k = 0; k < 4; k++)
                {
                    lInteger32 = lInteger32 * 256 + lCharacterBuffer[k]; //add the ascii value of the char
                }
                aOutfile << lInteger32 << '\n'; //save it to the file
                lDataToRead = 4; //reset the buffer counter
            }
        }
        aInfile.get(lCharacter);
    }
}

int main(int argc, char* argv[])
{
	//requires 2 command line arguments
	//arg1 = input file, arg2 output.txt
	if (argc != 3)
	{
		cerr << "Incorrect use of command line arguments:" << endl;
		cerr << "Encoder inputfile.txt outputfile.txt" << endl;
		return 1;
	}
	
	ifstream lInput;		//create the file streams
	ofstream lOutput;
	lInput.open(argv[1], ios::in);
	lOutput.open(argv[2], ios::out);
    //File validations
	if (!lInput.good())
	{
		cerr << "Cannot open file: " << argv[2] << endl;
		lOutput.close();
		return 2;
	}
	if (!lOutput.good())
	{
		cerr << "Cannot create file: " << argv[3] << endl;
		lInput.close();
		return 3;
	}

    encodeTextFile(lInput, lOutput);

	lOutput.close();
	lInput.close();
	return 0;
}