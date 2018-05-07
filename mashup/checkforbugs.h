/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#ifndef CHECKFORBUGS_H
#define CHECKFORBUGS_H
#include "aux.h"
#include "world.h"

int otherColor(aux::tcolor val);
int adjacentBug(World &w, int x, int y, int color);
void checkforsurrounded(World *w,int x, int y);
void checkforbugs(World *w, int x, int y);
#endif