#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

char decode(char aData)
{
    int result = 1 + rand() % 127;
    result = aData - result;
    if (result < 0)
    {
        result = result + 128;
    }
    return result;
}

void decodeFile(ifstream& aInfile, ofstream& aOutfile, int aKey)
{
    srand(aKey);
    while (aInfile.good())
    {
        if (!aInfile.eof())
        {
            aOutfile << decode(aInfile.get());
        }
    }
}

int main(int argc, char* argv[])
{
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
