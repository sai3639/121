#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Node.h"
#include "TemperatureData.h"
#include <sstream> 
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {
	// Implement this function

}

LinkedList::~LinkedList() {
	// Implement this function
	clear();
}

LinkedList::LinkedList(const LinkedList& source) : head(nullptr), tail(nullptr) {
	// Implement this function
	Node* cur = source.head;
	while(cur != nullptr)
	{
		cur = cur -> next;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// Implement this function
	if(this!= &source)
	{
		clear();
		Node* cur = source.head;
		while(cur != nullptr)
		{
			cur = cur->next;	
		}
	}
	return *this;
}


void LinkedList::insert(string location, int year, int month, double temperature) {
	// Implement this function
	//create new node
	Node* newNode = new Node(location, year, month, temperature);
	Node* current = head;
	Node* prev = nullptr;
	
	if(head == nullptr)
	{
		head = newNode;
		tail = newNode;
		return;
	}
	
	// if(newNode < head)
	// {
	// 	newNode->next = head;
	// 	head = newNode;
	// 	return;
	// }
	if(*newNode < *current)
	{
		head = newNode;
		newNode->next = current;
		return;
	}

	//while not at end of list or the current data is not greater than newNode's data
	else{
	while(current->next)
	{
		if(*newNode < *current->next)
		{
			newNode->next = current->next;
			current->next = newNode;
			return;
		}
		current = current->next;
	}
	//tail = newNode;

	// if(current == nullptr)
	// {
	// 	prev->next = newNode;
	// 	tail = newNode;

	// }

 }
 tail = newNode;
 current->next = newNode;
 return;

	 
	


	// while(current!=nullptr)
	// {	
	// 	if(current->next->data.id < newNode->data.id)
	// 	{
	// 		//cout << "this is ! (1)" << endl;
	// 		current->next = newNode;
	// 		current = newNode;
	// 		return;

	// 	}
	// 	else if(current->next->data.id == newNode->data.id && current->next->data.year <= newNode->data.year)
	// 	{
	// 		if(current->next->data.month < newNode->data.month)
	// 		{
	// 			//cout << "this is true (2)" << endl;
	// 			current->next=newNode;
	// 			current = newNode;
	// 			//cout << "nd (2) " << newNode->data.id << endl;
	// 			//cout << "cd (2) " << current->data.id << endl;
	// 			return;
	// 		}
	// 		else
	// 		{
	// 			//cout << "incrementing (3)" << endl;
	// 			current = current->next;
	// 			//cout << "Ic (3) " << current->data.id << endl;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		//cout << "incrementing (4)" << endl;
	// 		current = current->next;
	// 		//cout << "IC (4) " << current->data.id << endl;
	// 	}
		
	// }

	//once out of loop - found data that is greater than newNode's data
	//add node 
	

	
}

void LinkedList::clear() {
	// Implement this function
	// Node* a = head;
	// Node* b = tail;
	while(head!= nullptr)
	{
		Node* delNode = head;
		head = head-> next;
		delete delNode;
	}
	head = nullptr;
	tail = nullptr;
	

}

Node* LinkedList::getHead() const {
	// Implement this function it will be used to help grade other functions
	return head;
}

string LinkedList::print() const {
	string outputString, id, year, month, temperature;
	// Implement this function
	//stringstream
	std::ostringstream ss;
	Node* t = head;
	//std::ostringstream ss;
	while(t != nullptr)
	{
		ss << t->data.id << " " << t->data.year << " " << t->data.month << " " << t->data.temperature << '\n';
		t = t->next;
		// if(t !=nullptr)
		// {
		// 	ss << endl;

		// }
	}
	outputString == ss.str();
	
	
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
