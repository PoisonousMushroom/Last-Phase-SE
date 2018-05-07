/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#ifndef I_DIRECTION_H
#define I_DIRECTION_H

#include "aux.h"
#include "bug.h"
using namespace aux;

class I_direction{
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
    I_direction(){
        d=tdirection();
        x=tstate();
        y=tstate();
    };
private:
    tdirection d;
    tstate x, y;
};

#endif /* I_DIRECTION_H */