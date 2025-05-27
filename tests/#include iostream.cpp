#include <iostream>


using std::cout, std::cin, std::endl;

char main(){
	int number;
	cout << "Enter number: " << endl;
	cin >> number;
	int length = 0;
	//gives the length of the number 
	while (number != 0){
		number /= 10;
		++length;
	}

    int digit = 0;
    int index = length - index - 1;
    int count = 0;
    int prevDigit = 0;
    char range = ' ';
    char firstComp = ' ';
    //check digits in loop/number slicing
    while ((number!=0) && (count <= index)){
        digit = number%10;
        number = number/10;
        
       
        //compare digits with each other
        if (count != 0){
            //first digit < second digit (/)
            if (prevDigit < digit){
                range = 'M';
            }
            //first digit > second digit (\)
            else if (prevDigit > digit){
                range = 'V';
            }
            //previous digit = digit 
            else if (prevDigit == digit){
                // if there's consecutive slashes 
                // return N and break 
                return 'N';
                break;
            }
            
            //save first comparison
            if (count = 1){
                firstComp = range;
            }
            
        }
    

    }

    // outside while loop - compare firstComp with last range value 
    // check length of number first to see if even or odd 
    // number of digits

    // odd number of digits
    if (length%2 != 0){
        if ((firstComp == 'M') && (range == 'M')){
            return 'M';
        }
        else if ((firstComp == 'V') && (range == 'V')){
            return 'V';
        }
        else{
            return 'N';
        }
    }
    // even number of digits 
    else if (length%2 == 0){
         if ((firstComp == 'M') && (range == 'M')){
            return 'M';
        }
        else if ((firstComp == 'V') && (range == 'V')){
            return 'V';
        }
        else{
            return 'N';
        }
    }


    
}











