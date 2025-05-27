#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {
    //variables & entering 
    string sent; 
    string word; 
    cout << "Please enter the sentence: ";
    getline(cin, sent);
    cout << "Please enter the filter word: ";
    getline(cin, word);
    

    // find word in sentence 
    //sent.find(word);
    //sent.replace();

    // substr - start at index find returns and keep iterating through 
    // sentence 
    int size = (sent.size()-1);
    int word_size = (word.size());
    int letter = 0; 
    //int let = 0;
    while (letter != size){
        if(sent.find(word) != std::string::npos ){
            int word_index = sent.find(word);
            for (int i = word_index; i < (word_size + word_index); ++i){
                sent.replace(i, 1, "#");
            }
           
    
            
        }
        
        ++letter;
    }

    cout << "Filtered sentence: " << sent; 





    return 0;
}
