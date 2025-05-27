#include <string>
#include "Node.h"
#include <iostream> 

using namespace std;

// Default constructor
Node::Node() : data(), next (nullptr)//, id("1234"), year(-1), month(-1), temperature(-99.99),next(nullptr) 
{
	data = TemperatureData();
	//TemperatureData(data.id, data.year, data.month, data.temperature);
} 
// remember to initialize next to nullptr

// Parameterized constructor
Node::Node(string id, int year, int month, double temperature) : data(), next(nullptr)// id("1234"), year(-1), month(-1), temperature(-99.99), next(nullptr){}
{
	data = TemperatureData(id, year, month, temperature);
}

// remember to initialize next to nullptr

bool Node::operator<(const Node& b)
{
	
	//TemperatureData data = {data.id, data.year, data.month, data.temperature};


	//cout << "d " << data.id << endl; 


	//cout << "id " << id  << " " << b.data.id << endl;
	//cout << data(id);

	if(this->data.id<b.data.id)
	{
		return true;
	}
	if( this->data.id == b.data.id && this->data.year<=b.data.year)
	{
		if(this->data.month < b.data.month)
		{
			return true;
		}
		else
		{
			return false;
		}
	
	}


	return this->data < b.data;
}
