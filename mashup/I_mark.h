/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef INSTRUCTION_MARK_H
#define INSTRUCTION_MARK_H

#include "instruction.h"
using namespace aux;

class I_mark: public Instruction 
{
public:
    
    /*
     * Execute this instruction on a given bug.
     * @param b: Bug to execute the instruction on.
     * @param w: The world in which we need to action
     */
    void execute(Bug b, World w);
    
    /*
     * Parse the instruction, given a string.
     * @param args: coded instruction in string to parse the instruction from.
     */
    void parse(std::string args);
private:
    int m;
    tstate z;
};

#endif /* INSTRUCTION_MARK_H */