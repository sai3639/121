#include <iostream>
#include <vector>
using namespace std;



// void minusOddColumn(int** mat, int n)
// {
//     //declare 2d array mat nxn
//     int** mat = new int*[n];
//     for(int i = 0; i < n; ++i){
//         mat[i] = new int[n];
//     }

//     //iterate through 2D array
//     for(int i = 0; i < n; ++i){
//         for(int j = 0; j < n; ++j){

//         }
//     }




// }


// int main()
// {
    
// }

int* get_even_numbers(int*A, unsigned int n, unsigned int& m){
    //create new array
    //int* B = new int[n]; //have extra space in array 
    vector<int> B; //undefined size 

    //vector <int> = B; - make an array without a specfic size 
    //check if array elements are >= 0
    //iterate through arrray
    for(int i = 0; i < n; ++i){
        if(A[i] < 0){
            return false;
        }
        //if array element is even
        else if(A[i]%2 == 0){
            //store value of A[i] into B[i]
            //increment m? 
            B[i] = A[i];
            m = m + 1;


        }

    }
}