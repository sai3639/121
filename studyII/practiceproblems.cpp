
#include <iostream>
// #include "fn.h"
// #include "fn.cpp"
using namespace std;

//double pathlength 
//m = 3
//path[] = 0, 1, 2
//values = [0,1][1,2] and add them together 
double pathLength(double** distance, int n, int* path, int m){
    //for loop to traverse array
    int total = 0;
    for(int i = 0; i < m; ++i){
        total += distance[path[i]][path[i+1]];

    }

}



int main()
{
    //create a 2D matrix 
    double** distance = new double*[10];
    for(int i = 0; i < 10; ++i){
        distance[i] = new double[10];
    }
    //fill in array elements with 0 
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            distance[i][j] = 0;
        }
    }

    //delete array one done with
    for(int i = 0; i < 10; ++i){
        //delete all arrays in distance array 
        delete[] distance[i];
    }
    //delete array storing arrays
    delete[] distance;

}