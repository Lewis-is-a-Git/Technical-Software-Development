#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	ifstream lInput;
	lInput.open("inputData.txt", ios::in);
	ofstream lOutput;
	lOutput.open("flipout.txt", ios::out);

	while (!lInput.eof())
	{
		int number = 0;
		char ch;
		for (int i = 0; i < 4; i++)
		{
			lInput.get(ch);
			number = number * 256 + ch;
		}
		lOutput << number << ' ';
	}

	lInput.close();
	lOutput.close();

	ifstream ifile;
	ifile.open("flipout.txt", ios::in);
	ofstream ofile;
	ofile.open("flipcoded.txt", ios::out);
	int Num;
	char c;
	while (ifile >> Num) {               
		for (int i = 0; i < 4; i++) {
			c = Num % 256;              
			if (c == 0x0A) {				
				ofile << '\n';          
			}
			else {
				ofile << c;         
			}
			Num = Num / 256;         
		}
	}
	ifile.close();
	ofile.close();

	//now repeat the process to flip it back

	ifstream lInput2;
	lInput2.open("flipcoded.txt", ios::in);
	ofstream lOutput2;
	lOutput2.open("encoded.txt", ios::out);

	while (!lInput2.eof())
	{
		int number = 0;
		char ch;
		for (int i = 0; i < 4; i++)
		{
			lInput2.get(ch);
			number = number * 256 + ch;
		}
		lOutput2 << number << ' ';
	}

	lInput2.close();
	lOutput2.close();

	ifstream ifile2;
	ifile2.open("encoded.txt", ios::in);
	ofstream ofile2;
	ofile2.open("decoded.txt", ios::out);
	int Num2;
	char c2;
	while (ifile2 >> Num2) { 

		for (int i = 0; i < 4; i++) {
			c2 = Num2 % 256;              
			if (c2 == 0x0A) {			
				ofile2 << '\n';   
			}
			else {
				ofile2 << c2;      
			}
			Num2 = Num2 / 256;    
		}
	}
	ifile2.close();
	ofile2.close();
	remove("flipcoded.txt");
	remove("flipout.txt");
	return 0;
}
