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
        if(!file.is_open())
        {
            return nullptr;
        }


    maxRow = 0;
    maxCol = 0;
    player.row = 0;
    player.col = 0;

    file >> maxRow;
    if(file.fail())
    {
        return nullptr;
    }
    if(maxRow < 1)
    {
        return nullptr;
    }
    file >> maxCol;
    if(file.fail())
    {
        return nullptr;
    }
    if(maxCol < 1)
    {
        return nullptr;
    }
    if(maxRow > INT32_MAX / maxCol)
    {
        return nullptr;
    }
    file >> player.row;
    if(file.fail())
    {
        return nullptr;
    }
    if(player.row < 0)
    {
        return nullptr;
    }
    if(player.row > maxRow)
    {
        return nullptr;
    }
    file >> player.col;
    if(file.fail())
    {
        return nullptr;
    }
    if(player.col < 0)
    {
        return nullptr;
    }
    if(player.col > maxCol)
    {
        return nullptr;
    }

    char symb = '\0';
   
    char** map = createMap(maxRow, maxCol);
    bool exit = false;
    int total = maxRow * maxCol;
    int count = 0;


    for(int i = 0; i < maxRow; ++i){
        for(int j = 0; j < maxCol; ++j){
            file >> symb;
            if(file.eof())
            {
                if(count < total)
                {
                    deleteMap(map, maxRow);
                    return nullptr;
                }
            }
            ++count;
            //map[i][j] = symb;
            switch(symb)
            {
                case TILE_DOOR:
                    map[i][j] = symb;
                    exit = true;
                    break;
                case TILE_EXIT:
                    map[i][j] = symb;
                    exit = true;
                    break;
                case TILE_OPEN:
                    map[i][j] = symb;
                    break;
                case TILE_PLAYER:
                    map[i][j] = symb;
                    break;
                case TILE_TREASURE:
                    map[i][j] = symb;
                    break;
                case TILE_AMULET:
                    map[i][j] = symb;
                    break;
                case TILE_MONSTER:
                    map[i][j] = symb;
                    break;
                case TILE_PILLAR:
                    map[i][j] = symb;
                    break;
                default:
                    deleteMap(map, maxRow);
                    return nullptr;

            }
         


        }
    }

    if(!exit)
    {
        deleteMap(map, maxRow);
        return nullptr;
    }

    map[player.row][player.col] = TILE_PLAYER;


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
    input = tolower(input);
     if(input == MOVE_UP){
        //row decreases by 1 
        nextRow = nextRow - 1;
    }
    //moveleft
    else if (input == MOVE_LEFT){
        //column decreases by 1
        nextCol = nextCol - 1;
    }
    //movedown
    else if (input == MOVE_DOWN){
        //row increases by 1
        nextRow = nextRow + 1;
    }
    //moveright
    else if (input == MOVE_RIGHT){
        //column increases by 1
        nextCol = nextCol + 1;
    }
    //stay in same position/dont move
   
    
 //   return;
    
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
     if(maxRow < 0 || maxCol <0){
    return nullptr;
   }
   
   
    //create 2d array 
    char** map = new char*[maxRow];
    for(int i = 0; i < maxRow; ++i){
        map[i] = new char[maxCol];
        for(int j = 0; j < maxCol; ++j)
        {
            map[i][j] = TILE_OPEN;
        }
    }

    //assign cell to tile_open
    // for(int i = 0; i < maxRow; ++i){
    //     for(int j = 0; j < maxCol; ++j){
    //         map[i][j] = '-';
    //     }
    // }

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
    if(map == nullptr)
    {
        return nullptr;
    }
    if(maxRow < 1)
    {
        return nullptr;
    }
    if(maxRow > INT32_MAX /2)
    {
        return nullptr;
    }
    if(maxCol < 1)
    {
        return nullptr;
    }
    if(maxCol > INT32_MAX/2)
    {
        return nullptr;
    }

    int maxRow2 = maxRow * 2;
    int tempCol = maxCol;
    int tempMaxRow = maxRow;
    int playRow = 0;
    int playCol = 0;

    for(int i = 0; i < maxRow; ++i)
    {
        for(int j = 0; j < maxCol; ++j)
        {
            if(map[i][j] == TILE_PLAYER)
            {
                playRow = i;
                playCol = j;
            }
        }
    }

     char** newMap = new char*[maxRow2];
     for(int i = 0; i < maxRow2; ++i)
     {
        newMap[i] = new char[maxCol * 2];
     }

     for(int i = 0; i < tempMaxRow; ++i)
     {
        for(int j = 0; j < tempCol; ++j)
        {
            if(map[i][j] == TILE_PLAYER)
            {
                map[i][j] = TILE_OPEN;
            }
            newMap[i][j] = map[i][j];
            newMap[i][j+tempCol] = map[i][j];
            newMap[i + tempMaxRow][j + tempCol] = map[i][j];
            newMap[i + tempMaxRow][j] = map[i][j];
        }
     }


     newMap[playRow][playCol] = TILE_PLAYER;

     deleteMap(map, tempMaxRow);
     maxRow *=2;
     maxCol*=2;
     return newMap;


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
    // char input;
    // cin >> input;
    // getDirection(input, nextRow, nextCol);

   // int status = STATUS_STAY;

    if(nextRow < 0)
    {
        return STATUS_STAY;
    }
    if(nextRow >= maxRow)
    {
        return STATUS_STAY;
    }
    if(nextCol >= maxCol)
    {
        return STATUS_STAY;
    }
    if(nextCol < 0)
    {
        return STATUS_STAY;
    }

    switch(map[nextRow][nextCol])
    {
        case TILE_MONSTER:
            return STATUS_STAY;
        case TILE_PILLAR:
            return STATUS_STAY;
        case TILE_AMULET:
            map[player.row][player.col] = TILE_OPEN;
            map[nextRow][nextCol] = TILE_PLAYER;
            
            return STATUS_AMULET;
        case TILE_TREASURE:
            map[player.row][player.col] = TILE_OPEN;
            map[nextRow][nextCol] = TILE_PLAYER;
            ++player.treasure;
            return STATUS_TREASURE;
        case TILE_DOOR:
            map[player.row][player.col] = TILE_OPEN;
            map[nextRow][nextCol] = TILE_PLAYER;
            return STATUS_LEAVE;
        case TILE_EXIT:
            if(player.treasure > 0)
            {
                map[player.row][player.col] = TILE_OPEN;
                map[nextRow][nextCol] = TILE_PLAYER;
                return STATUS_ESCAPE;
            }
            else
            {
                return STATUS_STAY;
            }
        case TILE_OPEN:
            map[player.row][player.col] = TILE_OPEN;
            player.row = nextRow;
            player.col = nextCol;
            map[player.row][player.col] = TILE_PLAYER;
            return STATUS_MOVE;
        default:
            return STATUS_STAY;


    }

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
    char t;
    bool e = false;
    for(int i = player.row - 1; i > -1; --i)
    {
        t = map[i][player.col];
        if(t == TILE_PILLAR)
        {
            break;
        }
        else if(t == TILE_MONSTER)
        {
            map[i+1][player.col] = TILE_MONSTER;
            //tile where monster was - now open 
            map[i][player.col] = TILE_OPEN;
            if(i + 1 == player.row)
            {
                e = true;
            }
        }
    }

     for(int i = player.row +1; i < maxRow; ++i){
        //check for pillars 
        t= map[i][player.col];
        if(t == TILE_PILLAR){
            break;
        }
        else if( t == TILE_MONSTER)
        {
            map[i-1][player.col] = 'M';
            //tile where monster was = now open
            map[i][player.col] = '-';
            if(i - 1 == player.row)
            {
                e = true;
            }
        }
     }

      for(int i = player.col - 1; i > 0; --i)
      {
        t = map[player.row][i];
        if(t == TILE_PILLAR)
        {
            break;
        }
        else if(t == TILE_MONSTER)
        {
            map[player.row][i+1] =TILE_MONSTER;
            //tile opem
            map[player.row][i] = TILE_OPEN;
            if(i + 1 == player.col)
            {
                e = true;
            }
        }

      }

      for(int i = player.col + 1; i < maxCol; ++i)
      {
        t = map[player.row][i];
        if(t == TILE_PILLAR)
        {
            break;
        }
        else if (t == TILE_MONSTER)
        {
            map[player.row][i] = TILE_OPEN;
            map[player.row][i-1] = TILE_MONSTER;
            if(i - 1 == player.col)
            {
                e = true;
            }
        }
      }
      return e;

}
