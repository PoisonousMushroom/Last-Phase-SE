#ifndef INSTRUCTION_PICKUP_H
#define INSTRUCTION_PICKUP_H

#include "Instruction.h"

class Instruction_pickup: public Instruction
{
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
    void parse(std::string instr);
private:
    tstate x, y;
};

#endif /* INSTRUCTION_PICKUP_H */

