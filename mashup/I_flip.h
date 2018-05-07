/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef INSTRUCTION_FLIP_H
#define INSTRUCTION_FLIP_H

#include "aux.h"
#include "bug.h"
#include <math.h>

using namespace aux;

class I_flip{
public:

    /*
     * Execute this instruction on a given bug.
     * @param b: Bug to execute the instruction on.
     */
    void execute(Bug b);

    /*
     * Parse the instruction, given a string.
     * @param args: coded instruction in string to parse the instruction from.
     */
    void parse(std::string args);

private:
    int p;
    tstate x, y;
    int seed=12345;

    int randomint(){
        int s1=(seed*22695477+1)%int(pow(2,30));
        int s2=(s1*22695477+1)%int(pow(2,30));
        int s3=(s2*22695477+1)%int(pow(2,30));
        int s4=(s3*22695477+1)%int(pow(2,30));
        int x=((int)(s4/pow(2,16))%int(pow(2,30)));
        seed=s1;
        return x;
    }
};

#endif /* INSTRUCTION_FLIP_H */
