/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef INSTRUCTION_UNMARK_H
#define INSTRUCTION_UNMARK_H

#include "world.h"
#include "aux.h"
#include "bug.h"

using namespace aux;
class World;
class I_unmark {
public:
    
    /*
     * Execute this instruction on a given bug.
     * @param b: Bug to execute the instruction on.
     */
    void execute(Bug b);
    
    /*
     * Parse the instruction, given a string.
     * @param instr: coded instruction in string to parse the instruction from.
     */
    void parse(std::string args);
    World *w;
private:
    int m;
    tstate z;
};

#endif

