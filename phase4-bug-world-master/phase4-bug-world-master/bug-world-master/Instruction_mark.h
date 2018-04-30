#ifndef INSTRUCTION_MARK_H
#define INSTRUCTION_MARK_H

#include "Instruction.h"

class Instruction_mark: public Instruction 
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
    int m;
    tstate z;
};

#endif /* INSTRUCTION_MARK_H */

