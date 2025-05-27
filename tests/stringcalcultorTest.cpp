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
    else if (lhs_size < rhs_size){
        greater = rhs_size;
        lesser = lhs_size;
        great = rhs;
        less = lhs;
    }
    else{
        greater = rhs_size;
        lesser=lhs_size;
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
                if (j>0){
                    std::stringstream result_str;
                    result_str << result;
                    char r2;
                    result_str >> r2;
                    str_result.push_back(r2);
                    cout << str_result <<endl;
                    carry = 0;
                }
                else if (j==0){
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
                    string rcarry;
                    rcarry.append(1,r_carry);
                    std::stringstream c(rcarry);
                    c >> carry;
                    //carry = r_carry - '0';
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
    cout << part;
    





    return 0;
}
