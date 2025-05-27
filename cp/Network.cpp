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
#include<stdexcept>

using std::string;
using std::vector;

Network::Network() {
  // empty containers of vectors already created
  // no implementation is needed here
}

void Network::loadFromFile(string fileName) {
  // TODO(student): load user and post information from file
  std::ifstream file;
  file.open(fileName);
  if(file.fail()){
    throw std::invalid_argument("could not open file");
  }

  std::stringstream ss;
  std::vector<string> v;
  string line;
   while(!file.eof()){
      v.clear();
          ss.clear();
    string w;
    getline(file,w);
    //std::istringstream s1(w);

    // string user;
    // s1 >> user;
    // //std::cout << "us " << user << std::endl;
    // string u;
    // s1 >> u;
    // std::cout << "u " << u << std::endl;

    getline(file, line);

    if(line == "")
    {
      return;
    }
    ss<<line;
    string word = "";
   
        

       

          while (!ss.eof()) {
               ss >> word;
               v.push_back(word);
          }

          string operation = v.at(0);
          if (operation == "User") {
               try {
                    this->addUser(v.at(1));
               } catch (const std::exception& err) {
                    throw std::runtime_error(err.what());
               }
          } else if (operation == "Post") {
               size_t sz = v.size();
               if (sz < 4)
                    throw std::runtime_error("invalid post format");

               unsigned int id = 0;

               try {
                    id = (unsigned int)stoi(v.at(1));
               } catch (const std::exception& err) {
                    throw std::runtime_error(err.what());
               }

               string name = v.at(2);

               string post = "";

               for (size_t i = 3; i < sz; ++i)
                    post += v.at(i) + (i != sz - 1 ? " " : "");

               try {
                    this->addPost(id, name, post);
               } catch (const std::exception& err) {
                    throw std::runtime_error(err.what());
               }
          } else
               throw std::runtime_error("Unknown entry:\t" + line);
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
}

void Network::addPost(unsigned int postId, string userName, string postText) {
  // TODO(student): create post and add it to network
    //bool y = false;
  for(int i = 0; i < posts.size(); ++i){
    //std::cout << posts[i] << std::endl;
   // std::cout << "d " << posts[i]->getPostUser() << std::endl;
    if(posts[i] -> getPostId() == postId){
      throw std::invalid_argument("existing postId");
    }
    if((posts[i] -> getPostUser()) != userName){
      throw std::invalid_argument("user does not exist");
    }
 
    

  }
    
 
  
  // for(int i = 0; i < posts.size(); ++i){
  //   if(posts[i] -> findTags() ==  )
  // }

  //Post(postId, userName, postText);
  Post* newPost = new Post(postId, userName, postText);
  bool e = false;
  for(string tag_name : newPost->findTags())
  {
    e = false;
    for(Tag* tag : this->tags)
    {
      if(tag->getTagName() == tag_name)
      {
        tag->addTagPost(newPost);
        e = true;
        break;
      }
    }
      if(!e)
  {
    try{
      Tag* newTag = new Tag(tag_name);
      newTag->addTagPost(newPost);
      this->tags.push_back(newTag);
      
    }
    catch (const std::exception& err)
    {
      continue;
    }
  }
  }
 
  
this->posts.push_back(newPost);
  //posts.push_back(new Post(postId, userName, postText));
  std::cout << "Added Post " << postId << " by " << userName;


  

  
  //sspost = new Post(postId);
 // y = false;
}

vector<Post*> Network::getPostsByUser(string userName) {
if (userName.empty())
          throw std::invalid_argument("User name cannot be empty");

     for (User* user : this->users)
          if (user->getUserName() == userName)
               return user->getUserPosts();

     throw std::invalid_argument("User " + userName + " does not exist in the network.");
  // // TODO(student): return posts created by the given user
  // bool y =false;
  // if(userName == ""){
  //   throw std::invalid_argument("user name empty");
  // }
  // for(int i = 0; i < users.size(); ++i){
  //   //User -> users; 
  //  // users[i]->getUserName();
  //   if( users[i]->getUserName() == userName){
  //     y = true;
  //     return users[i] ->getUserPosts();
  //   }
  
  // }
  // if(y == false){
  //   throw std::invalid_argument("user not in vector");
  // }
  

}

vector<Post*> Network::getPostsWithTag(string tagName) {
  // TODO(student): return posts containing the given tag
  // for(int i = 0; i < posts.size(); ++i)
  // {
  //   if(tags[i]->getTagName()== tagName)
  //   {
  //     return tags[i]->getTagPosts();
  //   }
  //   if(tagName.size() == 0 || tagName == "")
  //   {
  //      throw std::invalid_argument("tag name is empty");
  //   }
  // }
     if (tagName.empty())
          throw std::invalid_argument("Tag name cannot be empty");

     for (Tag* tag : this->tags)
          if (tag->getTagName() == tagName)
               return tag->getTagPosts();

     throw std::invalid_argument("Tag " + tagName + " does not exist in the network");

}

vector<string> Network::getMostPopularHashtag() {
  // TODO(student): return the tag occurring in most posts
  unsigned int max = 0;
  for(Tag* tag : this->tags)
  {
    
    unsigned int a = tag->getTagPosts().size();
    if(a > max)
    {
      max = a;
    }
  }
  vector<string> t = vector<string>();
  for(Tag* tag : this->tags)
  {
    if(tag->getTagPosts().size() == max)
    {
      t.push_back(tag->getTagName());
    }
  }
  return t;
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
