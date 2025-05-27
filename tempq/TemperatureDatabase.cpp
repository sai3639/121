#include "TemperatureDatabase.h"

#include <fstream>
#include <string> 
#include <vector>
#include <sstream>
#include <iostream> 
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function for part 1
	std::ifstream file;
  	file.open(filename);
  	if(file.fail()){
    	//throw std::invalid_argument("could not open file");
		cout << "Error: could not open file";
  	}
	while(!file.eof())
	{
		string w;
		getline(file,w);
		istringstream s1(w);

		string id;
		s1 >> id;
		// if(s1.fail())
		// {
		// 	cout << "Error: Other invalid input" << endl;
		// }

		int y;
		s1 >> y;
		//if(s1.fail())
		// {
		// 	cout << "Error: Other invalid input" << endl;
		// }
		if(y < 1800 || y > 2022)
	 	{
	 		cout << "Error: Invalid year " << y << endl ;
	 	}



		int m;
		s1 >> m;
		if(s1.fail())
		{
			cout << "Error: Other invalid input" << endl;
		}
	 	if(m <= 0 || m > 12)
		{
			cout << "Error: Invalid month " << m << endl;
	 	}




		double t;
		s1 >> t;
		// if(s1.fail())
		// {
		// 	cout << "Error: Other invalid input" << endl;
		// }
	 	if((t < -50 || t > 50) && t != -99.99)
	 	{
	 		cout << "Error: Invalid temperature " << t << endl;
	 	}
		records.insert(id, y, m, t);

	

	}
	
	
	
	// while(!file.eof()){
    // 	string w;
	// 	stringstream ss;
		
	// 	getline(file,w);
	// 	ss << w;
	// 	if(ss.fail())
	// 	{
	// 		cout << "Error: Other invalid input" << endl;
	// 	}
	// 	vector<string> w2;
	// 	string word;
    // 	while(ss >> word)
	// 	{
	// 		if(ss.fail())
	// 		{
	// 			cout << "Error: Other invalid input" << endl;
	// 		}
	// 		w2.push_back(word);
	// 	}

	// 	cout << "w2 " << w2[3] << endl;
	// 	stringstream i(w2[0]);
	// 	std::string i2;
	// 	i >> i2;
	// 	if(i.fail())
	// 	{
	// 		cout << "Error: Other invalid output" << endl;
	// 	}

	// 	stringstream y(w2[1]);
	// 	int ydate;
		
	// 	y >> ydate;
	// 	if(y.fail())
	// 	{
	// 		cout << "Error: Other invalid input" << endl;
	// 	}
		
	// 	if(ydate < 1800 || ydate > 2022)
	// 	{
	// 		cout << "Error: Invalid year " << ydate << endl ;
	// 	}
		
	// 	stringstream t(w2[3]);
	// 	double temp;
		
	// 	t >> temp;
	// 	if(t.fail())
	// 	{
	// 		cout << "Error: Other invalid input" << endl;
	// 	}
	// 	if(temp == NULL)
	// 	{
	// 		cout << "Error: Other invalid input" << endl;
	// 	}
	// 	if(temp < -50 || temp > 50)
	// 	{
	// 		cout << "Error: Invalid temperature " << temp << endl;
	// 	}

	// 	stringstream m(w2[2]);
	// 	int mon; 
		
	// 	m >> mon;
	// 	if(m.fail())
	// 	{
	// 		cout << "Error: Other invalid input" << endl;
	// 	}
	// 	if(mon <= 0 || mon > 12)
	// 	{
	// 		cout << "Error: Invalid month " << mon << endl;
	// 	}

	// }

}

// Do not modify
void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1
}
