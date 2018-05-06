
#ifndef L_MOVE_H
#define L_MOVE_H
#include "aux.h"
#include "instruction.h"

class I_move{
private:
    aux::tstate x;
    aux::tstate y;
public:
    void execute(Bug b, World w);
    void parse(string args);
};


#endif /* L_MOVE_H */
