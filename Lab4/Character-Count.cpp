#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    //set up input stream
    ifstream lInput;
    lInput.open("input.txt", ifstream::binary);

    if (!lInput.good()){
        //operation failed
        cerr << "Cannot open file" << "input.txt" << endl;
        return 2;
    }

    int cnt = 0; //counter
    int letters[256] = {0}; //character array set to 0

    while(lInput.good()){
        //if the data exists get it
        int lData = lInput.get();
        letters[lData]++;  //increase the count for that index   
        cnt++; //increase the total count
    }
    //print out the result
    cout << "Counted " << cnt << " characters." << endl;
    for (int i = 0; i < 256; i++){
        if (letters[i] != 0 ){
        
            if (isgraph(i)){
                cout << char(i); //print the character if it can be printed
            }else{ //print the hexadecimal equivalent
                cout << setfill('0') << setw(2) << hex << i; //and make it look nice
            }
        
        cout << " = " << dec << letters[i] << endl;
        }
    }
    //close the file
    lInput.close();

    return 0;
}
