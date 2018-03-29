/*
    Author: Lewis Brockman-Horsley
    Date Created: March 2018
    Purpose: Decode a list of integers form an input file to ASCII art in an output file
    Special Notes: Requires 2 commmand line arguments input.txt and output.txt
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[]){
    //set up input/output streams
    ifstream ifile;
    ofstream ofile;
    ifile.open(argv[1], ios::in);
    ofile.open(argv[2], ios::out);
    int Num; //integer from file
    char c; //decoded character

    if (!ifile.good()){
        //operation failed
        cerr << "Cannot open file: " << argv[1] << endl;
        return 1;
    }
    if (ofile.is_open()){                   //check the create file permission
        while (ifile >> Num){               //while not at the end of the file
            for (int i = 0; i < 4; i++){    
                c = Num % 256;              //modulo to decode the integer
                if (c == 0x0A){				//if its a new line character '\n'
                    ofile << '\n';          //move to new line
                }else{
                    ofile << c;             //print the decoded character
                }
                Num = Num / 256;            //move to the next character
            } 
        }
    }else{
        //cannot create an output file
        cerr << "Cannot create file: " << argv[2] << endl;
        return 2;
    }
    ofile << "\n Prepared by Lewis Brockman-Horsley (101533222)";
    //close the files
    ifile.close();
    ofile.close();
    return 0;
}
