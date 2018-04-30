#ifndef BUG_H
#define BUG_H

#include <iostream>
#include <vector>

#include "Exception.h"
#include "Structs.h"

class Bug{
private:
    /* color of the bug */
    tcolor color;
    /* current state of the bug */
    tstate state;
    /* reference to the current program id */
    int prog_id;
    /* current position of the bug */
    tposition position;
    /* current direction of the bug */
    tdirection direction;
    /* Resting property ? */
    int resting;
    /* number of rounds the bug still has to rest */
    int remaining_rest;
    /* amount of food the bug is carrying */
    bool food;
    /* Boolean whether or not the bug is dead */
    bool dead;
public:
    
    /*
     * Default Bug constructor.
     */
    Bug();
    
    /*
     * Constructor for the bug
     * @param col: Color of the Bug
     * @param progid: Id of the program currently running
     * @param resting: Boolean whether or not the Bug is resting
     */
    Bug(tcolor i_col, int i_progid, int i_resting);
    
    /*
     * Bug starts resting now.
     */
    void start_resting();
    
    /*
     * Boolean of whether the Bug is rested or not.
     * @return 0: if not rested, 1: if rested.
     */
    bool rested();
    
    /*
     * Program id getter.
     * @return int: program id.
     */
    int get_progid();
    
    /*
     * Bug color getter.
     * @return tcolor: color of this Bug.
     */
    tcolor get_color();
    
    /*
     * Bug state getter.
     * @return tstate: current state of this Bug.
     */
    tstate get_state();
    
    /*
     * Bug state setter.
     * @param new_state: new state of the Bug.
     */
    void set_state(tstate new_state);
    
    /*
     * Bug direction getter.
     * @return tdirection: current direction of the Bug.
     */
    tdirection get_direction();
    
    /*
     * Bug direction setter.
     * @param new_direction: new direction for the Bug.
     */
    void set_direction(tdirection new_direction);
    
    /*
     * Bug position getter.
     * @return tposition: current position of the Bug.
     */
    tposition get_position();
    
    /*
     * Bug position setter.
     * @param new_position: new position of the Bug.
     */
    void set_position(tposition new_position);
    
    /*
     * Binary bug food getter (whether or not it has food).
     * @return 0: if has no food, 1: if has food.
     */
    bool get_food();
    
    /*
     * Bug food setter.
     * @param: new_food: new boolean of whether or not Bug has food.
     */
    void set_food(bool new_food);
    
    /*
     * Bug binary dead getter.
     * @return 0: if bug is alive, 1: if bug is dead.
     */
    bool is_dead();
    
    /*
     * Kill this bug.
     */
    void kill();
};

#endif
