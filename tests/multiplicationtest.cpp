#include <iostream>
#include <string>
#include <sstream>

using std::cout, std::endl;
using std::string;
using std::cin;

int main(){

    string num;
    cout << "L: ";
    getline(cin, num);
    // TODO(student): implement
   // cout << "n " << num << endl;
    int size = num.size();
    int index;
    string number;
    //cout << "i " << index;
    //check for neagtive numbers 
    if (num.at(0) == '-'){
        for (long unsigned int digit = 1; digit < num.length(); digit ++){
            if(num.at(digit) != '0' && size != 1){
            //cout << num.at(digit) << endl;
                index = digit;
                break;
            }
            //index.push_back(digit);
        }
        number = num.substr(index,size);
        
    }
            
    else{
         for (long unsigned int digit = 0; digit < num.length(); digit ++){
            if(num.at(digit) != '0' && size != 1){
            //cout << num.at(digit) << endl;
                index = digit;
                break;
            //index  .push_back(digit);
            }
        
        }
        number = num.substr(index,size);
    }
    if(num.at(size) == '0')
    {
        number = "0";
    }
    
    if (num.at(0) == '-'){
        number.insert(0,"-");
    }
     
     cout << "n " << number << endl;
  
   //cout << "p " << product << endl;





}
