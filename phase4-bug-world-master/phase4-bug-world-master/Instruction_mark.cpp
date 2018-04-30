#include "Instruction_mark.h"

void Instruction_mark::parse(std::string instr) {
    /* move x y */
    std::string delimiter = " ";
    size_t pos = 0;
    std::string token;
    int i = 0;

    while ((pos = instr.find(delimiter)) != std::string::npos) {
        token = instr.substr(0, pos);
        switch (i) {
            case 0:
                break;
            case 1:
                x = tstate(std::stoi(token));
                break;
            case 2:
                y = tstate(std::stoi(token));
                break;
        }
        instr.erase(0, pos + delimiter.length());
        i++;
    }
}

void Instruction_mark::execute(Bug b) {
    set_marker(mark_new, color_new);
    b.set_position(tposition(x,y));
}
