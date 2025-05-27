#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"

using std::cout, std::endl, std::ifstream, std::string;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) {
    ifstream file(fileName);

    maxRow = 0;
    maxCol = 0;
    player.row = 0;
    player.col = 0;

    file >> maxRow;
    file >> maxCol;
    file >> player.row;
    file >> player.col;

    char symb;
   
    char** map = createMap(maxRow, maxCol);

    for(int i = 0; i < maxRow; ++i){
        for(int j = 0; j < maxCol; ++j){
            file >> symb;
            map[i][j] = symb;
            

        }
    }

    map[player.row][player.col] = 'o';
    




    return map;
}

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int& nextRow, int& nextCol) {
        //moveup
    if(input == 'w'){
        //row decreases by 1 
        nextRow = nextRow - 1;
    }
    //moveleft
    else if (input == 'a'){
        //column decreases by 1
        nextCol = nextCol - 1;
    }
    //movedown
    else if (input == 's'){
        //row increases by 1
        nextRow = nextRow + 1;
    }
    //moveright
    else if (input == 'd'){
        //column increases by 1
        nextCol = nextCol + 1;
    }
    //stay in same position/dont move
    else{
        nextRow = 0;
        nextCol = 0;
    }
    
}


/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char** createMap(int maxRow, int maxCol) {
       if(maxRow <= 0 || maxCol <=0){
    return nullptr;
   }
   
   
    //create 2d array 
    char** map = new char*[maxRow];
    for(int i = 0; i < maxRow; ++i){
        map[i] = new char[maxCol];
    }

    //assign cell to tile_open
    for(int i = 0; i < maxRow; ++i){
        for(int j = 0; j < maxCol; ++j){
            map[i][j] = '-';
        }
    }

    return map;
}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
void deleteMap(char**& map, int& maxRow) {
    for(int i = 0; i < maxRow; ++i){
        delete[] map[i];
    }
    delete[]map;
    maxRow = 0;
    map = nullptr;
}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */
char** resizeMap(char** map, int& maxRow, int& maxCol) {
    int maxRow2 = maxRow * 2;
    int maxCol2 = maxCol *2;
    int tempMaxRow = maxRow;

    char** newMap = new char*[maxRow2];

  

    return nullptr;
}

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol) {
    char input = 'e';
    getDirection(input, nextRow, nextCol);

    int status = STATUS_STAY;

    if(map[nextRow][nextCol] == '+' || map[nextRow][nextCol] == 'M'){
        map[player.row][player.col] = 'o';
        status = STATUS_STAY;
    }

    if(player.row == 0 && input == 'w'){
        map[player.row][player.col] = 'o';
        status = STATUS_STAY;
    }
    if(player.row == maxRow && input == 's'){
        map[player.row][player.col] = 'o';
        status = STATUS_STAY;
    }
    if(player.col == 0 && input == 'a'){
        map[player.row][player.col] = 'o';
        status = STATUS_STAY;
    }
    if(player.col == maxCol && input == 'd'){
        map[player.row][player.col] = 'o';
        status = STATUS_STAY;
    }

    if(map[nextRow][nextCol] == '$'){
        map[player.row][player.col] = '-';
        map[nextRow][nextCol] = 'o';
        player.treasure += 1;
        status = STATUS_TREASURE;
        
    }

    if(map[nextRow][nextCol] == '!' && player.treasure > 0){
        map[player.row][player.col] = '-';
        map[nextRow][nextCol] = 'o';
        status = STATUS_ESCAPE;
    }
    if (map[nextRow][nextCol] == '!' && player.treasure < 1){
        map[player.row][player.col] = 'o';
        status = STATUS_STAY;
    }

    if(map[nextRow][nextCol] == '@'){
        map[player.row][player.col] = '-';
        map[nextRow][nextCol] = 'o';
        status = STATUS_AMULET;
    }
    
    if(map[nextRow][nextCol] == '-'){
        map[player.row][player.col] = '-';
        map[nextRow][nextCol] = 'o';
        status = STATUS_MOVE;
    }

    if(map[nextRow][nextCol] == '?'){
        map[player.row][player.col] = '-';
        map[nextRow][nextCol] = 'o';
        status = STATUS_LEAVE;
    }









    return 0;
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char** map, int maxRow, int maxCol, const Player& player) {
    return false;
}
