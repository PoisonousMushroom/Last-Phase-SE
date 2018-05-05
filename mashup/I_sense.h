#ifndef INSTRUCTION_SENSE_H
#define INSTRUCTION_SENSE_H

#include "instruction.h"

using namespace aux;

class Instruction_sense: public Instruction 
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
    tsensedir dir;
    tcondition condition;
};

#endif /* INSTRUCTION_SENSE_H */