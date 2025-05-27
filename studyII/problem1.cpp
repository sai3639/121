#include <iostream>
using std::cout;
using std::endl;
using std::string;


//&a is passed by referene 
int howdy(int &a, int b);
//howdy(y,s) where y = a - a is being passed by reference through y
//&d passed by reference 

int gigEm(int c, int& d);
//gigEm(s, t) where t = d

struct thing {
   string label;
   int howMany;
   thing() : label(""), howMany(0) {}
};

int main() {
   int s = 5;
   int t = 4;
   
   int y = gigEm(s, t);
   
   int z = howdy(y, s);

    //thing = pointer to struct 
    //pointer = memory address - so thing* is pointing to the memory address of thing?
    // new keyword - used to allocate space on heap 
    //some/many are allocated on heap and store memory address 
    //allocating memory using new keyword 
    //constructs object at new allocated space 
   thing* some = new thing();
   thing* many = new thing();


    //used to access memebers of struct through pointer 
    //label and howmany can change - heap
   some->label = "Shoe";
   some->howMany = y;
   many->label = "Toy";
   many->howMany = z;

   cout << "Items from the " << s << "&" << t << " store" << endl;
   //calling pointer some struct label 
   //accessing struct using dot operator - pointer allows change in variable 
   //keeps changed value - could have passed by reference? 
   cout << (*some).label << "'s quantity: " <<
      (*some).howMany << endl;
   cout << (*many).label << "'s quantity: " <<
      (*many).howMany << endl;

  //delete's pointer some but not many? 
  delete some;
  //sets many to nullptr so it doesn't reference allocated memory anymore 
  //now can't access data that has been allocated and can't delete it - memory leak
  many = nullptr;
}

//functions


//a being passed by reference 
int howdy(int &a, int b) {
   cout << "a " << a << endl;
   //a = 5 - pass by reference (c) where a  = c
   //changing a changes c 
   cout << "b " << b << endl;
   // b = 10 - pass by reference (d) b = d
   // changing b changes d 
   a /= 4;
   b *= 3;
   int temp = a + b + 9;
   return temp;
}

//d being passed by reference 

int gigEm(int c, int& d) {
    cout << "d1 " << d << endl;
   d = 10;
   //trying to pass variable c into new function? - c passes by reference in howdy
   //function
   cout << "c " << c << endl;
   //c = 5
   cout << "d " << d << endl;
   // d = 10
   int temp = howdy(c, d);
   temp += c;
   cout << "temp " << temp << endl;
   return temp;
}


// s = 5
// t = 4
// y = gigEm(s,t) - (5,4)
//z = howdy(y,s) - (y, 5)

//gigem called first
// (c, d) = (c, 10)
//d = t
// where d starts off as 4 because it is passed by ref and then changes to 10 in
//gigEm function 

//c = 5 when passed through howdy function
//bc a is passed by reference and gigEm sets c = 5 
// a = y = c
// a = c - like a temp variable holding the value of c 


//don't need to delete references - they basically only exist in source code 
//memory leak caused by pointers - some or many 

//t, a, d = heap
//some and many = heap
//temp = stack 


//reference - way for us to reference an existing variable
    //not new variables 

    //& in front of existing variable - asking the variable its memory address

//pointers help manage and manipulate memory
//pointer - an integer that stores a memory address

//main purpose of new is to allocate space on the heap 
//returns pointer to that memory address
//new returns pointer
    //allocate on heap