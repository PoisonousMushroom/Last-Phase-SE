#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Bug.h"
#include "World.h"

class Instruction {
public:
    /*
     * Execute this instruction on a given bug.
     * @param b: Bug to execute the instruction on.
     */
    virtual void execute(Bug b) = 0;
    
    /*
     * Parse the instruction, given a string.
     * @param instr: coded instruction in string to parse the instruction from.
     */
    virtual void parse(std::string instr) = 0;
protected:
    /* world variable in which to execute the instructions. */
    World w;
};

#endif /* INSTRUCTION_H */