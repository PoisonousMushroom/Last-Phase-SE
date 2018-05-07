/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "I_turn.h"
#include <vector>
#include <string>
#include "tokenizer.h"
#include <iostream>
int turn (aux::tleftright l,aux::tdirection dir)
{
    switch(l.l)
    {
        case 0://left
            return (dir.d+5)%6;
        break;
        case 1://right
            return (dir.d+1)%6;
        break;
    }
}

void I_turn::execute(Bug b)
{
    b.set_direction(turn(lr,b.get_direction()));
    b.set_state(z);
}

void I_turn::parse(string args)
{
    vector<string> command=tokens_in_vector(args);
    vector<string>::iterator it=command.begin();
    it++;
    string s=*it;
    cout<<s<<endl;
    aux::tleftright aux(s);
    lr=aux;
    it++;
    s=*it;
    aux::tstate aux2(s);
    std::cout<<"turn "<<lr.l<<" "<<aux2.st<<std::endl;
    z=aux2;
}
