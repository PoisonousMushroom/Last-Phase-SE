#include "Instruction_turn.h"

void Instruction_turn::parse(std::string instr) {
    /* sense dir x y */
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
                d = tdirection(std::stoi(token[0]));
                break;
            case 2:
                x = tstate(std::stoi(token));
                break;
            case 3:
                y = tstate(std::stoi(token));
                break;
        }
        instr.erase(0, pos + delimiter.length());
        i++;
    }
}

void Instruction_turn::execute(Bug b) {
    b.set_state(tstate(x));
}
