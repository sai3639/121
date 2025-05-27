#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include "./string_calculator.h"
//#include "string_calculator.cpp"

using std::cout, std::endl, std::cin;
using std::string;

int main() {
    string input;
    char digit;
    string r;
    string l;
    string num;
    unsigned int decimal;
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    cin >> input;
    while(input != "q" || input != "quit"){
        cin >> input;
        if(input.find('+') != std::string::npos){
            cout << "ans = "<< add(l,r) << endl << endl;

        }
        else if (input.find('*') != std::string::npos){
            cout << "ans ="  << endl << multiply(l,r) << endl << endl;
        }

    }
     if (input == "q" || input == "quit"){
        cout << endl << "farvel!" << endl;
        return 0;
    }

    


    string addition;
    digit_to_decimal(digit);
    decimal_to_digit(decimal);
    trim_leading_zeros(num);
    addition = add(l,r);
    cout << addition;
    multiply(l,r);


    // TODO(student): implement the UI
 
    
    

    return 0;
}

