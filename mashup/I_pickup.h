/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#ifndef L_PICKUP_H
#define L_PICKUP_H
#include "instruction.h"

using namespace aux;


class I_pickup: public Instruction
{
public:
    
    /*
     * Execute this instruction on a given bug.
     * @param b: Bug to execute the instruction on.
     */
    void execute(Bug b, World w);
    
    /*
     * Parse the instruction, given a string.
     * @param instr: coded instruction in string to parse the instruction from.
     */
    void parse(std::string args);
private:
    tstate x, y;
};

#endif /* L_PICKUP_H */

