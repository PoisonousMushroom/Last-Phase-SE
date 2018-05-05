#ifndef PROGRAM_H
#define PROGRAM_H

#include "instruction.h"
#include  <vector>
#include <map>
#include "I_drop.h"
#include "I_direction.h"
#include "I_flip.h"
#include "I_mark.h"
#include "I_move.h"
#include "I_pickup.h"
#include "I_sense.h"
#include "I_turn.h"
#include "I_unmark.h"
#include <utility>

class Program{
private:
  int id;
  vector<l_direction> ldi;
  vector<l_drop> ldr;
  vector<l_flip> lfl;
  vector<l_mark> lma;
  vector<l_move> lmo;
  vector<l_pickup> lpi;
  vector<l_sense> lse;
  vector<l_turn> ltu;
  vector<l_unmark> lun;
  map<int,pair<int,string>> order;
  World w;
  /*
  The values in order tell from which vector must we take the next command 
  and also the order of the command in the respective vector
  */
  int i;//number of instructions
public:
  Program(std::string filename, World w);
  Program(){};
  void step(Bug b, World w);

};


#endif