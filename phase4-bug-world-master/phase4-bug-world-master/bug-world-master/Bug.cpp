/* 
 * File:   Bug.cpp
 */

#include "Bug.h"
#include "Exception.h"

using namespace std;

Bug::Bug() 
{
    this->color = tcolor();
    this->prog_id = -1;
    this->resting = -1;    
    this->state = tstate();
    this->position = tposition();
    this->direction = tdirection();
    this->remaining_rest = -1;
    this->food = false;
    this->dead = false;
}

Bug::Bug(tcolor i_col, int i_progid, int i_resting)
{
    /* given arguments */
    this->color = i_col;
    this->prog_id = i_progid;
    this->resting = i_resting;
    /* uninitialized fields */
    this->state = tstate();
    this->position = tposition();
    this->direction = tdirection();
    this->remaining_rest = -1;
    this->food = false;
    this->dead = false;
}

void Bug::start_resting()
{
    resting = 1;
}

bool Bug::rested()
{
    if(resting)
        return true;
    else
        return false;
}

int Bug::get_progid()
{
    return prog_id;
}

tcolor Bug::get_color()
{
    return color;
}

tstate Bug::get_state()
{
    return state;
}

void Bug::set_state(tstate new_state)
{
    state = new_state;
}

tdirection Bug::get_direction()
{
    return direction;
}

void Bug::set_direction(tdirection new_direction)
{
    direction = new_direction;
}

tposition Bug::get_position()
{
    return position;
}

void Bug::set_position(tposition new_position)
{
    position = new_position;
}

bool Bug::get_food()
{
    if(food)
        return true;
    else
        return false;
}

void Bug::set_food(bool new_food)
{
    food = new_food;
}

bool Bug::is_dead()
{
    if(dead)
        return true;
    else
        return false;
}

void Bug::kill()
{
    dead = true;
}