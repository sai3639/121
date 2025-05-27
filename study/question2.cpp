#include <iostream>


using std::cout, std::endl, std::cin;

void decode(char alphabet[], unsigned int nums1[], unsigned int nums2[], unsigned int size){



     //find size of alphabet/see whats in alphabet
     unsigned int count = 0;
     unsigned int alpha = 0;
     for (unsigned int i = 0; alphabet[i] != '\0'; ++i){
        count+= 1;
        //throw exception
        if (isalpha(alphabet[i])){
            alpha += 1;
            //throw std::invalid_argument("no characters to use")
        }
     }
    // cout << count;

     // if alpha = 0 - there are no characters in alphabet - throw exception

     if (alpha == 0){
        throw std::invalid_argument("no characters to use");
     }

     // throw exception of count of alphabet = 0
     if (count == 0){
        throw std::invalid_argument("size of alphaet is zero");
     }


    //for loop - go to size given
    // if i is even - select numbers from num2
    // if i is odd - select numbers from num1

    //initialize variable that stores int of num1 or num2

    unsigned int digit = 0;


    for(unsigned int i = 1; i <= size; ++i){
        // find number in first num1 
        //then switch to num2

        // assigne the number in index i to digit from either nums1 or nums2
        if (i%2 != 0){
            digit = nums1[i];

        }

        else if (i%2 == 0){
            digit = nums2[i];
        }

        //wrap around? 
        // if size of alphabet == 4 (0, 1, 2, 3, 4)
        // then wrap around == index # - size - 1 (accounting for starting at 0)

        if (digit > count){
            digit = digit - count;
        }

        // print the index digit of the alphabet
        // if digit = 0 ; alphabet[0] = a assuming alphabet = [a, b, c]
        cout << alphabet[digit];





    }

}


int main(){

    // char a[] = {"abcdefghijklmnopqrstuvwxyzabcdefghij"};
    // unsigned int n1[] = {43,11,56};
    // unsigned int n2[] = {4,5,18};
    // unsigned int s = 6;

    // decode(a, n1, n2, s);


    



    return 0;
}


