/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "marker.h"
#include "I_unmark.h"
#include <vector>
#include <string>
#include "tokenizer.h"
#include <iostream>


void I_unmark::execute(Bug b)
{
    aux::tposition t=b.get_position();
    Cell &cell=*w->get_cell(t);
    cell.mark.clear_marker(m,b.get_color());
    b.set_state(z);
}

void I_unmark::parse(string args)
{
    vector<string> command=tokens_in_vector(args);
    vector<string>::iterator it=command.begin();
    it++;
    string s=*it;
    m=0;
    for(int i=0;i<s.size();i++)
    {
        m=m*10+(s[i]-'0');
    }
    it++;
    s=*it;
    aux::tstate aux(s);
    z=aux;
    std::cout<<"unmark "<<m<<" "<<z.st<<std::endl;
}
