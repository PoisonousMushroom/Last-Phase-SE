/* 
 * File:   Cell.h
*/

#ifndef CELL_H
#define CELL_H

#include "Structs.h"
#include "Marker.h"
#include "Bug.h"

class Cell{
private:
    /* Bug currently occupying the cell */
    Bug occupant;
    /* Boolean whether or not this cell is obstructed */
    bool obstructed;
    /* Amount of food currently in this cell */
    int food;
    /* Set of markers currently in this cell */
    Marker mark;
    /* Boolean of whether this cell is a black bug home */
    bool homeBlackBug;
    /* Boolean of whether this cell is a red bug home */
    bool homeRedBug;
public:
    
    /*
     * Default constructor for Cell.
     */
    Cell();
    
    /*
     * Constructor for a new cell, given symbol code.
     * @param symb: Symbol code to create new cell.
     *              #: obstacle, .: clear, -: black bug home
     *              +: red bug home, 1..9: food.
     */
    Cell(char symb);
    
    /*
     * Deconstructor for Cell.
     */
    ~Cell();
    
    /*
     * Get method for the cells occupant.
     * @return Bug: current occupant
     */
    Bug getOccupant();
    
    /*
     * Set a new occupant to this cell.
     * @param new_occupant: Bug that should be the new occupant.
     */
    void setOccupant(Bug newBug);
    
    /*
     * Get method for the cells food count.
     * @return int: current amount of food in the cell.
     */
    int getFood();
    
    /*
     * Set the amount of food for this cell.
     * @param new_food: integer value for the amount of food in the cell.
     */
    void setFood(int newFood);
    
    /*
     * Get method for the cells obstructed property.
     * @return bool: whether or not the cell is obstructed.
     */
    bool getObstructed();
    
    /*
     * Check if this is a black home area.
     * @return bool: whether or not the cell is a black home area.
     */
    bool isBlackHomeArea();
    
    /*
     * Check if this is a red home area.
     * @return bool: whether or not the cell is a red home area.
     */
    bool isRedHomeArea();
};

#endif