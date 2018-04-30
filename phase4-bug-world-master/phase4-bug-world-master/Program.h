#ifndef PROGRAM_H
#define PROGRAM_H

#include "Bug.h"
#include <iostream>

class Program 
{
private:
    /* Program id */
    int id;
public:
    /*
     * Create a new program from the given filename.
     * @param filename: name of the file from which to lead the program.
    */

    Program(std::string filename);

    /*
     * Executes the next instruction for this bug.
     * @param b: Bug to execute the instruction from.
     */

    void step(Bug b);
};

#endif /* PROGRAM_H */