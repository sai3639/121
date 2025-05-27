/*
 * TemperatureData.cpp
 *
 *  Created on: Jul 16, 2018
 *      Author: student
 */

#include "TemperatureData.h"
#include <string>
using namespace std;

TemperatureData::TemperatureData() : year(1800), month(0), temperature(0.0) {} //initialize everything

TemperatureData::TemperatureData(std::string id, int year, int month, double temperature) : id(id), year(year), month(month), temperature(temperature)//initialize everything
{
	
} 

TemperatureData::~TemperatureData() {} // You should not need to implement this

bool TemperatureData::operator<(const TemperatureData& b) {

	

	if(this->id<b.id)
	{
		//cout << "id y" << endl;
		return true;
	}
	if( this->id == b.id && this->year<=b.year)
	{
		if(this->month < b.month)
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}
	// else if(this->month < b.month)
	// {
	// 	cout << "month y " << endl;
	// 	return true;
	// }
	// else if(this->temperature < b.temperature)
	// {
	
	// 	return true;
	// }
	else
	{
		return false;
	}
	
	
	
	
	
	
	
	// else if(this->id >= b.id)
	// {
	// 	if(this->year < b.year )
	// 	{
	// 		return true;
	// 	}
	// 	else if(this-> year >= b.year)
	// 	{
	// 		if(this->month < b.month)
	// 		{
	// 			return true;
	// 		}
	// 		else if(this->month >= b.month)
	// 		{
	// 			if (this->temperature < b.temperature)
	// 			{
	// 				return true;
	// 			}
	// 			else
	// 			{
	// 				return false;
	// 			}
	// 		}
	// 	}
	// }

}

