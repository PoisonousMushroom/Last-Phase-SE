/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "cell.h"
#include "exception.h"

Cell::Cell(char symb) {
    food = 0;
    c = symb;
    if (symb == '#') {
        obstructed = true;
        home_black_bug = false;
        home_red_bug = false;
    } else if (symb == '-') {
        obstructed = false;
        home_black_bug = true;
        home_red_bug = false;
    } else if (symb == '+') {
        obstructed = false;
        home_black_bug = false;
        home_red_bug = true;
    } else if (symb == '.') {
        obstructed = false;
        home_black_bug = false;
        home_red_bug = false;
    } else if (symb >= 49 && symb <= 57) {
        obstructed = false;
        home_black_bug = false;
        home_red_bug = false;
        food = symb - '0';
    } else {
        throw Exception("Invalid symbol\n");
    }

}

int Cell::get_food()
{
    return food;
}

void Cell::set_food(int new_food)
{
    if (new_food >=0)
    {
        food= new_food;
    } else {
        throw Exception("Food can't be a negative valued");
    }
}

bool Cell::get_obstructed()
{
    return obstructed;
}

Bug* Cell::get_occupant() {
    if(occupant){
        return occupant;
    }
    else{
        throw Exception("Occupant hasn't been set yet");
    }
}

void Cell::set_occupant(Bug* new_occupant) {
    occupant = new_occupant;
    obstructed=true;
}

void Cell::set_occupancy(bool b){
    occupant_set = b;
    occupant=NULL;
}

bool Cell::is_black_home_area()
{
    return home_black_bug;
}

bool Cell::is_red_home_area()
{
    return home_red_bug;
}

bool Cell::occupied(){
    return occupant_set;
}
