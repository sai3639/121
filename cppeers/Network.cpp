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
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Network.h"

using std::string;
using std::vector;

Network::Network() {
  // empty containers of vectors already created
  // no implementation is needed here
}

void Network::loadFromFile(string fileName) {
  // TODO(student): load user and post information from file
  //cppeers.getPostsByUser(userName);
  std::ifstream file;
  file.open(fileName);
  if(file.fail()){
    throw std::invalid_argument("could not open file");
  }

  while(!file.eof()){
    string w;
    getline(file,w);

    if(w.substr(0, w.find(" ")) == "User"){
      //std:: cout << w << std:: endl
      addUser(w.substr(w.find(" "), w.find(" ")));
    }
    if(w.substr(4, w.length()) == " "){
      throw std::invalid_argument("no user");
    }
    if(!isalpha(w[6])){
      throw std::invalid_argument("userName doesnt start with a letter");

    }
    else if(w.substr(0, w.find(" ")) == "Post"){
      //addPost();
    }
    else{
      throw std::invalid_argument("invalid file");
    }
    
    try{
      addUser(w);
      
      // if(!isalpha(w[6]) || w.substr(4, w.length()) == " "){
      //   //addUser(w.substr(4, w.find(" ")));
      // }
     
    }
    catch(string w){
      //throw std::invalid_argument("userName is empty or doesn't start with a letter");

    }

  }
  }

 

void Network::addUser(string userName) {
  // TODO(student): create user and add it to network
  for(int i = 0; i < userName.size(); ++i){
    tolower(userName.at(i));
  } 
  for(int i = 0; i < users.size(); ++i){
    //User -> users; 
   // users[i]->getUserName();
    if( users[i]->getUserName() == userName){
      throw std::invalid_argument("user already exists");

    }

  }
 
  users.push_back(new User(userName));
  std::cout << "Added User " << userName;

  // try{
  //   users.push_back(new User(userName));
  // }
  // catch(){
  //   throw std::invalid_argument("already exists");

  // }

 // users.push_back(new User(userName));
  
  //users.push_back(userName)

}

void Network::addPost(unsigned int postId, string userName, string postText) {
  // TODO(student): create post and add it to network
  // Post p;
  // p.getPostId();

  // Post * post = new Post();
  // post ->getPostId();
  //posts[0] -> getPostId();
  bool y = false;
  for(int i = 0; i < posts.size(); ++i){
    //std::cout << posts[i] << std::endl;
    if(posts[i] -> getPostId() == postId){
      throw std::invalid_argument("existing postId");
    }
    if((posts[i] -> getPostUser()) == userName){
      y = true;
    }

  }
  if(y == false){
    throw std::invalid_argument("user name doesn't exist");
  }
  // for(int i = 0; i < posts.size(); ++i){
  //   if(posts[i] -> findTags() ==  )
  // }

  //Post(postId, userName, postText);
  posts.push_back(new Post(postId, userName, postText));
  std::cout << "Added post " << postId << " by " << userName;


  

  
  //sspost = new Post(postId);
  y = false;

  

  



}

vector<Post*> Network::getPostsByUser(string userName) {
  // TODO(student): return posts created by the given user
  bool y =false;
  if(userName == ""){
    throw std::invalid_argument("user name empty");
  }
  for(int i = 0; i < users.size(); ++i){
    //User -> users; 
   // users[i]->getUserName();
    if( users[i]->getUserName() == userName){
      y = true;
      return users[i] ->getUserPosts();
    }
  
  }
  if(y == false){
    throw std::invalid_argument("user not in vector");
  }
  



}

vector<Post*> Network::getPostsWithTag(string tagName) {
  // TODO(student): return posts containing the given tag
  if(tagName == ""){
    throw std::invalid_argument("tag name is empty");
  }




}

vector<string> Network::getMostPopularHashtag() {
  // TODO(student): return the tag occurring in most posts
  vector<string> tags1;
  string tagName;
  int size = 0;
  for(int i = 0; i < tags.size(); ++i){
    //tags[i] -> getTagPosts();
    if(size < tags.at(i) -> getTagPosts().size()){
      //size = tags.at(i+1) ->getTagPosts().size();
      size = tags.at(i) -> getTagPosts().size();
      tagName = tags.at(i) -> getTagName();


    }
  }
  // for(int i = 0; i < tags.size(); ++i){
  //   if(tags.at(i) -> getTagPosts().size() == size){
  //      tags1.push_back((tagName));


  //   }
 // }
  tags1.push_back(tagName);

  return tags1;
}



/**
  * Destructor
  * Do not change; already implemented.
  */
Network::~Network() {
  for (unsigned int i = 0; i < users.size(); ++i) {
    delete users.at(i);
  }
  for (unsigned int i = 0; i < tags.size(); ++i) {
    delete tags.at(i);
  }
  for (unsigned int i = 0; i < posts.size(); ++i) {
    delete posts.at(i);
  }
}
