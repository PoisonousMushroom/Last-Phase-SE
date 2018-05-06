/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "I_move.h"
#include "tokenizer.h"
#include <vector>
#include <string>
#include "adjacent_cell.h"
#include "checkforbugs.h"


void I_move::execute(Bug b)
{
    int nx,ny;
    aux::tposition t=b.get_position();
    adjacentCell(t.x,t.y,b.get_direction().d,&nx,&ny);
    aux::tposition n(nx,ny);
    Cell &cell=*w->get_cell(n);
    Cell &oldcell=*w->get_cell(t);
    if(cell.get_obstructed()||cell.occupied())
    {
        b.set_state(y);
    }
    else
    {
        cell.set_occupant(&b);
        oldcell.set_occupancy(false);
        b.set_position(tposition(nx,ny));
        b.set_state(x);
        b.start_resting();
        checkforbugs(w,nx,ny);
    }
}

void I_move::parse(string args)
{
    vector<string> command=tokens_in_vector(args);
    vector<string>::iterator it=command.begin();
    it++;
    string s=*it;
    aux::tstate aux(s);
    x=aux;
    it++;
    s=*it;
    aux::tstate aux2(s);
    y=aux2;
}
