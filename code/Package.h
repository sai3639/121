/*
 * Package.h
 *
 *  Created on: Jan 10, 2020
 *      Author: Prof. Lupoli
 */

#ifndef PACKAGE_H_
#define PACKAGE_H_

#include <iostream>
#include <string>
using namespace std;

#include "Address.h"
#include "Dimension.h"

class Package {
public:
	Package();
	Package(Address &a, Dimension &d, string id, float weight);

	const Address& getAddress() const { return address; }
	void setAddress(const Address& address) { this->address = address; }

	const Dimension& getDimension() const { return dimension; }
	void setDimension(const Dimension& dimension) { this->dimension = dimension; }

	const string& getId() const { return ID; }
	void setId(const string& id) { ID = id; }

	float getWeight() const { return weight; }
	void setWeight(float weight) { this->weight = weight; }

	float getVolume() const { return volume; }
	void setVolume(float volume) { this->volume = volume; }
	
	// overloaded cout
	 friend std::ostream& operator<<(std::ostream& os, const Package& pkg) {
        os << "Package ID: " << pkg.ID << "\n"
           << "Address: " << pkg.address << "\n"
           << "Dimension: " << pkg.dimension << "\n"
           << "Weight: " << pkg.weight << " kg\n"
           << "Volume: " << pkg.volume << " cubic units";
        return os;
    }

protected:
	string ID;
	float weight;
	Dimension dimension;
	Address address;
	float volume;
	

};

inline Package::Package()
{
	ID = "";
	weight = 0.0;
}

inline Package::Package(Address &a, Dimension &d, string id, float weight)
{
	this->address = a;
	this->dimension = d;
	this->ID = id;
	this->weight = weight;
}

#endif /* PACKAGE_H_ */
