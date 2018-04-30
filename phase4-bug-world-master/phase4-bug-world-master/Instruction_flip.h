#ifndef INSTRUCTION_FLIP_H
#define INSTRUCTION_FLIP_H

#include "Instruction.h"

class Instruction_flip: public Instruction 
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
    
    int randomint();
private:
    int p;
    tstate x, y;
    int seed;
};

#endif /* INSTRUCTION_FLIP_H */

