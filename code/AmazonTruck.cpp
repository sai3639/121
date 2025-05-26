#include "AmazonTruck.h"
#include <fstream>
#include <sstream>


// Check if the truck is full
bool AmazonTruck::isFull() {
    return totalVolumeSoFar() > volume;
}

// Empty the truck of items
void AmazonTruck::makeEmpty() {
    // reset volume back to 1644;
    // Empty the *truck packages vector 
}

// Calculate the total volume of packages in the truck so far
unsigned short AmazonTruck::totalVolumeSoFar() {
    unsigned short totalVolume = 0;
    for (const auto& pkg : *truck) {
        totalVolume += pkg.getVolume();
    }
    return totalVolume;
}

// Fill the truck with packages from a file
void AmazonTruck::fillFromFile(string filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string addressStr, city, state, id;
        unsigned short width, height, depth;
        float weight;
        int zip;

        // Assuming the file contains data in the following order:
        // Address, City, State, ZIP, Width, Height, Depth, Weight, ID
        ss >> addressStr >> city >> state >> zip
           >> width >> height >> depth >> weight >> id;

        Address address(addressStr, city, state, zip);
        Dimension dimension(width, height, depth);
        Package package(address, dimension, id, weight);

        if (!isFull()) {
            // also should check if truck current volume can handle the next package
            truck->push_back(package);
        } else {
            cout << "Truck is full. Cannot add more packages." << endl;
            break;
        }
    }

    file.close();
}

// Display the last item in the truck
void AmazonTruck::displayLastItemInTruck() {
    if (!truck->empty()) {
        cout << "Last item in the truck: " << endl;
        cout << truck->back() << endl;
    } else {
        cout << "The truck is empty." << endl;
    }
}