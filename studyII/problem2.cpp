# include <iostream>


struct backQueue {
    char* array = nullptr;
    int capacity = 0;
    int size = 0;
};
 
//backQueue reference as queue

void push(backQueue& queue, char character) {
    // TODO: push()
    //if array is nullptr - capacity = 1
    //access struct with dot operator 
    if(queue.array == nullptr){
        queue.capacity = 1;
    }
    
    //char* newQ = new char[queue.capacity * 2];
    //check if size is greater than capacity --> array won't have enough space 
    //need to then double the capacity 
    if(queue.size > queue.capacity){
        //double the capacity
        //to resize array need to make new array with double the capacity
        //then copy values over
        //delete old array

        //make new array
        //create newQ outside of if statement to access outside of if statement?
        char* newQ = new char[queue.capacity * 2];
        //copy values over
        for (int i = 0; i < queue.size; ++i){
            newQ[i] = queue.array[i];
        }
        //once values are copied - need to delete old array bc its allocated on heap
        delete[] queue.array;
        //update capacity 
        queue.capacity = queue.capacity * 2;
        for(int i = 0; i < queue.size; ++i){
            queue.array[i] = newQ[i];
            
        }
        //need for loop to shift elements to right
        queue.size = queue.size + 1;
        for(int i = queue.size; i >=0; --i){
            //shift all element to right 
            queue.array[i+1] = queue[i];
        }
        //add new element to front of array 
            queue.array[0] = character;
        


        //queue.array[0] = character;
        //queue.size = queue.size + 1;
    }
    // else if (queue.size < queue.capacity){
    //     char* newQ = new char[queue.capacity];
    //     for (int i = 0; i < queue.size; ++i){
    //         newQ[i] = queue.array[i];
    //     }
    //     delete[] queue.array;

    // }

    //need to add new item to array 
    //pushback 
    //newQ[queue.size++] = character;
    //queue.array[0] = character;
    //queue.array[0] = start of array - pushback 
    //queue.size++ - one after the original size 


    //update size 
    //queue.size = queue.size + 1;

    


   
}
 

char pop(backQueue& queue) {
    // TODO: pop()
    //if no characters in queue??
    if(queue.array == nullptr){
        return '\0';
    }
    else{
        //find the last element in the array 
        char highest = queue.array[queue.size];
        return highest;
         //update size 
        queue.size = queue.size - 1;


    }
    //checks if nothing in array??
    for(int i = 0; i < queue.size; ++i){
        if(queue.array[i] == 0){
            return '\0';
        }
        else{
            char highest = queue.array[queue.size];
            return highest;
            //update size 
            queue.size = queue.size - 1;
        }
    }



  // for(int i = 0; i < queue.size; ++i){
  //   if(queue.array[i] == equeue.array[queue.size - 1]){
  //     for(int j = i; j < queue.size-1; ++j){
  //       queue.array[j] = queue.aray[j+1];
  //     }
  //   }
  // }
    
    
    


 
}
 
int main() {
    backQueue q;
 
    push(q, 'a');
    std::cout << pop(q) << '\n';
 
    // OPTIONAL TODO: add more test cases
   
    delete[] q.array;
}
