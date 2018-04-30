/* 
 * File: World.h
 */

#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>
#include "Cell.h"
#include "Exception.h"
#include "Structs.h"

class World{
private:
    /* dimensions of the world */
    int width, height;
    /* all the cells of the world, in 2D vector */
    std::vector<std::vector<Cell>> worldCells;
public:
    
    /*
     * Default constructor, no arguments needed.
     */
    World();
    
    /*
     * Deconstructor.
     */
    ~World();
    
    /*
     * Load the current world from a file.
     * @param filename: name of the file to load the data from.
     */
    void load(std::string filename);
    
    /*
     * Execute the next cycle in the world.
     */
    void executeCycle();
    
    /*
     * Return a cell, given a position.
     * @param pos: position in the world.
     * @return Cell: cell at that position in the world.
     */
    Cell getCell(tposition pos);
    
    /*
     * Given a position and direction, get the adjacent position.
     * @param pos: current position.
     * @param dir: current direction.
     * @return tposition: position that is adjacent to the arguments.
     */
    tposition adjacent(tposition pos, tdirection dir);
    
    /*
     * Given a color, return the other color.
     * @param color: color to be "inverted".
     * @return tcolor: inverted color.
     */
    tcolor otherColor(tcolor color);
    
    /*
     * Returns the color of the winning team.
     * @return tcolor: color of the winning team.
     */
    tcolor winner();
    
    /*
     * Returns the amount of food that team red has.
     * @return int: amount of food for team red.
     */
    int redFood();
    
    /*
     * Returns the amount of food that team black has.
     * @return int: amount of food for team black.
     */
    int blackFood();
    
    /*
     * Handling error messages.
     * @param errMsg: error message as string.
     */
    void throwError(std::string errMsg);
    
    /*
     * Handling log messages.
     * @param logMsg: log message as string.
     */
    void log(std::string logMsg);
};

#endif