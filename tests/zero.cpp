#include <iostream>
#include <string>
#include <sstream>

using std::cout, std::endl;
using std::string;
using std::cin;

int main(){

    string num;
    cout << "num " << endl;
    cin >> num;
    int size = num.size();
    int index;
    string number;
    //cout << "i " << index;
    //check for neagtive numbers 
    if (num.at(0) == '-'){
        for (int digit = 1; num.at(digit); digit ++){
            if(num.at(digit) != '0' && size != 1){
            //cout << num.at(digit) << endl;
                index = digit;
                break;
            }
            //index.push_back(digit);
        }
        
    }
            
    else{
         for (int digit = 0; num.at(digit); digit ++){
            if(num.at(digit) != '0' && size != 1){
            //cout << num.at(digit) << endl;
                index = digit;
                break;
            //index.push_back(digit);
            }
        
        }
    }
   

    number = num.substr(index,size);
    if (num.at(0) == '-'){
        number.insert(0,"-");
    }
    cout << number;
    return 0;
}