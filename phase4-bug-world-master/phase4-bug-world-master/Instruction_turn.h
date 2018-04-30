#ifndef INSTRUCTION_TURN_H
#define INSTRUCTION_TURN_H

#include "Instruction.h"

class Instruction_turn: public Instruction 
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
    tleftright lr;
    tstate z;
};

#endif /* INSTRUCTION_TURN_H */

