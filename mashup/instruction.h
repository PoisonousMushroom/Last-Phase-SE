/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


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