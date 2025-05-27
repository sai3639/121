#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    string num1;
    string op;
    string num2;
   
    //string input;
    string result;
    //input = num1 + op + num2;
    while(num1!= "q" || num1!= "quit")
    {

        cin >> num1;
        if(num1 == "q" || num1=="quit")
        {
            break;
        }
        cin >> op;
        cin >> num2;
        cout << ">> ";
        //cout << endl;
        if(op == "+")
        {
            result = add(num1, num2);
        }
        else if(op == "*")
        {
            result = multiply(num1, num2);
        }
        cout << endl;
        cout << "ans =";
        cout << endl;
        cout << endl;
        cout << "    " << result;
        cout << endl;
        cout << endl;
       

    }
    //cout << endl;
    cout << ">> " << endl;
    cout << "farvel!";
    cout << endl; 


    
    // TODO(student): implement the UI
}

