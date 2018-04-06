#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

char decode(char aData)
{
<<<<<<< HEAD
    int result = 1 + rand() % 127;
    result = aData - result;
    if (result < 0)
    {
        result = result + 128;
    }
    return result;
=======
	int result = 1 + rand() % 127;
	result = aData - result;
	if (result < 0)
	{
		result = result + 128;
	}
	return result;
>>>>>>> 23cd822bf53ae8219ae51ab4a163e7127500101a
}

void decodeFile(ifstream& aInfile, ofstream& aOutfile, int aKey)
{
<<<<<<< HEAD
    srand(aKey);
    while (aInfile.good())
    {
        if (!aInfile.eof())
        {
            aOutfile << decode(aInfile.get());
        }
    }
=======
	srand(aKey);
	while (aInfile.good())
	{
		if (!aInfile.eof())
		{
			char lDecode = decode(aInfile.get());
			if (lDecode == 0x0A)
			{
				aOutfile << '\n';
			}
			else
			{
				aOutfile << lDecode;
			}

		}
	}
>>>>>>> 23cd822bf53ae8219ae51ab4a163e7127500101a
}

int main(int argc, char* argv[])
{
<<<<<<< HEAD
    if (argc < 3)
    {
        cerr << "Not enough command arguments, correct use is:" << endl;
        cerr << "Cipher key inputfile.txt outputfile.txt" << endl;
        //return 3;
    }
    
    //arg1 = seed. arg2 = input file, arg3 output.txt
    char input[] = "EncodedDataOSX(1).txt";
    //char input[] = "EncodedDataVS(1).txt";
    char output[] = "output.txt";
    //int key = atoi(argv[1]);
    int key = 12345;

    ifstream lInput;
    ofstream lOutput;
    lInput.open(input, ios::in);
    lOutput.open(output, ios::out);
    //lInput.open(argv[2], ios::in);
    //lOutput.open(argv[3], ios::out);
    if (!lInput.good())
    {
        cerr << "Cannot open file: " << input << endl;
        return 2;
    }
    if (!lOutput.good())
    {
        cerr << "Cannot create file: " << output << endl;
        return 3;
    }

    decodeFile(lInput, lOutput, key);

    lOutput << "\n\nPrepared by Lewis Brockman-Horsey (101533222)" << endl;

    lOutput.close();
    lInput.close();
    return 0;
}
=======
	if (argc < 3)
	{
		cerr << "Not enough command arguments, correct use is:" << endl;
		cerr << "Cipher key inputfile.txt outputfile.txt" << endl;
		return 3;
	}
    
	int key = atoi(argv[1]);

	ifstream lInput;
	ofstream lOutput;
	lInput.open(argv[2], ios::binary);
	lOutput.open(argv[3], ios::out);
	if (!lInput.good())
	{
		cerr << "Cannot open file: " << argv[1] << endl;
		return 2;
	}
	if (!lOutput.good())
	{
		cerr << "Cannot create file: " << argv[2] << endl;
		return 3;
	}

	decodeFile(lInput, lOutput, key);

	lOutput << "\n\nPrepared by Lewis Brockman-Horsey (101533222)" << endl;

	lOutput.close();
	lInput.close();
	return 0;
}
>>>>>>> 23cd822bf53ae8219ae51ab4a163e7127500101a