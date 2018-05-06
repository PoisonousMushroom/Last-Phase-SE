/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#ifndef I_MOVE_H
#define I_MOVE_H
#include "aux.h"

class I_move{
private:
    aux::tstate x;
    aux::tstate y;
public:
    void execute(Bug b, World w);
    void parse(string args);
};


#endif /* I_MOVE_H */
