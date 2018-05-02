#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include "aux.h"
#include "world.h"
#include "bug.h"

class Instruction
{
private:
    
public:
    void execute(Bug b);
    void parse(string args);
};

#endif