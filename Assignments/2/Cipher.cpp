#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

char decode(char aData)
{
	int lResult = 1 + rand() % 127; //creates the variable offset using rand
	lResult = aData - lResult;		//apply the offset
	if (lResult < 0)
	{
		lResult = lResult + 128;
	}
	return lResult;
}

void decodeFile(ifstream& aInfile, ofstream& aOutfile, int aKey)
{
	srand(aKey);			//seed the random function with the decipher key
	while (aInfile.good())
	{
		if (!aInfile.eof())
		{
			aOutfile << decode(aInfile.get()); //get a character and decode it
		}
	}
}

int main(int argc, char* argv[])
{
	//arg1 = seed, arg2 = input file, arg3 output.txt
	if (argc != 3)
	{
		cerr << "Not enough command arguments, correct use is:" << endl;
		cerr << "Cipher key inputfile.txt outputfile.txt" << endl;
		return 1;
	}

	
	int lKey = atoi(argv[1]);
	
	ifstream lInput;		//create the file streams
	ofstream lOutput;
	lInput.open(argv[2], ios::binary);
	lOutput.open(argv[3], ios::out);
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

	decodeFile(lInput, lOutput, lKey);

	lOutput << "\n\nPrepared by Lewis Brockman-Horsey (101533222)" << endl;

	lOutput.close();
	lInput.close();
	return 0;
}
