#ifndef INSTRUCTION_DIRECTION_H
#define INSTRUCTION_DIRECTION_H

#include "Instruction.h"

class Instruction_direction: public Instruction 
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
    tdirection d;
    tstate x, y;
};

#endif /* INSTRUCTION_DIRECTION_H */

