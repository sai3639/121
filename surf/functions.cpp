#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

Pixel** createImage(int width, int height) {
  cout << "Start createImage... " << endl;
  
  // Create a one dimensional array on the heap of pointers to Pixels 
  //    that has width elements (i.e. the number of columns)
  Pixel** image = new Pixel*[width];
  
  bool fail = false;
  
  for (int i=0; i < width; ++i) { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    image[i] = new Pixel[height];
    
    if (image[i] == nullptr) { // failed to allocate
      fail = true;
    }
  }
  
  if (fail) { // if any allocation fails, clean up and avoid memory leak
    // deallocate any arrays created in for loop
    for (int i=0; i < width; ++i) {
      delete [] image[i]; // deleting nullptr is not a problem
    }
    delete [] image; // delete array of pointers
    return nullptr;
  }
  
  // initialize cells
  //cout << "Initializing cells..." << endl;
  for (int row=0; row<height; ++row) {
    for (int col=0; col<width; ++col) {
      //cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = { 0, 0, 0 };
    }
  }
  cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel** image, int width) {
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i=0; i<width; ++i) {
    delete [] image[i]; // delete each individual array placed on the heap
  }
  delete [] image;
  image = nullptr;
}

// implement for part 1

int* createSeam(int length) {
  //create array and intialize it to 0

  int* seam = new int[length];
  for (int i = 0; i < length; ++i){
    seam[i] = {};
  }

  


  return nullptr;
}

void deleteSeam(int* seam) {
  delete[] seam;
}

bool loadImage(string filename, Pixel** image, int width, int height) {
  ifstream file;
  //fstream filename
  //open file
  file.open(filename);

  //error checking!!!!!
  if(file.fail()){
    cout << "Error: failed to open input file - " << filename;
    return false;
  }

  //store type (first line of file)
  string type;
  getline(file, type);
  
  if(type!="P3"){
    cout << "Error: type is " << type << " instead of P3";
    return false;
  }
  //store size of file 
  string size;
  getline(file,size);

 
    //change into integers to compare with parameters given 

  string first = size.substr(0, size.find(" "));
  string sec = size.substr(size.find(" "), size.length());
    
  int int_width;
  int int_height;
  //int area = (int_width * int_height) *3;


  stringstream width1(first);
  stringstream height1(sec);

  width1 >> int_width;
  if(file.fail()){
    cout << "Error: value is non-integer value";
    return false;
  }
  height1 >> int_height;
  if(file.fail()){
    cout << "Error: value is non-integer value";
    return false;
  }
    

  if(width!=int_width){
    cout << "Error: input width (" << width << ") does not match value in file (" <<int_width << ")";
    return false;
  }

  if(height!=int_height){
    cout << "Error: input height (" << height << ") does not match value in file (" << int_height << ")";
    return false;
  }
  


     //store max
    string max;
    getline(file,max);
    int imax;

    stringstream m(max);

    m >> imax;
    if(file.fail()){
      cout << "Error: value is non-integer value";
      return false;
    }
    if(imax > 255){
      cout << "Error";
      return false;
    }
    
   
    //istringstream iss;
    int r1;
    int g1;
    int b1;

    

  
  int count = 0;
  while(!file.eof()){

   
  
   
    for(int i = 0; i < height; ++i){
      for(int j = 0; j < width; ++j){
          file >> r1;
          if(file.fail() && !file.eof()){
            cout << "Error: value is non-integer value";
            return false;
          }
          if(file.fail() && file.eof()){
            cout << "Error: too many color values";
            return false;
          }
          else{
            count = count + 1;
          }
          
     
         
        
           file >> g1;
          if(file.fail() && !file.eof()){
            cout << "Error: value is non-integer value";
            return false;
          }
            else{
            count = count + 1;
          }
          
    
          file >> b1;
          if(file.fail() && !file.eof()){
            cout << "Error: value is non-integer value";
            return false;
          }
       
            else{
            count = count + 1;
          }
         
          
          image[j][i].r = r1;
          
          if(image[j][i].r < 0 || image[j][i].r > 255){
            cout << "Error: invalid color value " << image[j][i].r;
            return false;
          }
          
          image[j][i].g = g1;
          
          if(image[j][i].g < 0 || image[j][i].g > 255){
            cout << "Error: invalid color value " << image[j][i].g;
            return false;
          }
          image[j][i].b = b1;
          
          if(image[j][i].b < 0 || image[j][i].b > 255){
            cout << "Error: invalid color value " << image[j][i].b;
            return false;
          }
          
         
          

          //count = count + 1;
      }
       
 

    }
    // if(count < area && file.eof()){
    //         cout << "Error: not enough color values";
    //         return false;
    //       }
    // else if (count > area){
    //   cout << "Error: too many color values";
    //   return false;
    // }
     
      // if(!file.eof() && count > area){
      //   cout << "Error: too many color values";
      //   return false;
      // }
      // if(file.eof() && count < area){
      //   cout << "Error: not enough color values";
      //   return false;
      // }
    

    
  

    // count = count + 3;
    // if(count > area && !file.eof()){
    //   cout << "Error: too many color values";
    //   return false;
    // }
    // if (count < area && file.eof()){
    //   cout << "Error: not enough color values";
    //   return false;
    // }

    // if(file.fail() && file.eof()){
    //   cout << "Error: whitespace";
    //   return false;
    // }

  
    
  
  }
 
 
 


  // if(file.eof()){
  //   return false;
  // }
 
  //close file
  file.close();



  return true;
}

bool outputImage(string filename, const Pixel*const* image, int width, int height) {
  ofstream outFS;
  outFS.open(filename);

  if(!outFS.is_open()){
    cout << "Error: failed to open output file - <filename>";
    return false;
  }


  //write header
  outFS << "P3" << endl;
  outFS << width << " " << height << endl;
  outFS << "255" << endl;

        for(int i = 0; i < height; ++i){
          for(int j = 0; j < width; ++ j){
             outFS << image[j][i].r;
             outFS << image[j][i].g;
             outFS << image[j][i].b;
          }
          cout << endl;
        }
       
       


  outFS.close();

  return true;
}

int energy(const Pixel*const* image, int x, int y, int width, int height) { 
  //image[x][y].r
  //border cases - if x = 0 or x = width
  int redx;
  int greenx;
  int bluex;
  int redy;
  int greeny;
  int bluey;
  int energyx;
  int energyy;
  int energy;


  if(x==0){
    if(y==0){
    redx = image[x+1][y].r - image[width-1][y].r;
    greenx = image[x+1][y].g - image[width-1][y].g;
    bluex = image[x+1][y].b - image[width-1][y].b;
    energyx = pow(redx,2) + pow(greenx, 2) + pow(bluex, 2);

    redy = image[x][y+1].r - image[x][height-1].r;
    greeny = image[x][y+1].g - image[x][height-1].g;
    bluey = image[x][y+1].b - image[x][height-1].b;
    energyy = pow(redy, 2) + pow(greeny, 2) + pow(bluey, 2);
    energy = energyx + energyy;
    }
    else if(y==height-1){
      redx = image[x+1][y].r - image[width-1][y].r;
      greenx = image[x+1][y].g - image[width-1][y].g;
      bluex = image[x+1][y].b - image[width-1][y].b;
      energyx = pow(redx,2) + pow(greenx, 2) + pow(bluex, 2);

      redy = image[x][0].r - image[x][y-1].r;
      greeny = image[x][0].g - image[x][y-1].g;
      bluey = image[x][0].b - image[x][y-1].b;
      energyy = pow(redy, 2) + pow(greeny, 2) + pow(bluey, 2);
      energy = energyx + energyy;
    }
    else{
      redx = image[x+1][y].r - image[width-1][y].r;
      greenx = image[x+1][y].g - image[width-1][y].g;
      bluex = image[x+1][y].b - image[width-1][y].b;
      energyx = pow(redx,2) + pow(greenx, 2) + pow(bluex, 2);

      redy= image[x][y+1].r - image[x][y-1].r;
      greeny= image[x][y+1].g - image[x][y-1].g;
      bluey= image[x][y+1].b - image[x][y-1].b;
      energyy = pow(redy, 2) + pow(greeny, 2) + pow(bluey, 2);
      energy = energyx + energyy;
    }
  }


  else if(x==width-1){
    if(y==0){
      redx = image[0][y].r - image[x-1][y].r;
      greenx = image[0][y].g - image[x-1][y].g;
      bluex = image[0][y].b - image[x-1][y].b;
      energyx = pow(redx,2) + pow(greenx, 2) + pow(bluex, 2);

      redy= image[x][y+1].r - image[x][height-1].r;
      greeny= image[x][y+1].g - image[x][height-1].g;
      bluey= image[x][y+1].b - image[x][height-1].b;
      energyy = pow(redy, 2) + pow(greeny, 2) + pow(bluey, 2);
      energy = energyx + energyy;
    }
    else if(y==height-1){
      redx = image[0][y].r - image[x-1][y].r;
      greenx = image[0][y].g - image[x-1][y].g;
      bluex = image[0][y].b - image[x-1][y].b;
      energyx = pow(redx,2) + pow(greenx, 2) + pow(bluex, 2);

      redy = image[x][0].r - image[x][y-1].r;
      greeny = image[x][0].g - image[x][y-1].g;
      bluey = image[x][0].b - image[x][y-1].b;
      energyy = pow(redy, 2) + pow(greeny, 2) + pow(bluey, 2);
      energy = energyx + energyy;
    
    }
    else{
        redx = image[0][y].r - image[x-1][y].r;
    greenx = image[0][y].g - image[x-1][y].g;
    bluex = image[0][y].b - image[x-1][y].b;
    energyx = pow(redx,2) + pow(greenx, 2) + pow(bluex, 2);

    redy= image[x][y+1].r - image[x][y-1].r;
    greeny= image[x][y+1].g - image[x][y-1].g;
    bluey= image[x][y+1].b - image[x][y-1].b;
    energyy = pow(redy, 2) + pow(greeny, 2) + pow(bluey, 2);
    energy = energyx + energyy;
    }
  }

  else if(y==height-1){
 
    if((x!=0) && x!=width-1){
       redx = image[x+1][y].r - image[x-1][y].r;
      greenx = image[x+1][y].g - image[x-1][y].g;
      bluex = image[x+1][y].b - image[x-1][y].b;
      energyx = pow(redx,2) + pow(greenx, 2) + pow(bluex, 2);

      redy = image[x][0].r - image[x][y-1].r;
      greeny = image[x][0].g - image[x][y-1].g;
      bluey = image[x][0].b - image[x][y-1].b;
      energyy = pow(redy, 2) + pow(greeny, 2) + pow(bluey, 2);
      energy = energyx + energyy;

    }

  }

  else if(y==0){
    if(x!=0 && x!=width-1){
      redx = image[x+1][y].r - image[x-1][y].r;
    greenx = image[x+1][y].g - image[x-1][y].g;
    bluex = image[x+1][y].b - image[x-1][y].b;
    energyx = pow(redx,2) + pow(greenx, 2) + pow(bluex, 2);

    redy= image[x][y+1].r - image[x][height-1].r;
    greeny= image[x][y+1].g - image[x][height-1].g;
    bluey= image[x][y+1].b - image[x][height-1].b;
    energyy = pow(redy, 2) + pow(greeny, 2) + pow(bluey, 2);
    energy = energyx + energyy;
    }
  }


  else{
      
      redx = image[x-1][y].r - image[x+1][y].r;
      greenx = image[x-1][y].g - image[x+1][y].g;
      bluex = image[x-1][y].b - image[x+1][y].b;
      energyx = pow(redx,2) + pow(greenx, 2) + pow(bluex, 2);

      redy = image[x][y-1].r - image[x][y+1].r;
      greeny = image[x][y-1].g - image[x][y+1].g;
      bluey = image[x][y-1].b - image[x][y+1].b;
      energyy = pow(redy, 2) + pow(greeny, 2) + pow(bluey, 2);

      energy = energyx + energyy;
  }


  if(width < 3 && height < 3){
    energy = 0;
  }
  if(width < 3 && height >= 3){
    energyx = 0;
    energy = energyy;

  }
  if (width >= 3 && height < 3){
    energy = energyx;
  }
  


  return energy;
}

// implement for part 2

// uncomment for part 2


int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam) {
  //start col = start_col
  //inital energy = energy of start_col
  //traverse the array in vertical seam mode
  //calculate energy of vertical seams
  //find minimal energy ???

  //start at start col, row 0 - (col, row)
  //nesting for loop (width, height?) - col , row?
  //for(i = start_col; i < width; ++i);

   //options to go - row must increase by 1 each time but col has options
   //increase col by 1, decrease by 1, keep the same

   //nesting for loop - how to implement col - can;t increase by 'i'
   
   //traverse the rows of the array - they increment 
   //for(int i = 0; i < height; ++i)
    
  //put start_col into array seam 
  seam[0] = start_col; 
  //initialize total energy 
  int tot_energy = energy(image, start_col, 0, width, height);

  //initialize variables
  int backwards = 0 ;
  int same  = 0 ;
  int forward = 0 ;
  int sj;
  int fj;
  int bkj;


  //traverse image to find column values need to put into seam array
  //nested for loop 
  //start row below start_col row
  if(width != 1){
   for(int i = 1; i < height; ++i){
    //go through columns in that specific row 
    for(int j = 0; j < width; ++j){
      //adjacent columns to start_col
      //same
      //if j is the same column number as the last column 
      // if(width == 1){
      //   same = energy(image, j, i, width, height);
      //   sj = j;
      //   forward = same;
      //   fj = sj;
      //   backwards = same;
      //   bkj = j;
      // }
      //else{
        if(start_col == (width-1)){
          if(j==start_col){
          //check energy bkof pixel
          same = energy(image, j, i, width, height);
          //save the column # 
          sj = j;
          }
          if(j==(start_col-1)){
          
          backwards = energy(image, j, i, width, height);
          bkj = j;
        }
        fj = sj;
        forward = same;
        }
        if(start_col == 0){
            if(j==start_col){
          //check energy bkof pixel
          same = energy(image, j, i, width, height);
          //save the column # 
          sj = j;
          }
            if(j==(start_col+1) ){
          forward = energy(image, j, i, width, height);
          fj = j;

        }
        bkj = sj;
        backwards = same;

        }
        else{
          if(j==start_col){
            //check energy bkof pixel
            same = energy(image, j, i, width, height);
            //save the column # 
            sj = j;
            //cout << "same " << same << endl;
            //cout << "sj " << sj << endl;

          }
          //forward 
          //when j is the column after previous column
          if(j==(start_col+1) ){
            forward = energy(image, j, i, width, height);
            fj = j;
          }

          //backwards
          //when j is the column before previous column 
          if(j==(start_col-1)){
            
            backwards = energy(image, j, i, width, height);
            bkj = j;
          }
        //}
    }
    }
    //check minimum energy 
    if(same < forward && same < backwards){
      //same is minimum energy
      //j becomes start_col (width) 
      start_col = sj;
      //save column value to array seam
      seam[i] = sj;
      //add minimum energy to total energy 
      tot_energy = tot_energy + same;
    }

    else if(forward < same && forward < backwards){
      start_col = fj;
      seam[i] = fj;
      tot_energy = tot_energy + forward;

    }

    else if(backwards < same && backwards < forward){
      start_col = bkj;
      seam[i] = bkj; 
      tot_energy = tot_energy + backwards; 

    }
    //check if values have the same minimum energy and take the one with 
    //lowest j value 

    //all equal
    else if(same == backwards && same == forward){
      start_col = sj;
      seam[i] = sj;
      tot_energy = tot_energy + same;

    }



    //forward and left tie
    else if(same == forward && same < backwards){
      start_col = sj;
      seam[i] = sj;
      tot_energy = tot_energy + same;
    }
    //foward and right tie
    else if(same == backwards && same < forward){
      start_col = sj;
      seam[i] = sj;
      tot_energy = tot_energy + same;
    }

    //left and right tie
    else if(forward == backwards && forward < same){
      start_col = fj;
      seam[i] = fj;
      tot_energy = tot_energy + forward;
    }



   // if(forward == backward && forward <)
   

    //don't need nested for loop
  //just need to iterate through rows (height)

  // //start col
  // seam[0] = start_col;

  // //initialize total energy
  // int tot_energy = energy(image, start_col, 0, width, height);


  // //initialize variables
  // int backwards =0;
  // int same = 0;
  // int forward = 0;



  // //traverse image to find column values needed to put in seam array
  // //go through rows (height) of image
  // for(int i = 1; i < height; ++i){
  //     //check columns next to the column selected as well as the column selected
  //     same = energy(image, start_col, i, width, height);

  //     forward = energy(image, (start_col + 1), i, width, height);

  //     backwards = energy(image, (start_col - 1), i, width, height);


  //     if(same < forward && same < backwards){
  //     tot_energy = tot_energy + same;
  //     start_col = start_col;
  //     seam[i] = start_col;
  // }

  // else if(forward < same && forward < backwards){
  //     tot_energy = tot_energy + forward;
  //     start_col = start_col + 1;
  //     seam[i] = (start_col + 1);
  // }

  // else if (backwards < forward && backwards < same){
  //     tot_energy = tot_energy + backwards;
  //     start_col = (start_col -1);
  //     seam[i]  = (start_col -1);
  // }

  // else if (forward== same && forward == backwards){
  //     tot_energy = tot_energy + forward;
  //     start_col = (start_col + 1);
  //     seam[i] = (start_col + 1);
  // }


   }
  }
  if(width ==1 && height == 1){
    tot_energy = tot_energy;
  }
  

  
   //cout << tot_energy << endl;
    cout << seam[1] << endl;







  
   

  return tot_energy;
}

// int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam) {
//   return 0;
// }

int* findMinVerticalSeam(Pixel** image, int width, int height) {

  //if seam has a lower energy than current 
  //delete minseam and set minseam to current seam
  //update energy 


  //create seam by calling createSeam function

  //call loadVerticalSeam for # width - returns total energy value
  //want to find the minimum of these values 


  //where does image come in place?????? 
  //image contains pixel values? - used in loadVerticalSeam 
  //need in minverticalseam?
  
  //create seam
  //want to iterate through rows not columns "width" - horizontal seam
  int* seam = createSeam(height);
  int* min_seam = createSeam(height);
  int min_energy = loadVerticalSeam(image, 0, width, height, min_seam);
 
  //"result energy"
  int r_energy;
  for(int i = 1; i < width; ++i){
    r_energy = loadVerticalSeam(image, 0, width, height, seam);
    if(r_energy < min_energy){
      min_energy = r_energy;
      min_seam = seam;    
      
      //set pointer to seam?
      //seam = seam??????
      //save vertical seam as seam containing min energy - ask about???
      //how to return pointer?? - have to go through full width to find 
      // minimum energy - so how does it know what vertical seam it was?
      //i takes into account iteration of going through vertical seams
      //but how does i relate to pointer?? 


    }
  }
  


  //delete seam not being used from heap 
  deleteSeam(seam);

  //populates the seam with minimum energy values for # of columns
  //find minimum energy value from recently populated seam array
  // int min_energy = seam[0];
  // for(int i = 1; i < width; ++i){
  //   if(seam[i] < min_energy){
  //     min_energy = seam[i];
  //   }
  // }




  return min_seam;
}

// int* findMinHorizontalSeam(Pixel** image, int width, int height) {
//   return nullptr;
// }

void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) {
  for(int i = 0; i < height; ++i){
    for(int j = verticalSeam[i] +1; j < width; ++j){
     image[j-1][i] = image[j][i];
    }
  }
  
  
  
  
  
  
  
  
  
  //shift columns 
  //initialize column value with column + 1


  //call function findMinVerticalSeam
  //this returns the minseam that needs to be removed 
  //verticalSeam = findMinVerticalSeam(image, width, height);

  
  //iterate throw each row 
  //then iterate throw each column 

  //nested for loop 

  // for(int i = 0; i < height; ++i){
  //   for(int j = 0; j < width; ++j){
  //     //seam 
  //   }
  // }

  //go through array and starting at seam[i] start shifting columns 

  //2D array image[j][i] vs 1D array seam[i]

  //seam[i] gives which column 
  //seam[i] = j
 
  // //go through rows 
  // for(int i = 0; i < height; ++i){
  //   //go through columns 
  //   for(int j = width; j <= verticalSeam[i]; --j){
  //     image[j-1][i].r = image[j][i].r;
  //     image[j-1][i].g = image[j][i].g;
  //     image[j-1][i].b = image[j][i].b;


  //     //find the right column in the row
  //     //if(j == verticalSeam[i]){
  //       //at this point image[j][i] - vertical min seam value
  //       //values get shifted left 
  //       //another for loop
  //       //start at vertical min seam 
  //       //shift left
  //         // for(int k = j; k <= width; ++k){
  //         //   image[j][i] = image[j+1][i];
            
  //         // }
          
  //       //}
  //         //image[j][i] = image[j+1][i];

  //      // }
  //       // k < width-j
  //       //shift values before minseam
  //       // for(int k= 0; k < width-j; ++k){
  //       //   //shift values over to the left starting at minseam value
  //       //   image[j][i] = image[j+1][i];

  //       // }
  //       // //shift values after minseam
  //       // for(int a = j; a < width; ++a){

  //       // }
  //     //}
      
      
  //   }


  //}




  //know the row value by the index of seam "i"
  //know the column value by the value at that index "seam[i]"


  //value in column of array to the right equals the value of the column
  //being removed due to the vertical seam 
  //array[i] = array[i+1]


  //width gets smaller 
  //width = width - 1;



}


// // void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam) {
// // }
