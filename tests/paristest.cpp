
//timeArray[9] = {85, 65, 37, 61, 74, 93, 28, 97, 84};
#include <iostream>
#include <string>

using std::cout, std::cin, std::endl; 
using std::string;

double timeArray[9] = {85, 65, 37, 61, 74, 93, 28, 97, 84};
unsigned int rankArray[9];
int main(){


for (unsigned int i = 0; i < 9; ++i){
	rankArray[i] = timeArray[i];
}

for (unsigned int i = 0; i < 8; ++i){
		int t = 0;
		//cout << timeArray[i] << endl;
		for (unsigned int j = i+1; j < 9; ++j){
			if (rankArray[i] > rankArray[j]){
			//	max = timeArray[i];
				t = rankArray[i];
				rankArray[i] = rankArray[j];
				rankArray[j] = t;
				//cout << t << endl;
				//rankArray[i] = timeArray[i];
				//rankArray[j] = rankArray[i];
				//rankArray[i] = timeArray[j];
				//timeArray[i] = timeArray[j];
				//timeArray[j] = t;

				//rankArray[i] = rankArray[j];
				//rankArray[j] = t;
				

				//cout << rankArray[i] << endl;
				//cout << timeArray[i] << " " << timeArray[j] << endl;
		
			}
		}
		//cout << rankArray[i] << endl;
		//cout << timeArray[i] << endl;
		

	}
//for (unsigned int i = 0; i < 9; ++i){
//	rankArray[i] = timeArray[i];
//	cout << rankArray[i] << endl;
//}


  return 0; 

  }