/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "I_drop.h"
#include <vector>
#include <string>
#include "tokenizer.h"
#include <iostream>

void I_drop::execute(Bug b )
{
    aux::tposition t=b.get_position();
    Cell &cell=*(w->get_cell(t));
    if(b.get_food())
    {
        cell.set_food(cell.get_food()+1);
        b.set_food(false);
    }
    b.set_state(z);
}

void I_drop::parse(string args)
{
    vector<string> command=tokens_in_vector(args);
    vector<string>::iterator it=command.begin();
    it++;
    string s=*it;
    aux::tstate aux(s);
    z=aux;
    std::cout<<"drop "<<z.st<<std::endl;
}
