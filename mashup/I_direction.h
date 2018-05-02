#ifndef L_DIRECTION_H
#define L_DIRECTION_H
#include "instruction.h"

using namespace aux;

class I_direction: public Instruction 
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

#endif /* L_DIRECTION_H */