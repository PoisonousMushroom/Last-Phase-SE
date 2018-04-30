/* 
 * File: Cell.cpp
 */

#include "Cell.h"
#include "Bug.h"
#include "Exception.h"

using namespace std;

Cell::Cell()
{
}

Cell::~Cell()
{
}

Cell::Cell(char symb)
{
    /*
     * We don't yet initialize the occupant.
     * The marker is not yet implemented -> not initialized either.
     */
    switch(symb){
        case '#': 
            obstructed = true;
            food = 0;
            homeBlackBug = false;
            homeRedBug = false;
            break;
        case '.':
            obstructed = false;
            food = 0;
            homeBlackBug = false;
            homeRedBug = false;
            break;
        case '-':
            homeBlackBug = true;
            homeRedBug = false;
            food = 0;
            obstructed = false;
            break;
        case '+':
            obstructed = false;
            food = 0;
            homeBlackBug = false;
            homeRedBug = true;
            break;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            obstructed = false;
            food = symb - 48;
            homeBlackBug = false;
            homeRedBug = false;
            break;
        default:
            throw(Exception("Invalid symbol! Cannot initialize cell!"));
            break;
    }
}

Bug Cell::getOccupant()
{
    return occupant;
}

void Cell::setOccupant(Bug newBug)
{
    occupant = newBug;
}

int Cell::getFood()
{
    return food;
}

void Cell::setFood(int newFood)
{
    food = newFood;
}

bool Cell::getObstructed()
{
    return obstructed;
}

bool Cell::isBlackHomeArea()
{
    return homeBlackBug;
}

bool Cell::isRedHomeArea()
{
    return homeRedBug;
}
