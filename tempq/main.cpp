#include "TemperatureDatabase.h"

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	if (argc < 3) {
		cout << "Usage: " << argv[0] << " data_file query_file" << endl;
		return 1;
	} else {
		TemperatureDatabase database;
		database.loadData(argv[1]);
		// database.outputData(argv[1]); // comment out before submitting Part 2
		// database.performQuery(argv[2]); // Will be done in Part 2
	}

	// LinkedList ll;
	// ll.insert("411048", 2016, 3, 14.82);
	



}
