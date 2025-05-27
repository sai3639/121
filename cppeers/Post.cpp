/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream> 
#include "Post.h"
//std::stringstream;

using std::string;
using std::vector;

Post::Post(unsigned int postId, string userName, string postText)
  : postId(postId), userName(userName), postText(postText) {
  if (postId == 0 || userName == "" || postText == "") {
    throw std::invalid_argument("post constructor: invalid parameter values");
  }
}

unsigned int Post::getPostId() {
  return postId;
}

string Post::getPostUser() {
  return userName;
}

string Post::getPostText() {
  return postText;
}

vector<string> Post::findTags() {
  // TODO(student): extracts candidate tags based on occurrences of # in the post
  //make vector to store tags
  vector<string> tag;
  //word variable to store word
  string word;
  //make stringstream 
  std::istringstream s(postText);
  bool y;
  //read each word from postText
  while (s >> word){
  if(word.find('#') != std::string::npos){
    for(int i = word.length()-1; i >0; --i){
        //look for punctuation to remove at end of word
        if(word.at(i) == ',' || word.at(i) == '!' || word.at(i) == '.' || word.at(i) == '?'){
          //remove character from string 
          word.erase(i,1);
        }
        y = true;
      }
    tag.push_back(word);

    }
    if(y==true){
      tag.push_back(word);
    }
    //tag.push_back(word);
   // std::cout << word << std::endl;
    
  }
  y = false;

  //return vector with tags 
  return tag;



}
