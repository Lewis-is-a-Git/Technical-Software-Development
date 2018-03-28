#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    //TODO: remove these and use shitty args
    char input[] = "SampleData.txt";
    char output[] = "Output.txt";

    //set up input/output streams
    ifstream ifile;
    ofstream ofile;
    ifile.open(input, ios::in);
    ofile.open(output, ios::out);
    int Num; //integer from file
    char c; //decoded character

    if (!ifile.good()){
        //operation failed
        cerr << "Cannot open file: " << input << endl;
        return 1;
    }
    if (ofile.is_open()){                   //check the create file permission
        while (ifile >> Num){               //while not at the end of the file
            for (int i = 0; i < 4; i++){    
                c = Num % 256;              //modulate to decode the integer
                if (c == 0x0A){
                    ofile << '\n';          //if the character is new line character, move to new line
                }else{
                    ofile << c;             //print the decoded character to the file
                }
                Num = Num / 256;            //move to the next character
            } 
        }
    }else{
        //cannot create an output file
        cerr << "Cannot create file: " << output << endl;
        return 2;
    }
    ofile << "\n Prepared by Lewis Brockman-Horsley (101533222)";
    //close the files
    ifile.close();
    ofile.close();
    return 0;
}
