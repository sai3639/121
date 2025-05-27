#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {

    string pass;
    cout << "Please enter your text input: ";
    cin >> pass;
    cout << "input: " << pass << endl;

//     int a_index = pass.find("a");
//    // cout << index;
//    if(int e_index = pass.find("e") > 0){
//     cout << e_index;
//    }
//    else{
//     cout << a_index;
//    }
//   // int e_index = pass.find("e");
   //cout << e_index;

    //iterate through string 

    // for (int letter = 0; letter < pass.size(); ++letter){
    //     if (pass.at(letter) == "a"){
    //         pass.replace(letter, letter, "@");

    //     }
    // }
    int size = (pass.size()-1);
    int i = 0;
    while (i < size){
        if (pass.find("a") != std::string::npos){
            int a_index = pass.find("a");
            pass.at(a_index) = '@';
        }
        else if(pass.find("e") != std::string::npos){
            int e_index = pass.find("e");
            pass.at(e_index) = '3';
        }
        
        else if(pass.find("i") != std::string::npos){
            int i_index = pass.find("i");
            pass.at(i_index) = '!';
        }
        else if(pass.find("o") != std::string::npos){
            int o_index = pass.find("o");
            pass.at(o_index) = '0';
        }
        else if(pass.find("u") != std::string::npos){
            int u_index = pass.find("u");
            pass.at(u_index) = '^';
        }
        ++i;
  
     }

    string pass2 = pass;
    for (int i= 0; i < size; ++i){
        char temp = pass2[i];
        pass2[i] = pass2[size];
        pass2[size] = temp;
        --size;

    }
    pass = pass + pass2;

    cout << "output: " << pass;



    return 0;
}
