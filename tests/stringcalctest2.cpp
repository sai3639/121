#include <iostream>
#include <string>
#include <sstream>

using std::cout, std::endl;
using std::string;
using std::cin;

int main(){

    string lhs;
    string rhs;
    cout << "L: ";
    getline(cin, lhs);
    cout << "R: ";
    getline(cin, rhs);
    //declare variables
    int carry = 0;
    string result;
    string str1;
    string str2;
    int num1;
    int num2;
    int dif;
    int sum;
    bool neg = false;

    if(lhs.length() > rhs.length())
    {
        str2 = lhs;
        str1 = rhs;
    }
    else
    {
        str2 = rhs;
        str1 = lhs;
    }

    num1 = str1.length();
    num2 = str2.length();
    dif = num2 - num1;

    for(int i = num1-1; i >=0; --i)
    {
        sum = ((str1.at(i)-'0') + (str2.at(i+dif)- '0') + carry);
        result.push_back(sum%10 + '0');
        carry = sum/10;
    }

    for(int i = num2-num1-1; i >=0; --i)
    {
        sum = ((str2.at(i)-'0')+carry);
        result.push_back(sum%10+'0');
        carry = sum/10;
    }

    if(carry)
    {
        result.push_back(carry+'0');
    }

    unsigned int size = (result.size()-1) ;
    for (unsigned int i= 0; i < size; ++i)
    {
        char temp = result[i];
        result[i] = result[size];
        result[size] = temp;
        --size;
    

    }




    cout << "result " << result << endl;



}

