#include <iostream>


using std::cout, std::cin, std::endl;

int main(){
	
	int number;
	cout << "Enter number: " << endl;
	cin >> number;
	//int length = 0;
	//gives the length of the number 
	// save original number for later
	//int origNum = number;
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
		cout << "num " << number << endl;
		cout << "p " << prev << endl;
		cout <<  "d " << digit << endl; 
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


		cout << "ps " << prevSlope << endl;
		cout <<  "r " << range << endl;
		prev = digit;
		count++;

		if(preRange == range && count!= 1) 
		{
			return 'N';
		}



		
		
		cout << "c " << count << endl;

		cout << "s " << slope << endl;
		
		


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




	cout << 'r' << range << endl;
	
   
}


