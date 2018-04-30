#ifndef INSTRUCTION_SENSE_H
#define INSTRUCTION_SENSE_H

#include "Instruction.h"

class Instruction_sense: public Instruction 
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

#endif /* INSTRUCTION_SENSE_H */

