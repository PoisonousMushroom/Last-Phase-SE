/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#ifndef L_DROP_H
#define L_DROP_H

#include "world.h"
#include "aux.h"
#include "bug.h"
using namespace aux;
class World;
class I_drop {
public:
    
    /*
     * Execute this instruction on a given bug.
     * @param b: Bug to execute the instruction on.
     * @param w: The world in which we need to action
     */
    void execute(Bug b);
    
    /*
     * Parse the instruction, given a string.
     * @param args: coded instruction in string to parse the instruction from.
     */
    void parse(std::string args);
    World *w;
private:
    tstate z;
};

#endif /* L_DROP_H */