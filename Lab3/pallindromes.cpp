#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>

bool isPallindrome(std::string test){
    int left = 0;
    int right = test.length()-1;
    transform(test.begin(), test.end(), test.begin(),::tolower);    
    do {
        
        while(!isalpha(test[left])){
            left++;
        }
        while(!isalpha(test[right])){
            right--;
        }
    if (test[left] != test[right]){
        return false;
    }
    left++;
    right--;

    }while(left != right && left < right);
    return true;
}

int main(){
    std::string test1 = "glenelg";
    std::string test2 = "A new order began, a more Roman age bred Rowena.";

    std::cout << "Is \'" << test1 << "\' a pallindrome " << isPallindrome(test1) << std::endl;
    std::cout << "Is \'" << test2 << "\' a pallindrome " << isPallindrome(test2) << std::endl;

    return 0;
}