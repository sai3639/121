#include <iostream> // input and output libraries 

using std::cout, std::cin, std::endl;


int sumDigits(int number){
	int sum = 0;
	while (number != 0) {
		int digit = 0;
		digit = number%10;
		sum += digit;
		number /=10;
	}
	return sum;
}

int countDigits(int number) {
	int count = 0;
	while (number != 0){
		count++; 
		number  /= 10;
		
	}
	return count;
}

void printMenu() {
	std::cout << "C) Count Digits" << std::endl;
	std::cout << "S) Sum of Digits" << std::endl;
	std::cout << "Q) Quit" << std::endl;
}


int main(){
	char menuChoice = '5';
	while (toupper(menuChoice) != 'q') {
		printMenu();
		std::cin >> menuChoice;
		int number = 0;
		switch (menuChoice) {
			case 'C':
			case 'c':
			cout << "Enter number to count digits: ";
			cin >> number;
			cout << countDigits(number) << endl;
			//call function to count digits
			break;
			case 'S':
			case 's':
			cout << "Enter number to sum digits: ";
			cin >> number;
			cout << sumDigits(number) << endl;
			//call function to get sum of digits
			break;
		}
	}
	std::cout << "Leaving program" << std::endl;	
	//return 0;
}