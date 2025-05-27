#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if ((a < 10) || (b > 10000) || (a >b)){
		return false;
	}
	else{
		return true;
	}
}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
	int length = 0;
	int digit = 0;
    int count = 0;
    int prevDigit = 0;
    char range;
    char lastComp;
	char prevRange;
	//gives the length of the number 
	// save original number for later

    //check digits in loop/number slicing
    while (number!=0){
        digit = number%10;
        number = number/10;
        //compare digits with each other
        if (count != 0){
            //first digit < second digit (/)
            if (prevDigit > digit){
                range = 'M';
            }
            //first digit > second digit (\)
            else if (prevDigit < digit){
                range = 'V';
            }
            //previous digit = digit 
            else if ((prevDigit == digit)){
                // if there's consecutive slashes 
                // return N and break 
                range = 'N';
                break;
            }
            
            //save last comparison
            if (count == 1){
                lastComp = range;
            }

			if ((prevRange == range)){
				range = 'N';
				break;
			}
	

		}

		++count;
		++length;
		prevDigit = digit; 
		prevRange = range;

    }

    // outside while loop - compare firstComp with last range value 
    // check length of number first to see if even or odd 
    // number of digits
	if (length != 2){
		 // odd number of digits
    	if (length%2 != 0){
        	if ((lastComp == 'V') && (range == 'M')){
            	range = 'M';
        	}
        	else if ((lastComp == 'M') && (range == 'V')){
            	range = 'V';
        	}
    	
    	}
    	// even number of digits 
    	else if (length%2 == 0){
         	if ((lastComp == 'M') && (range == 'M')){
            	range ='M';
        	}
        	else if ((lastComp == 'V') && (range == 'V')){
            	range ='V';
        	}
    
    	}
	}
	else if (length == 2){
		if (lastComp == 'M'){
			range ='M';
		}
		else if (lastComp == 'V'){
			range ='V';
		}

	}
	return range;
   
}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
	// start by iterating from a to b
	int numMoun = 0;
	int numVall = 0;
	char range;
	for (int i=a; i<=b; ++i ){
		range = classify_mv_range_type(i);
		cout << i << range << endl;
		if (range == 'M'){
			numMoun += 1;
		}
		else if (range == 'V'){
			numVall += 1;
		}
	}
	cout << "There are " << numMoun << " mountain ranges and " << numVall << " valley ranges between " << a << " and " << b << "." << endl;


}


//look at left two digits to see if mountain or valley
//need variable for current digit and last digit 
//whether the digit goes up or down 
// pull first digit off before going to loop - previous digit 
//pull off next digit and compare to previous digit 
//know slope of last two digits if set up right - tells you if M or V