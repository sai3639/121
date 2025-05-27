// TODO: Implement this header file
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <stdexcept>




//start by defining a class named myString
class MyString
{
    //next define private members to hold size and capacity insdie this 
    //new class
    private:
      

        size_t size_ =0; 
        size_t capacity_;
        

        char *arr; 

        //void increaseCapacity();



    public:
    
       MyString();
       //MyString(char const*);
       //copy constructor - shallow
       MyString(const MyString& origObject);
       //copy constructor - deep
       MyString& operator=(const MyString& objToCopy);
       MyString(const char* s);

       //destructor
       ~MyString();


       void resize(size_t n);
       //need const??
       //check these bitch
       size_t capacity() const noexcept {return capacity_;};
       size_t size() const noexcept;
       //same thing as size??  cons
       size_t length() const noexcept {return size_;}; 
       const char* data() const noexcept; //returns whole string + null character 
       bool empty() const noexcept;
       const char& front() const;
       const char& at(size_t pos) const;
       void clear() noexcept;
       //check parameters 
       friend std::ostream& operator<< (std::ostream& os, const MyString& str);
       //MyString& operator= (const MyString& objToCopy);
       MyString& operator+= (const MyString& str);
       size_t find(const MyString& str, size_t pos = 0) const noexcept;
       



};



// void MyString::increaseCapacity() 
// {
//     if(capacity_ == 0)
//     {
//         capacity_ = 1;
//     }
//     else
//     {
//         capacity_ += 2; //capacity = capacity * 2;
//     }

//     //create new array on heap
//     char* newAry = new char[capacity_];
//     if(newAry == nullptr)
//     {
//         throw std::invalid_argument("unable to allocate memory for character array");

//     }

//     //copy
//     for(int i = 0; i < size_; ++i)
//     {
//         newAry[i] = arr[i];
//     }

//     //avoid memory leak
//     delete [] arr;

//     //update pointers
//     arr = newAry;
//     newAry = nullptr;
    
// }



#endif
