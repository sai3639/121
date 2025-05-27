#ifndef NODE
#define NODE

#include "TemperatureData.h"
#include <string> 
#include <iostream> 
using namespace std;
struct Node {
	TemperatureData data;
	Node* next;
	//Node* prev;
	//Node* current;
	// std::string id = "1234"; //= data.id;
	// int year = -1;// = data.year;
	// int month = -1;// = data.month;
	// double temperature = -99.99; 


	// Default constructor
	Node(); // remember to initialize next to nullptr
	Node(string id, int year, int month, double temperature); // remember to initialize next to nullptr

	// This operator will allow you to just ask if a node is smaller than another
	//  rather than looking at all of the location, temperature and date information
	bool operator<(const Node& b);

  // The function below is written. Do not modify it
	virtual ~Node() {}
};

#endif
