#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include "Pixel.h"

class Image {
  Pixel** image;
  unsigned int width; // columns
  unsigned int height; // rows
  std::string filename;
  

public:
//constructor
  Image();
  //constructor with parameters? 
  Image(std::string filename);
  Image(unsigned int width, unsigned int height);


  ~Image();
  Image(const Image& objToCopy);
  //copy constructor
  Image& operator=(const Image& objToCopy);
  //destructor
 



  
  Pixel*& operator[](unsigned int column);
  const Pixel* operator[](unsigned int column) const;
  unsigned int getWidth();
  unsigned int getHeight();
  
  void makeGreyscale();
  void makeSepia();
  void addColor(Pixel p);
  
  void output(std::string filename);
  
private:
  void load(std::string filename);
  void allocateImage(unsigned int width, unsigned int height);
  void clear();
};

#endif