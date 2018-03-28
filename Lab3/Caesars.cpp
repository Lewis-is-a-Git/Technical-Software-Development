#include <iostream>
#include <string>
#include <cctype>

int main(){
    std::string Text = "Do not worry about your difficulties in Mathematics. I can assure you mine are still greater.";
    for (int i = 0; i < Text.length(); i++){
        std::cout << Text[i];
    }
    std::cout << std::endl;
    for (int i = 0; i < Text.length(); i++){
        if (Text[i] == ' '){
        std::cout << ' ';
        }else if(isupper(Text[i])){
        std::cout << char('A' + ((Text[i] - 'A' + 4) % 26));
        }else if (islower(Text[i])){
        std::cout << char('a' + ((Text[i] - 'a' + 4) % 26));
        }
    }
}
