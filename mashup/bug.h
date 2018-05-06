/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef BUG_H
#define BUG_H

using namespace std;

#include "aux.h"
#include "exception.h"

class Bug{
public:
    /*
     * Default Bug constructor.
     */
    Bug();

    /*
     * Default Bug destructor
     */
    ~Bug(){};

    /*
     * Constructor for the bug
     * @param col: Color of the Bug
     * @param progid: Id of the program currently running
     * @param resting: Boolean whether or not the Bug is resting
     */
    Bug(aux::tcolor i_col, int i_progid, int i_resting);
    
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
    aux::tcolor get_color();
    
    /*
     * Bug state getter.
     * @return tstate: current state of this Bug.
     */
    aux::tstate get_state();
    
    /*
     * Bug state setter.
     * @param new_state: new state of the Bug.
     */
    void set_state(aux::tstate new_state);
    
    /*
     * Bug direction getter.
     * @return tdirection: current direction of the Bug.
     */
    aux::tdirection get_direction();
    
    /*
     * Bug direction setter.
     * @param new_direction: new direction for the Bug.
     */
    void set_direction(aux::tdirection new_direction);
    
    /*
     * Bug position getter.
     * @return tposition: current position of the Bug.
     */
    aux::tposition get_position();
    
    /*
     * Bug position setter.
     * @param new_position: new position of the Bug.
     */
    void set_position(aux::tposition new_position);
    
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

    /*
     * Equality operator overload
     */
    inline bool operator==(const Bug& b){ 
        if((b.color.c == color.c) && (b.prog_id == prog_id)){
            return true;
        }
        return false;                
    }
private:
    aux::tstate state;
    aux::tcolor color;
    aux::tdirection direction;
    int resting;
    bool has_food = false;
    int prog_id;
    aux::tposition pos;
    bool dead = false;
    int remaining_rest = 0;
};

#endif