#ifndef L_DROP_H
#define L_DROP_H
#include "instruction.h"

using namespace aux;

class I_drop: public Instruction 
{
public:
    
    /*
     * Execute this instruction on a given bug.
     * @param b: Bug to execute the instruction on.
     * @param w: The world in which we need to action
     */
    void execute(Bug b, World w);
    
    /*
     * Parse the instruction, given a string.
     * @param args: coded instruction in string to parse the instruction from.
     */
    void parse(std::string args);
private:
    tstate z;
};

#endif /* L_DROP_H */