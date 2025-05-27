#include <iostream>
#include <cassert>
using std::cout, std::endl;
 
class Friends {
    //count = pointer
   int* count;
 
 public:
 //constructor with parameters 
   Friends(int num) : count{nullptr} {
    //a dynamic array? 
    //size of array = 1
    //num = number inputed into array 
      count = new int[1]{num}; //new = memory on the heap - need do delete
   }
      
   // TODO: add destructor
   ~Friends();
    
   // TODO: add copy constructor  
   Friends(const Friends& objToCopy);

   // TODO: add copy assignment operator    
   Friends& operator=(const Friends& objToCopy);
 
   void increment() { ++count[0]; }
 
   bool operator==(int rhs) { return count[0] == rhs; }

   private:
    void clear();

   
};


void Friends::clear()
{
    //to delete array - need to loop through array and delete each
    if(count != nullptr)
    {
        // for(int i = 0; i < 1; ++i)
        // {
        //     delete[] count[i];

        // }

        //delete
        delete[] count;

    }
    //set variables = 0 and pointer = nullptr
    count = nullptr;


}

Friends::~Friends()
{
    //call clear in destructor 
    clear();
}

//copy constructor
Friends::Friends(const Friends& objToCopy) : count(nullptr)
{
    count = nullptr;
    for(int i = 0; i < 1; ++i)
    {
        count[i] = objToCopy.count[i];
    }
    

}

//copy assignment
Friends& Friends::operator=(const Friends& objToCopy)
{
     for(int i = 0; i < 1; ++i)
    {
        count[i] = objToCopy.count[i];
    }
    return *this;
}




 
int main() {
   Friends v(42);
   Friends v2(v);
   
   assert(v == 42);
   assert(v2 == 42);
 
   v2.increment();
 
   assert(v == 42);
   assert(v2 == 43);
   
   v2 = v;
   
   assert(v == 42);
   assert(v2 == 42);
   
   v2.increment();
 
   assert(v == 42);
   assert(v2 == 43);
   
   cout << "So long, and thanks for all the fish!" << endl;
      
   return 0;
}