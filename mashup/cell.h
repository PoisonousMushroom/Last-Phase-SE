#include "bug.h"
#include "marker.h"
#ifndef CELL_H
#define CELL_H
class Cell{
private:
    Bug* occupant;
    bool obstructed; //Blocked cell
    int food;
    bool home_black_bug;
    bool home_red_bug;
    bool occupant_set;
    char c;
public:
    Marker mark;
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
    Bug* get_occupant();

    /*
     * Set a new occupant to this cell.
     * @param new_occupant: Bug that should be the new occupant.
     */
    void set_occupant(Bug* new_occupant);

    /*
     * Get method for the cells food count.
     * @return int: current amount of food in the cell.
     */
    int get_food();

    /*
     * Set the amount of food for this cell.
     * @param new_food: integer value for the amount of food in the cell.
     */
    void set_food(int new_food);

    /*
     * Get method for the cells obstructed property.
     * @return bool: whether or not the cell is obstructed.
     */
    bool get_obstructed();

    /*
     * Check if this is a black home area.
     * @return bool: whether or not the cell is a black home area.
     */
    bool is_black_home_area();

    /*
     * Check if this is a red home area.
     * @return bool: whether or not the cell is a red home area.
     */    
    bool is_red_home_area();
};
#endif