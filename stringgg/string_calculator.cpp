#include <iostream>
#include <string>
#include "./string_calculator.h"
#include <sstream>

using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
    int num_digit;
    if(isdigit(digit))
    {
        num_digit = digit -'0';
    }
    else
    {
        throw std::invalid_argument("input is invalid");
    }
    return num_digit;
    
    return 0;
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement
    char char_decimal;
    if (decimal < 10){
        char_decimal = '0' + decimal;
    }
    else{
        throw std::invalid_argument("input is invalid");
    }
    return char_decimal;
}

string trim_leading_zeros(string num) {
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
    }
    number = num.substr(index,size);
    if (num.at(0) == '-'){
        number.insert(0,"-");
    }
    return number;
}

string add(string lhs, string rhs) {
    // TODO(student): implement

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

    if(lhs.find("-") != std::string::npos && rhs.find("-") != std::string::npos)
    {
        neg = true;
        lhs.erase(lhs.begin());
        rhs.erase(rhs.begin());
    }

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

     if(neg == true)
    {
        result.push_back('-');
    }

    unsigned int size = (result.size()-1) ;
    for (unsigned int i= 0; i < size; ++i)
    {
        char temp = result[i];
        result[i] = result[size];
        result[size] = temp;
        --size;
    

    }

   result = trim_leading_zeros(result);
 

    return result;
}

string multiply(string lhs, string rhs) {
    // TODO(student): implement

    string str1, str2;
    int l1, l2;
    bool neg;

    
    if(lhs.find("-") != std::string::npos && rhs.find("-") == std::string::npos)
    {
        neg = true;
        lhs.erase(lhs.begin());
    }
    else if(lhs.find("-") == std::string::npos && rhs.find("-") != std::string::npos)
    {
        neg = true;
        rhs.erase(rhs.begin());
    }
    if(lhs.find("-") != std::string::npos && rhs.find("-") != std::string::npos)
    {
        neg = false;
        lhs.erase(lhs.begin());
        rhs.erase(rhs.begin());
    }


    
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

    l1 = str2.length();
    l2 = str1.length();

    string product(l1 + l2, 0);
    for(int i = l1 - 1; i >= 0; --i)
    {
        for(int j = l2-1; j >=0; --j)
        {
            int m = (str2.at(i) - '0') * (str1.at(j) - '0');
            int sum = product[i + j + 1] + m;
            product[i + j] += sum / 10;
            product[i + j + 1] = sum % 10;
        }
    }
      for (long unsigned int i = 0; i < product.size(); i++) {
      product[i] += '0';
   }

   if(str1 == "0" || str2 == "0")
   {
        return "0";
   }


   if (product[0] == '0') {
      product = product.substr(1);
   }

    if(neg == true)
    {
        unsigned int size = (product.size()-1) ;
        for (unsigned int i= 0; i < size; ++i)
        {
            char temp = product[i];
            product[i] = product[size];
            product[size] = temp;
            --size;
    

        }

        product.push_back('-');
        size = (product.size()-1) ;
        for (unsigned int i= 0; i < size; ++i)
        {
            char temp = product[i];
            product[i] = product[size];
            product[size] = temp;
            --size;
    

        }
        ///cout << "p " << product << endl;

    }

    product = trim_leading_zeros(product);

     
  



    return product;
}
