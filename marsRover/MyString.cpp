// TODO: Implement this source file

#include <iostream>
#include <fstream>

#include "MyString.h"

//constructors 



MyString::MyString() :size_(0), capacity_(1), arr(nullptr)
{
    //constructs an empty string
    //length of zero characters
    //initalize character array to null character 
    capacity_ = 1;
    size_ = 0;
    char* arr = new char[capacity_]; 
    arr[0] = {'\0'}; 

}

MyString::MyString(const char* s):size_(0), capacity_(1), arr(nullptr)
{
    unsigned int i = 0;
    while(s[i]!='\0')
    {
        size_ += 1;
        ++i;
    }
}

//copy constructor
MyString::MyString(const MyString& origObject) :  size_(0), capacity_(1), arr(nullptr)
{

    size_ = origObject.size_;
    capacity_ = origObject.size_ + 1;
    //constructs a copy of str - copy of char arr 
    
    //size can be zero but avoid creating array on the heap if it is
    if(size_ > 0)
    {
        arr = new char[capacity_];
        if (arr = nullptr)
        {
            throw std::invalid_argument("unable to allocate memory");
        }

        //char* newAry = new char[capacity];

        //initialize each slot with val
        for(unsigned int i = 0; i < size_; ++i)
        {
             arr[i] = origObject.arr[i];
             
        }
        // delete [] arr;
        // arr = newAry;
        // newAry = nullptr;
    
    }
    arr[capacity_] == '\0';

}

//copy assignment
MyString& MyString::operator=(const MyString& objToCopy)
{
    //copies the null-terminated character sequence (c-string) pointed by s
    
        //delete[] arr;
        size_ = objToCopy.size_;
        capacity_ = objToCopy.capacity_;
        //arr = new char[capacity_];
       for(unsigned int i = 0; i < size_; ++i)
        {
            arr[i] = objToCopy.arr[i];
        }

   
 
    return *this;

}


MyString::~MyString()
{
    if(arr!=nullptr)
    {
        delete[] arr;
    }
    size_ = 0;
    capacity_ = 1;
    arr = nullptr;

}

size_t MyString::size() const noexcept
{
    return size_;
}


void MyString::resize(size_t n)
{
    capacity_ = (capacity_ + n);

    char* newAry = new char[capacity_];
    for(int i = 0; i < size_; ++i)
    {
        newAry[i] = arr[i];
    }
    for(int i = size_; i < capacity_; ++i)
    {
        //null characters for remaining capacity 
        newAry[i] = '\0';

    }

    //avoid memory leak
    delete [] arr;

    //update pointers
    arr = newAry;
    newAry = nullptr;
}


const char* MyString::data() const noexcept
{
    //return character array 
    return arr;


}

bool MyString::empty() const noexcept
{
    if(size_ == 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}


const char& MyString::front()
{
    return arr[0];

}

const char& MyString::at(size_t pos) const
{
    if(pos >= size_)
    {
        // std::stringstream msg;
        // msg << "Invalid index " << pos << " for size " << size;
        // throw std::out_of_range(msg.str());
        throw std::out_of_range("out of range bitch");


    }
    return arr[pos];


}

void MyString::clear() noexcept
{
    if(arr!=nullptr)
    {
        delete[] arr;
    }
    size_ = 0;
    capacity_ = 1;
    arr = new char[capacity_];
   // arr = nullptr;
    arr[0] = '\0';


}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
    //use for loop to add arr[i] to os in cout statement 

}



MyString& MyString::operator+=(const MyString& str)
{

}

size_t MyString::find(const MyString& str, size_t pos) const noexcept
{
   for(unsigned int i = pos; i < capacity_; ++i)
   {
    for(unsigned int j = i+1; j < capacity_;++j)
    {
        if(arr[i])
        {

        }

    }
   }
    return -1;
}
