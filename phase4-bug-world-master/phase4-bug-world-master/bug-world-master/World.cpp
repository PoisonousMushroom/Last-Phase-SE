/*
 * File: World.cpp
 */

#include "World.h"

World::World(){}

void World::load(std::string filename){
    /* TODO: to be implemented. */
}

void World::executeCycle(){
    /* TODO: to be implemented. */
}

Cell World::getCell(tposition pos){
    if(pos.posX > width || pos.posY > height){
        throw Exception("Out of bounds!");
    } else {
        return worldCells[pos.posX][pos.posY];
    }
}

tposition World::adjacent(tposition pos, tdirection dir){
    /*
     * Returns adjacent cell, with respect to direction.
     * If no such cell exists, return original position.
     */
    switch(dir.direction){
        case 0:
            if(pos.posX < width-1)
                return tposition(pos.posX+1, pos.posY);
            break;
        case 1:
            if(pos.posY%2 == 0 && pos.posY < height-1){
                return tposition(pos.posX, pos.posY+1);
            } else if (pos.posX < width-1 && pos.posY < height -1){
                return tposition(pos.posX+1, pos.posY+1);
            }
            break;
        case 2:
            if(pos.posY%2 == 0 && pos.posX > 0 && pos.posY < height-1){
                return tposition(pos.posX - 1, pos.posY+1);
            } else if (pos.posY < height -1){
                return tposition(pos.posX, pos.posY+1);
            }
            break;
        case 3:
            if(pos.posX > 0)
                return tposition(pos.posX-1, pos.posY);
            break;
        case 4:
            if(pos.posY%2 == 0 && pos.posX > 0 && pos.posY > 0){
                return tposition(pos.posX-1, pos.posY-1);
            } else if (pos.posY > 0){
                return tposition(pos.posX, pos.posY-1);
            }
            break;
        case 5:
            if(pos.posY%2 == 0 && pos.posY > 0){
                return tposition(pos.posX, pos.posY-1);
            } else if (pos.posX > 0 && pos.posY > 0){
                return tposition(pos.posX+1, pos.posY-1);
            }
            break;
        default:
            break;
    }
    return pos;
}

tcolor World::otherColor(tcolor color){
    return tcolor(!color.color);
}

tcolor World::winner(){
    return (redFood() > blackFood()) ? tcolor(0) : tcolor(1);
}

int World::redFood(){
    int count = 0;
    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            if(worldCells[x][y].isRedHomeArea())
                count += worldCells[x][y].getFood();
        }
    }
    return count;
}

int World::blackFood(){
    int count = 0;
    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            if(worldCells[x][y].isBlackHomeArea())
                count += worldCells[x][y].getFood();
        }
    }
    return count;
}

void World::throwError(std::string errMsg){
    throw Exception(errMsg);
}

void World::log(std::string logMsg){
    std::cout << logMsg << std::endl;
}