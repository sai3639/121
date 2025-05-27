# include <iostream>
# include <string>
 
// scene struct
struct SnowGlobe {
    std::string scene = "";
    std::string size = "";
};
 
// outputs scene titles
void outputScenes(SnowGlobe**& snowglobes, unsigned int& shelves) {
    std::cout << "Shelf:\n";
 
    for (unsigned int shelf = 0; shelf < shelves; shelf++) {
        for (unsigned int snowglobe = 0; snowglobe < 5; snowglobe++) {
            std::cout << snowglobes[shelf][snowglobe].scene<< " ";
        }
        std::cout << '\n';
    }
 
    std::cout << '\n';
}
 
// adds shelf
void addShelf(SnowGlobe**& snowglobes, unsigned int& shelves) {
    // TODO: add shelf for 5 snowglobes
    snowglobes = new SnowGlobe*[shelves];
    for(unsigned int i = 0; i < shelves; ++i)
    {
        snowglobes[i] = new SnowGlobe[5];

    }
}
 
// adds SnowGlobe
void addSnowGlobe(SnowGlobe**& snowglobes, unsigned int& shelves, std::string _Scene, std::string _Size) {
    // TODO: add snowglobe to shelf
    //each snowglobe contains a scene and size

    //snowglobes - 2d array
    //shelf is 2d array made up of 5 snowglobes 

    //make sure shelf is not full - iterate through 2d array 
    // array made up of shelves and snowglobes 

    //shelf = 2d array made up of a scene and size?
    //shelves = reference 
    //snowglobes = reference

    //[shelf 1][snowglobe 1] = scene and size?
    //if(snowglobes[shelves])

    //iterate through shelves
    for(int i = 0; i < shelves; ++i)
    {
        //check how many snowglobes in 1 shelf 
        //snowglobes.at(i).size??
        if(snowglobes[i].size < 5)
        {
            //if less than 5 add snowglobe to next position
        }
        if(sizeof)
    }




    //add snowglobe 
    snowglobes[shelves][i]{_Scene, _Size};

   // std::vector<int> snowglobes;

  ///  int cols = sizeof(snowglobes[0]/sizeof(snowglobes[0][0]))


ifile >> row >> col;
  //check how many snowglobes are in one shelf
  int count = 0;
  for(int i = 0; i < shelves; ++i)
  {
    for(int j = 0; j < 5; ++j)
    {
        //check if empty at position 
        if(!snowglobes[i][j])
        {
            break;
        }
        else
        {
            //count counts up till there is no scene or string in shelf
            //till shelf is empty
            //finds where to insert next snowglobe 
            count++;
        }
    //if count is equal to 5 - shelf full
    //add new shelf
        if(count == 5)
        {
            addShelf(snowglobes, shelves);
        }
    }

    for(int i = 0; i < shelves; ++i)
    {
        for(int j = 0; j < count; ++j)
        {
            snowglobes[i][j] = {_Scene, _Size};

        }
    }
  }


}
 
int main() {
    std::string Scene;
    std::string Size;
 
    SnowGlobe** snowglobes = nullptr;
    unsigned int shelves = 0;
 
    while (true) {
        std::cout << "Enter name of snowglobe (q to exit): ";
        std::cin >> Scene;
 
        if (Scene == "q") {
            break;
        }
 
        std::cout << "Enter the size: ";
 
        Size = "";
        std::cin >> Size;
 
        addSnowGlobe(snowglobes, shelves, Scene, Size);
 
        outputScenes(snowglobes, shelves);
    }
 
    // deallocate dynamic memory
    if (snowglobes != nullptr) {
        for (unsigned int shelf = 0; shelf < shelves; shelf++) {
            delete[] snowglobes[shelf];
        }
 
        delete[] snowglobes;
    }
}