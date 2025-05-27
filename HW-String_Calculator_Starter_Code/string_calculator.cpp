#include <iostream>
#include <string>
#include "./string_calculator.h"
#include <limits>
#include <sstream>

using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
    int num_digit;
    if (isdigit(digit)){
        num_digit = digit - '0';
    }
    else{
        throw std::invalid_argument("input is invalid");
    }
    //cout << num_digit;
    return num_digit;
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
    return number;
}

string add(string lhs, string rhs) {
    // TODO(student): implement
    unsigned int carry;
    string str_result; 
       //column loop
    //start by looping through string to get individual digits
    // loop through lhs and rhs at same time 
    //check sizes of strings first to see which one is longer
    // change digits to string in loop
    //add them together 

    //gets sizes :)
    unsigned int lhs_size = lhs.size();
    unsigned int rhs_size = rhs.size();
    

    unsigned int greater;
    unsigned int lesser;
    string great;
    string less; 


    // works :)
    if(lhs_size < rhs_size){
        greater= rhs_size;
        lesser = lhs_size;
        great = rhs;
        less = lhs;

    }
    else{
        greater = lhs_size;
        lesser = rhs_size;
        great = lhs;
        less = rhs;
    }

    greater = greater - 1;
    lesser = lesser - 1;


    // // works - but doesn't fix problem
    // int remain_size; 
    // remain_size = greater - lesser;
    // //append # remain_size 0's to front of less
    // for(int i = 0; i < remain_size; ++i){
    //     less.insert(0, "0");
    // }
    


    //check for the sign on the numbers
    //convert whole string into integer
    // works :)
    std::stringstream number1(lhs);
    std::stringstream number2(rhs);
    unsigned int num1;
    unsigned int num2;
    number1 >> num1;
    number2 >> num2;
    
    //for loop not working - iterating not working 
    
    if((num1 > 0 && num2 > 0) || (num1 < 0 && num2 < 0)){
        //add columns together 
        for(int digit1 = greater, digit2  = lesser; digit2 >= 0; --digit1, --digit2 ){
            //if digit + digit is greater than 9
            //change string into int then add together 
            //change string digit into int - character to int?
            

            //get digits of greater/digit1 
            //greater has more numbers than lesser
            // lesser has less digits and will stop
            // the loop leaving greater to have digits
            //greater - lesser
           // int remain_size;
            //how many more spaces there are left
            //remain_size = greater - lesser; 
            // remain_size - digit1 
            //append zeros to front of string digit2
            //that way greater = lesser & can keep for loop
           

            //use at() instead of [] indexing? 
            //doesn't quite work
            //doesn't go through full #
            //separate for loops to get individual digits of both #'s?
            string d1;
            d1.append(1,great.at(digit1));
            string d2;
            d2.append(1,less.at(digit2));
            
        


            //works :)
            std::stringstream first(d1);
            std::stringstream sec(d2);
            unsigned int one;
            unsigned int two;
            first >> one;
            sec >> two;

            //works :)
            unsigned int result = 0;
            //add carry to next result
            if (result == 0 && carry == 1){
                result = (one + two) + 1;
                std::stringstream result_str;
                result_str << result;
                char r2;
                result_str >> r2;
                str_result.push_back(r2);
                carry = 0;
            }
            if (one + two > 9){
                //save carry as int
                carry = 1;
                result = one + two;
                //save result 
                //turn result back into string 
                //save index 1 of the string
                // append to result string 
                std::stringstream result_str;
                result_str << result;
                string r;
                result_str >> r;
                char r_save = r[1];
                //appends to back of string
                str_result.push_back(r_save);
                // cout << "carry: " <<  carry << endl; 
                // cout << "result: " << result << endl;
                // cout << "r-save" << r_save << endl;
                // cout << "str- result" << str_result << endl;


            }
            else if (one + two < 9 && result == 0){
                //result if no carry 
                result = one + two;
                std::stringstream result_str;
                result_str << result;
                char r2;
                result_str >> r2;
                str_result.push_back(r2);

            }
            
        


        }
        // have to add great[0] outside of loop
        // first digit in the greatest #
        // not just first digit 
        // remain_size = greater - lesser
        // subtract number of lesser digits from greater to get how many places more greater has
        //works :)
        unsigned int result = 0;
        unsigned int remain_size;
        remain_size = greater - lesser;
        for (int i = 0; i < remain_size; ++i){
            if (carry == 0){
                str_result.push_back(great[i]);

            }
            else if (carry == 1){
                //change into int
                string rem; 
                rem.append(1,great[i]);
                std::stringstream rem1(rem);
                unsigned int r1;
                rem1 >> r1;
                result = r1 + carry;
                carry = 0;
                //turn back to string and append
                std::stringstream result_str;
                result_str << result;
                char r2;
                result_str >> r2;
                str_result.push_back(r2);


            }
        }
    //reverse string to right order
    // works :)
    unsigned int size = (str_result.size()-1) ;
    for (int i= 0; i < size; ++i){
        char temp = str_result[i];
        str_result[i] = str_result[size];
        str_result[size] = temp;
        --size;
    return str_result;

    }
    }
    


    
}

string multiply(string lhs, string rhs) {
    // TODO(student): implement
    //partial products - need to be summed
    //column mutiplication
    //carry on
    int carry;
    string str_result;
    char r_save;
    char r_carry;

    //check for size of strings
    int lhs_size = lhs.size();
    int rhs_size = rhs.size();
    
    string great;
    string less;
    int greater;
    int lesser;

    if(lhs_size > rhs_size){
        greater = lhs_size;
        lesser = rhs_size;
        great = lhs;
        less = rhs;
    }
    else{
        greater = rhs_size;
        lesser = lhs_size;
        great = rhs;
        less = lhs;
    }
    
    greater = greater - 1;
    lesser = lesser - 1;

    
    bool neg = false;

    //check if # is negative
    if((great.at(0) == '-')){
        great = great.substr(1,greater);
        neg = true;
        
    }
    else if ((less.at(0) == '-')){
        less = less.substr(1,lesser);
        neg = true;
    }

 


    int partial = 0;
   // int pProduct = 0;
    int parProduct;
    //get last digit of smaller sized number 
    //less.at(-1);
    //for loop in for loop
    // smaller number on outside and bigger on inside 
    //loop through each digit on smaller and multiply with each digit on bigger
    for(int i = lesser; less[i]; --i){
        //each iteratio of this loop gets partial product
        for (int j = greater; j >= 0; --j){

            if(i < lesser && j == greater){
                str_result.push_back('0');
            }
        
            //change character into integer
            // doesn't multiply first digit of lesser 
            string d1;
            d1.append(1,great.at(j));
            string d2;
            d2.append(1,less.at(i));
           
    


        
            
            std::stringstream first(d1);
            std::stringstream sec(d2);
            int one;
            int two;
            first >> one;
            sec >> two;

            

            int result = 0;
            //carry
            //add carry to next result 
            if ((result == 0 && carry != 0)){
                result = (one * two) + carry;
                if (result <= 9){
                    std::stringstream result_str;
                    result_str << result;
                    char r2;
                    result_str >> r2;
                    str_result.push_back(r2);
                    carry = 0;
                }
                else if (result > 9){
                    std::stringstream result_str;
                    result_str << result;
                    string r;
                    result_str >> r;
                    char r1 = r[1];
                    char r2 = r[0];
                    str_result.push_back(r1);
                    str_result.push_back(r2);
                    carry = 0;
                    
                }
        
            }
    
            if(one * two > 9 && result ==0){
                
                    carry = 1;

                    result = one * two;
                    //cout << result << endl;
                    std::stringstream result_str;
                    result_str << result;
                    string r;
                    result_str >> r;
                    r_save = r[1];
                    r_carry = r[0];
                    carry = r_carry - '0';
                    str_result.push_back(r_save);
            

                //appends to back of string
                
              


            }
            else if(one * two <= 9 && result == 0){
                result = one * two;
               // cout << result << endl;
                std::stringstream result_str;
                result_str << result;
                string r;
                result_str >> r;
                char r_save = r[0];
                //appends to back of string
                str_result.push_back(r_save);
                
            }
            
            //cout << str_result << endl;
            //string partialProduct = 



        }
    //change back to string
    // string proresult;
    // std::stringstream par(proresult);
    // par << parProduct;
        //cout << str_result << endl;

        int size = (str_result.size()-1) ;
        for (int i= 0; i < size; ++i){
            char temp = str_result[i];
            str_result[i] = str_result[size];
            str_result[size] = temp;
            --size;

        }
        if (neg == true){
            str_result.insert(0,"-");
        }
       // cout << str_result << endl;

        string str_result1 = str_result;
        std::stringstream product(str_result1);
        product >> partial;
        parProduct += partial;
        //cout << parProduct << endl;
        //clear string for next partial product 
        str_result = "";

           // turn str result back into int
           // save to parital product
            //add next partial product to this one
        // std::stringstream product(str_result);
        // product >> partial;
        // parProduct = partial + pProduct;
        // pProduct = partial;
        // string str_result; 


        //string partialProduct;
       
        
    }

    std::stringstream partialProduct;
    partialProduct <<parProduct;
    string part;
    partialProduct >> part;


    return part;
}



//outer loop - moving through bottom number from right to left
//inner loop - multiply by single digit 
//sum = 0
//add function to sum 
//add partial sum to sum 
