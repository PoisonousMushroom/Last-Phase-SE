#include "tokenizer.h"
#include <vector>
#include <string>
#include "I_mark.h"


void I_mark::execute(Bug b, World w)
{
    aux::tposition t=b.get_position();
    Cell &cell=*w.get_cell(t);
    cell.mark.set_marker(m,b.get_color());
    b.set_state(z);
}

void I_mark::parse(string args)
{
    vector<string> command=tokens_in_vector(args);
    vector<string>::iterator it=command.begin();
    it++;
    string s=*it;
    m=std::stoi(s);
    it++;
    s=*it;
    aux::tstate aux(s);
    z=aux;
}
