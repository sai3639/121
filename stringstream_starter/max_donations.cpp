#include <iostream>
#include <sstream>
#include <fstream>
using std::cin, std::cout, std::endl, std::string, std::getline,
      std::ifstream, std::istringstream;

int main() {
  string filename;
  cout << "Enter donation filename: ";
  cin >> filename;
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Failed to open file " << filename << "." << endl;
    return 1;
  }
  
  double maxTotalDonation = 0;
  int maxTotalCollector = 0;
  string line; 
  double total = 0;
  double highest = 0;
  int collector = 0;
  int count = 0;
  bool don = true;
 
  
  // read data
  while(!ifs.eof()){
  //  maxTotalDonation = 0;
     
    ifs >> maxTotalCollector;
   // collector = maxTotalCollector;
    
    getline(ifs, line);
    
  
    istringstream donation(line);

    if(line.size()==0){
      don = false;
    }


    // if (line.find(' ') > 0){
    //    cout << line << endl;
      
      
    // }

    
    while(!donation.eof()){
      donation >> maxTotalDonation;
      total += maxTotalDonation;
      count +=1;
    }

    //cout << maxTotalDonation << endl;
   // cout << count << endl;
  
  
    //maxTotalDonation = 0;
   // cout << total << endl;
    
    if(total > highest && count != 1){
      highest = total;
      collector = maxTotalCollector;
     //cout << "M " << maxTotalCollector << endl;

    }
    //highest = total;

    //cout << "H " <<  highest << endl;




    total = 0;
    count = 0;
    

  }

  maxTotalDonation = highest;
  //cout << maxTotalCollector << endl;
  //cout << collector << endl;
  maxTotalCollector = collector;

  

  
  //total = 0;
  
  

  //   total = maxTotalDonation;



  // }
  // cout << collector << " " << total << endl;
  
    
  if(don == true){
      cout << "Highest donation total: " << maxTotalDonation << endl;
    cout << "-- collected by id: " << maxTotalCollector << endl;
}
  else if (don == false){
    cout << "No donations.";
  }
    
  }

