
//Input/output streams 





//pointers
//memory = important 
//pointers help manage and manipulate memory
//pointer - an integer that stores a memory address
//memory in a computer is a linear 1D line
//pointer tell us where a specific byte of memory is 
//code reads and wrties from memory 

//stack stuff
//Ex 1 
//void doesn't care what type the data is 
void* ptr = 0; //0 is not a valid memory address - 0 means NULL (nullptr)
//giving a pointer a type means you assume that the thing at that memory address
//is that type
//type doesn't change what a pointer is 

//Ex 2
int var = 8;
void* ptr = &var;
//& in front of existing variable - asking the variable its memory address
//taking memory address from that variable and assigning it to new variable ptr
//integer = 4 bytes of data
//types are useful for manipulation of memory

//Ex 3
int var = 8;
int* ptr = &var;
//dereferencing pointer - write to/read from data (access data)
*ptr = 10; //changing var from 8 to 10 


//creating variable on heap 
//Ex 4
char* buffer = new char[8];
//8 bytes of memory and returning a pointer to the beginning of that block of memory
//need to delete memory when allocating on heap 
delete[] buffer;

//pointers are variables themselves and have their own memory address
//this is how you can get pointer to pointers (double pointers), etc.
//pointer to pointer
    //have a variable storing a memory address that is pointing to another 
    //variable that is storing a memory address
//Ex 5
char* buffer = new char[8];
//pointer to pointer 
//set equal to memory address of buffer 
char** ptr = &buffer;
delete[]buffer;

//References - extension of pointers
//pointers and references are pretty much the same thing
//reference - way for us to reference an existing variable
    //not new variables 

//Ex 1
int a = 5;
//make a reference
int& ref = a;
//ref variable doesn't really exist - just used in source code
ref = 2;
//changes a to 2 (ref = a)

//Ex 2
void Increment (int* value)
{
    //creates a brand new value instead of changing original - have to pass 
    //variable by reference in order to change a 
    (*value)++;
    //need to dereference variable in order to change value isntead of 
    //just changing memory address 
}
main{
    int a = 5;
    Increment(&a);
    //pass memory address of variable in order to modify variable
}

//Ex 3 - same result but pass by reference instead of pointer
void Increment(int& value)
{
    value++;
}
int main{
    int a = 5;
    Increment(a);
}
//once you declare a reference you can not change that reference 
//need to assign a referene to something once you declare it


//Arrays
//pointers are the base for how arrays work 
//array = collection of things (variables)
    //represent a whole bunch of data - instead of creating a bunch of variables

//Ex 1
//array of five integers
int example[5];
//accessing index 1 of array
example[0] = 2;
//last index
example[4] = 4;
//example is a pointer type so cout example will give memory address

//arrays go well with for loops 
for(int i = 0; i < 5; ++i)
{   
    //set everything in array equal to 2
    example[i] =2;
}
//arrays store value in a row in memory

//arrays are just integer pointers
int main()
{
    int example[5];

    int* ptr = example;
    example[2] = 5;
    //set value of example[2] to 6
    //4*2 = 8 - 2 four bytes to get to memory address of example[2]
    *(ptr + 2) = 6;

    for (int i = 0; i < 5; ++i)
    {
        example[i] = 2;
    }

}

//arrays on the heap
int main()
{
    //creates array on heap (int example[5])
    int* another = new int[5];
    for(int i = 0; i < 5; i++)
    {
        another[i] =5;
    }
    //need to delete 
    delete[] another;
}
//creating arrays on heap allows for longer lifetime 
//using array from function 
//indirection of memory 
//usually want to create arrays on stack 
//no way to know size of array 


//New keyword 
//main purpose of new is to allocate space on the heap 
//returns pointer to that memory address

int main()
{
    int a = 2;
    //new returns pointer
    //allocate on heap - b stores memory address
    int* b = new int;
    //allocate array on heap 
    int* c = new int[50]; //200 bytes
    delete b; 
    delete[] c;

}






//dynamic arrays

//vector class - vector is basically an array - array can resize 

struct Vertex
{
    float x, y, z
}

#include vector
int main()
{
    //tied to size even when allocating on heap
    Vertex vertices[5];
    vertex* vertices = new Vertex[5];
    //using vector to make resizable array
    std::vector<Vertex> vertices;
    vertices.push_back({1,2,3});
    vertices.push_back({4,5,6});

    for (int i = 0; i < vertices.size(), ++i)
    {
        std::cout << vertices[i] << std::endl;

    }

}


//2D arrays
//array of arrays - collection of arrays
int main()
{
    //heap allocation
    int* array = new int[50];
    //2d array - pointer of pointers
    //pointer to collection of int pointers
    int** a2d = new int*[50]; //allocating 50 integer pointers - 200 bytes of memory
    for (int i = 0; i < 50; ++i)
    {
        //allocate 50 arrays
        //each one of the arrays/each location is stored inside a2d array
        a2d[i] = new int[50];
    }

    a2d[0][0] = 0; //access first element
    a2d[0][1] = 0; 


    //delete array
    for(int i = 0; i < 50; ++i){
        delete[] a2d[i]; //delete the 50 arrays
    }
    delete[] a2d; //delete array that was storing all the arrays 

}
//3d array - nested for loop 
int*** a3d = new int**[50];
for (int i = 0; i < 50; ++i)
{
    a3d[i] = new int*[50];
    for (int j = 0; j < 50; ++j){
        a3d[i][j] = new int[50];
    }
}


//Ex 2
int** a = new int*[rowCount];
for(int i = 0; i < rowCount; ++i)
{
    a[i] = new int[colCount];
}


double** inputArray = new double*[row];
inputArray[0] = new double[col]{0.5, 2.0, 1.2, 3.0};
inputArray[1] = new double[col]{-1.0, 1.5, 3.0, 2.4};
inputArray[2] = new double[col]{0.0, 1.0, 1.5, 2.0};

//Stack vs Heap
//stack and heap are two areas in RAM
//stack usually has predefined size
//heap can grow and change 
//memory is used to store data 
//memory allocation 

//Ex 1
struct Vector3
{
    float x, y, z;
};
int main()
{
    //stack allocation
    int value = 5;
    int array[5];
    Vector3 vector;

    //vs heap allocation
    int* hvalue = new int;
    *hvalue = 5;
    int* harray = new int[5];
    Vector3* hvector = new Vector3(); 
}

