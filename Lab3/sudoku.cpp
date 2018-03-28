#include <iostream>

void printBoard(int lBoard[9][9]){
    for (int i = 0; i < 9; i++){
        std::cout << "-------------------------------------" <<std::endl;
        for (int j = 0; j < 9; j++){
            if (lBoard[i][j] == 0){
                std::cout << "|   ";
            }
            else {
                std::cout << "| " << lBoard[i][j] << " ";
            }
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;
    std::cout << std::endl;
}

int main(){

    int lBoard[9][9] = {
        { 5, 0, 0, 8, 0, 0, 7, 9, 0 },
        { 0, 0, 0, 1, 0, 0, 0, 3, 0 },
        { 0, 6, 9, 0, 0, 0, 8, 0, 0 },
        { 0, 4, 0, 6, 3, 0, 0, 0, 0 },
        { 1, 0, 2, 0, 0, 0, 3, 0, 6 },
        { 0, 0, 0, 0, 5, 1, 0, 7, 0 },
        { 0, 0, 1, 0, 0, 0, 9, 2, 0 },
        { 0, 2, 0, 0, 0, 4, 0, 0, 0 },
        { 0, 9, 6, 0, 0, 3, 0, 0, 8 }
        };

    printBoard(lBoard);

    return 0;
}