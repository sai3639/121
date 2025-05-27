#include <iostream>


using std::cout, std::endl, std::cin;

int main(){


    //question 1 


    //read integer from standard input 
    int num;
    cin >> num;
    int num2 = num;
    //read through the digits of the integer and compare them with some 
    //number i that increases by 1 
    //for loop 
    //could change int into string using sstream -- too much work? 
    //find size of input number/how many digits are in number
    // int digits = 0;
    // while(num){
    //     num/=10;
    //     digits++;
    // }
    //cout << digits;
   // cout << num;

    //find if number is negative first

    bool neg = false;
    if (num < 0){
        neg = true;
    }




    int sum = 0;
    int i = 1;
	while (num2 != 0) {
		int digit = 0;
		digit = num2%10;
		num2 /=10;
        //cout << digit << endl;
        //out << sum << endl;
        //find if digit is divisible by i and add rating 
        //no remainder
        //if positive integer
        if(neg == false){
            if ((digit%i == 0)){
                sum += 1;
            }
            //sum+= 1;
        }
        //if negative integer 
        else if (neg == true){
            if ((digit%i == 0)){
                sum += 0;
            }
            else if ((digit%i != 0)){
                sum += 1;
            }
            

        }

        //multiply by negative 1 if negative number
       

      //  cout << i << " "<< digit << " " << sum << endl;

      //increment i 
        ++i;

    }

    if (neg == true){
            sum = sum * -1;
        }

    //print sum 
    cout << sum << endl;

    //go through number a # of i times incrementing i
    //getting individual digits of a number
    // given number 12345
    // 5 is 12345 % 10
    // 4 is 12345 /10 %10
    // 3 is 12345 /100 %10
    //2 is 12345 /1000 % 10
    //1 is 12345 % 10000 % 10

    //sum ratings of individual digits
    // double sum = 0;
    // for(double i = 0; i < digits; ++i){
    //     double dig;
    //     dig = ((num/(10*i)));
    //     //cout << dig << endl;

    // }

 

    


    return 0;
}