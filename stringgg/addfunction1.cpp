string add(string lhs, string rhs) {
    // TODO(student): implement
    
 //declare variables
    int carry = 0;
    string result;
    char str_digit;
    std::stringstream d;
    unsigned int num1;
    unsigned int num2;
    unsigned int great;
    unsigned int less;
    int remain = 0;
    bool neg = false;


    //check if numbers are negative
    if(lhs.at(0) == '-' && rhs.at(0) == '-')
    {
        lhs.replace(0, 1, "0");
        rhs.replace(0, 1, "0");
        neg = true;
    }

     //convert string into number 
    std::stringstream number1(lhs);
    std::stringstream number2(rhs);
    number1>>num1;
    number2>>num2;
   

    //get size of string - need?
    unsigned int lhs_size = lhs.size();
    unsigned int rhs_size = rhs.size();


    //check which number has more digits
    if(lhs_size < rhs_size)
    {
        great = num2;
        less = num1;
    }
    else
    {
        great = num1;
        less = num2;
    }

   
    //number slicing 
    if(num1 > 9 || num2 > 9)
    {
        while(less!=0)
        {
            int digit = 0;
            //get digits 
            int digit1 = 0;
            digit1 = less%10;
            less/=10;

            int digit2 = 0;
            digit2 = great%10;
            great/=10;

            //add digits together 
            digit = digit1 + digit2;

            //if carry is 1 from last loop - add 1 to this loop and set carry
            //to 0
            if(carry==1)
            {
                digit++;
                carry = 0;
            }

            //deal with carry
                    if(digit1 + digit2 > 10)
                {
                    carry = 1;
                    //make sure to only add one's place
                    digit = digit - 10;
                }
            

            

            //cout << "digit " << digit << endl;
            //change integer digit into string 
            d << digit;
            d >> str_digit;


            //add character to result string
            result.push_back(str_digit);
            

        }


        //take care of any remainder digits
        if(great != 0)
        {
            //number slice until done with
            while(great!=0)
            {
                remain = 0;
                remain = great%10;
                great/=10;

                if(carry==1)
                {
                    remain++;
                    carry = 0;
                }

                //change integer digit into string
                d << remain;
                d >> str_digit;

                //add character to result string
                result.push_back(str_digit);

            }
        }

        //result is reversed  - unreverse it dumbass
        unsigned int size = (result.size()-1) ;
        for (unsigned int i= 0; i < size; ++i)
        {
            char temp = result[i];
            result[i] = result[size];
            result[size] = temp;
            --size;
        

        }
        
        if(neg == true)
        {
            result.push_back('-');
            
        }

    }
    else
    {
        string d1;
        int digit = 0;
        digit = num1 + num2;
        //change integer digit into string
        d << digit;
        d >> d1;

        //add character to result string
        result = d1;
        result.insert(0, "-");

    }
 

    return result;
}