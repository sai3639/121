/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <string>
#include <stdexcept>
#include "User.h"

using std::string;
using std::vector;

User::User(string userName) : userName(userName) {
  // TODO(student): implement constructor checks
  //check if userName is empty and if it doesn't start with letter
  if(userName == "" || isalpha(userName.at(0)) == 0)
  {
    //throw 
    throw std:: invalid_argument("userName is empty or doesn't start with a letter");

  }
  //check if userName contains any uppercase letters
    //use for loop and isupper?
      //isupper returns 0 if lowercase
  for(int i = 0; i < userName.size(); ++i){
    if(isupper(userName.at(i)) != 0){
      throw std:: invalid_argument("userName contains uppercase letter");
    }
  }

}

string User::getUserName() {
  // TODO(student): implement getter
  //gets username from post? 
  //aggregation - class user accesses/owns class post?? 
  return userName; 

}




vector<Post*>& User::getUserPosts() {
  // TODO(student): implement getter
  //returs a vector of all the posts the user has made
  return userPosts;
}

void User::addUserPost(Post* post) {
  // TODO(student): add post to user posts
  userPosts.push_back(post);
  if(post == nullptr){
    throw std:: invalid_argument("nullptr");
    
  }

  

}
