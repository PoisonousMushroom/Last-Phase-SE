/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef PROGRAM_H
#define PROGRAM_H

#include "instruction.h"
#include <vector>
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
  vector<I_direction> ldi;
  vector<I_drop> ldr;
  vector<I_flip> lfl;
  vector<I_mark> lma;
  vector<I_move> lmo;
  vector<I_pickup> lpi;
  vector<I_sense> lse;
  vector<I_turn> ltu;
  vector<I_unmark> lun;
  map<int,(std::pair<int,std::string>)> order;
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
