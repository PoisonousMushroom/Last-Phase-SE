/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef INSTRUCTION_TURN_H
#define INSTRUCTION_TURN_H

#include "aux.h"
#include "bug.h"
using namespace aux;

class I_turn{
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
private:
    tleftright lr;
    tstate z;
};

#endif /* INSTRUCTION_TURN_H */