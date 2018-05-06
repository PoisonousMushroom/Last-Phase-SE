/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "I_direction.h"
#include <vector>
#include <string>
#include "tokenizer.h"


void I_direction::execute(Bug b)
{
    aux::tdirection di=b.get_direction();
    if(di.d==d.d)
    {
        b.set_state(x);
    }
    else
        b.set_state(y);
}

void I_direction::parse(string args)
{
    vector<string> command=tokens_in_vector(args);
    vector<string>::iterator it=command.begin();
    it++;
    string s=*it;
    aux::tdirection a(s);
    d=a;
    it++;
    s=*it;
    aux::tstate aux(s);
    x=aux;
    it++;
    s=*it;
    aux::tstate aux2(s);
    y=aux2;
}
