/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#ifndef INSTRUCTION_SENSE_H
#define INSTRUCTION_SENSE_H

#include "aux.h"
#include "bug.h"
#include "world.h"
using namespace aux;
class World;
class I_sense{
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
    tstate x, y;
    tsensedir dir;
    tcondition condition;
};

#endif /* INSTRUCTION_SENSE_H */
