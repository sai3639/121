#include <ostream>
#include <iostream>
using std::cout;

struct Node {
 public:
    double value; 
    Node* next;
    Node(double num) : value{num}, next{nullptr} {}
};
 
class CircList {
 private:
    Node* listptr;
 public:
    // Constructor
    CircList() : listptr{nullptr} {}

    // The insertNode function inserts a node with num copied to its value
    // member so that the list remains sorted in non-decreasing order.                 
    void insertNode(double num);
    // TODO(student): implement this function
 
    void print(std::ostream& os=std::cout) const {
        // assumed to exist
        // prints the list to the output stream (default: stdout)
    }
 
    // The mergeArray function merges the array passed into dArray into the
    //  ordered list.     	 
    void mergeArray(double dArray[], size_t size);
    // TODO(student): implement this function
 
};



void CircList::insertNode(double num)
{
    //need to create new node
    Node* newNode = new Node(num);

    //making sure node is inserted in the right place

    //go through the linked list until finding a number greater than
    //num stored in node being inserted 

    //create node to store current place
    Node* current;
    Node* prev;

    //if head = nullptr - where listptr = head and tail
    //when list is empty - last pointer == nullptr
    if(listptr == nullptr)
    {
        newNode->value;
        newNode->next = listptr->next;
        listptr->next = newNode;
        // listptr = newNode;

        // //link single node to itself
        // newNode->next = listptr;

    }
    else
    {
        //if list not null
        //newNode->next = current;
        //current->next = ndewNode;

        //search for position
        while(current!=nullptr)
        {
            //need to compare current data with newNode data 
            if(current->value < newNode->value)
            {
                prev = current;
                current = current->next;
            }
            else 
		{
			if(prev == nullptr)
			{
				newNode->next = listptr;
				listptr = newNode;
			}
			else 
			{
				prev->next = newNode;
				newNode->next = current;
			}
			break;
        }

    }


}


void CircList::mergeArray(double dArray[], size_t size)
{
    for(int i < 0; i < size; ++i)
    {
        insertNode(dArray[i]);
    }
}