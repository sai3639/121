#include <iostream>
#include "cstring.h"



unsigned int length(char str[]) {
  // returns the length of the string including zero (0)
  int count = 0;
  for (int i = 0; str[i] != '\0'; ++i){
    count+= 1;
  }
  return count;
}

unsigned int find(char str[], char character) {
  // returns 
  //  - the index of the first occurence of character in str
  //  - the size if the character is not found

  //find length of string by calling function length  
  //length(str[]);

  //loop through string to find character - for loop 
  int index = 0;
  //int count = 0;
  for (int chr = 0; str[chr] != '\0'; ++chr){
    //find index number where character is if exists 
    if (str[chr]==character){
      index = chr;
      break;
    }
    //else index = how long the string is 
    else{
      index += 1;
    }
  }


  return index;
}

bool equalStr(char str1[], char str2[]) {
  // returns true if they are equal and false if they are not
  bool bol;
  for (int i = 0, j = 0; str1[i] != '\0' && str2[j] != '\0'; ++i, ++j){
    if (str1[i] == str2[j]){
      bol = true;
    }
    else if (str1[i] != str2[j]) {
      bol = false;
      break;
    }
    


  }
  return bol;
}