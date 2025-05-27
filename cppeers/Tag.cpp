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
#include "Tag.h"

using std::string;
using std::vector;

Tag::Tag(string tagName) : tagName(tagName) {
  // TODO(student): implement constructor checks
  if(tagName.length() < 2){
    throw std::invalid_argument("tag name size is too small");
  }

  if(tagName.at(0) != '#'){
    throw std::invalid_argument("first character is not #");
  }

  if(!isalpha(tagName.at(1))){
    throw std::invalid_argument("second character is not a letter");
  }

  for(int i = 0; i < tagName.size(); ++i){
    if(isupper(tagName.at(i))){
      throw std:: invalid_argument("userName contains uppercase letter");
    }
  }

  //  if(tagName.at(-1) == ',' || tagName.at(-1) == '!' || tagName.at(-1) == '.' || tagName.at(-1) == '?'){
  //     throw std:: invalid_argument("punctuation at end of string");
  //  }
  for(int i = tagName.length()-1; i >0; --i){
    if(tagName.at(i) == ',' || tagName.at(i) == '!' || tagName.at(i) == '.' || tagName.at(i) == '?'){
          //remove character from string 
          throw std::invalid_argument("punctuation at the end");
        }
  }




}

string Tag::getTagName() {
  // TODO(student): implement getter
  return tagName;
}

vector<Post*>& Tag::getTagPosts() {
  // TODO(student): implement getter
  //returns a vector with the posts that contain hashtag?
  return tagPosts;

}

void Tag::addTagPost(Post* post){
  // TODO(student): add post to tag posts
  // adds post to tag posts - use vector 
  //add the whole post to the tagpost vector
  //methods are like functions inside of classes 
   if(post == nullptr){
    throw std:: invalid_argument("nullptr");
    
  }
  else{
    tagPosts.push_back(post);
  }

  

}
