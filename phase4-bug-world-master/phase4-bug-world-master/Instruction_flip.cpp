#include "Instruction_flip.h"


void Instruction_flip::parse(std::string instr) {
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

int Instruction_flip::randomint(){
    int random_int = std::rand();
    return random_int;
}

void Instruction_flip::execute(Bug b) {
    int random_nr = randomint();
    if (random_nr == 0){
        b.set_state(tstate(x));
    }
    else {
       b.set_state(tstate(y));
    }
}
