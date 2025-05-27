#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"
using namespace std;

int main(){
    
    ifstream file;
    string filename;
    cin >> filename;

    file.open(filename);
    if(file.fail()){
        cout << "Error: failed to open input file - " << filename;
        return false;
    }

     //store type (first line of file)
     string type;
    getline(file, type);

    //store size of file 
    string size;
    getline(file,size);

 
    //change into integers to compare with parameters given 

    string first = size.substr(0, size.find(" "));
    string sec = size.substr(size.find(" "), size.length());
    
    int int_width;
    int int_height;


    stringstream width1(first);
    stringstream height1(sec);

    width1 >> int_width;
    height1 >> int_height;
    int area = int_width * int_height;
    
    



     //store max
    string max;
    getline(file,max);
    int imax;

    stringstream m(max);

    m >> imax;
    
    string line;
    string word;
    istringstream iss;
    int r1;
    int g1;
    int b1;

  
    int count = 0;
   // ifstream line1;
    while(file.good()){
    //while(!file.eof())
    //get line in file
        //getline(file, line);
       // while(!file.eof()){
            // Pixel red;
            // Pixel green;
            // Pixel blue;

            file >> r1;
            if(r1 < 0){
                cout << "neg";
            }
            file >> g1;
            file >> b1;

           // cout << r1 << " " << g1 << " " << b1 << endl;

            //cout << i_r1 << endl;
            
           // cout << i_r1 << " " << i_g1 << " " << i_b1 << endl;
           count = count + 1;
            
    

    }
    // if(file.fail()){
    //     cout << "fail" << endl;
    // }
    // if(file.eof()){
    //     cout << "eof" << endl;
    // }
    if(count > area && file.eof()){
        cout << "too many numbers" << endl;

    }

    

  





    return 0;
}