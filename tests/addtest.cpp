#include <iostream>
#include <string>
#include <sstream>

using std::cout, std::endl;
using std::string;
using std::cin;





string add(string lhs, string rhs){

    int carry;
    string str_result; 
   
       //column loop
    //start by looping through string to get individual digits
    // loop through lhs and rhs at same time 
    //check sizes of strings first to see which one is longer
    // change digits to string in loop
    //add them together 

    //gets sizes :)
    int lhs_size = lhs.size();
    int rhs_size = rhs.size();
    

    int greater;
    int lesser;
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
    int num1;
    int num2;
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
            int one;
            int two;
            first >> one;
            sec >> two;

            //works :)
            int result = 0;
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
        int result = 0;
        int remain_size;
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
                int r1;
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
    int size = (str_result.size()-1) ;
    for (int i= 0; i < size; ++i){
        char temp = str_result[i];
        str_result[i] = str_result[size];
        str_result[size] = temp;
        --size;

    }
   // cout << str_result;
    return str_result;

    }
 
    

}

int main(){
    string r;
    string l;
    getline(cin, l);
    getline(cin,r);
    string addition;
    add(l,r);
    
    return 0;
}