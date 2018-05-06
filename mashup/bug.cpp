/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "bug.h"

using namespace std;
using namespace aux;

Bug::Bug() 
{
    color = tcolor();
    prog_id = -1;
    resting = 0;    
    remaining_rest = 0;
    has_food = false;
    dead = false;
    direction=tdirection();
}

Bug::Bug(tcolor c, int new_pid, int new_resting){
        if(c.c > 1 || c.c < 0){
            throw Exception("Color number must be 0 or 1.\n");
        }
        color = c;
        prog_id = new_pid;
        resting = new_resting;
        remaining_rest=0;    
        has_food=false;
        dead=false;                
}

tstate Bug::get_state()
{
    return state;
}

void Bug::set_state(tstate s)
{
    state=s;
}

tdirection Bug::get_direction()
{
    return direction;
}

void Bug::set_direction(tdirection d)
{
    direction=d;
}

bool Bug::get_food()
{
    return has_food;
}

void Bug::set_food(bool f)
{
    if(has_food == true && f == true){
        throw Exception("Bug already has food! \n");
    }
    has_food = f;   
}

tcolor Bug::get_color()
{
    return color;
}

int Bug::get_progid()
{
    return prog_id;
}

void Bug::set_position(tposition t)
{
    pos=t;
}

tposition Bug::get_position()
{
    return pos;
}

void Bug::start_resting()
{
    if(remaining_rest>0)
    {
        throw "The bug was already resting\n";
    }
    remaining_rest=resting;
}

bool Bug::rested()
{
    if(remaining_rest>0)
    {
        remaining_rest--;
        return 0;
    }
    return 1;
}

bool Bug::is_dead()
{
    return dead;
}

void Bug::kill()
{
    if(dead == true){
        throw Exception("Bug is already dead!\n");
    }
    dead = true;
}