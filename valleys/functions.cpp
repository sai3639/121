#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range

	//check first and second digit 
		if ((a < 10) || (b >= 10000) || (a > b)){
		return false;
	}
	if(a < 0 || b < 0)
	{
		return false;
	}
	else{
		return true;
	}
}


	//return false;


char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
	int digit = 0;
	int prev = number%10;
	number = number/10;
	char slope; 
	char prevSlope;
	char range; 
	char preRange;
	int count = 0;

		while(number!= 0)
	{
		digit = number%10;
		number /= 10;
		// cout << "num " << number << endl;
		// cout << "p " << prev << endl;
		// cout <<  "d " << digit << endl; 
		prevSlope = slope;
		preRange = range;

		//compare prev with digit
		if(digit < prev)
		{
			slope = 'p';
		}
		else if (digit > prev)
		{
			slope = 'n';
		}

		else if(prevSlope == slope)
		{
			//cout << "equal" << endl;
			return 'N';
		}
	
		if(prevSlope == 'p' && slope == 'n')
		{
			range = 'M';
		}
		else if (prevSlope == 'n' && slope == 'p')
		{
			range = 'V';
		}


		// cout << "ps " << prevSlope << endl;
		// cout <<  "r " << range << endl;
		prev = digit;
		count++;

		if(preRange == range && count!= 1) 
		{
			return 'N';
		}



		
		
		// cout << "c " << count << endl;

		// cout << "s " << slope << endl;
		
		


	}

		
	if(range == 'V' && count!=1)
		{
			return 'M';
		}
		else if(range == 'M' && count!=1)
		{
			return 'V';
		}
		else if(count == 1 && slope == 'p')
		{
			range =  'M';
			return range;
		}
		else if(count == 1 && slope == 'n')
		{
			range = 'V';
			return range;
		}



	
}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt

	int numMoun = 0;
	int numVall = 0;
	char range;
	for (int i=a; i<=b; ++i ){
		range = classify_mv_range_type(i);
		//cout << i << range << endl;
		if (range == 'M'){
			numMoun += 1;
		}
		else if (range == 'V'){
			numVall += 1;
		}
	}
	cout << "There are " << numMoun << " mountain ranges and " << numVall << " valley ranges between " << a << " and " << b << "." << endl;


}