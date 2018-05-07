/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "program.h" 
#include "tokenizer.h"
#include <fstream>
#include "exception.h"

using namespace std;

Program::Program(string filename, World w)
{
    
    ifstream f(filename.c_str());
   
    if(!f.is_open())
    {
        throw "Unable to open the assembly language program file\n";
    }
    
   // vector<string> command;
    i=0;
    string s;

    while(f.good())
    {
        getline(f,s);
        vector<string> command=tokens_in_vector(s);
        vector<string>::iterator it=command.begin();
        if(*it== "sense"){
            I_sense* t;
            t->parse(s);
            t->w=&w;
            printf("%s\n",s.c_str());
            lse.push_back(t);
            order[i]=make_pair(lse.size(),"sense");
            i++;
        }
        else if(*it=="flip"){
            I_flip * f;
            f->parse(s);
            printf("%s\n",s.c_str());
            lfl.push_back(f);
            order[i]=make_pair(lfl.size(),"flip");
            i++;
        }
        else if(*it=="pickup"){
            I_pickup *p;
            p->parse(s);
            p->w=&w;
            printf("%s\n",s.c_str());
            lpi.push_back(p);
            order[i]=make_pair(lpi.size(),"pickup");
            i++;
        }
        else if(*it=="mark"){
            I_mark* t;
            t->parse(s);
            t->w=&w;
            printf("%s\n",s.c_str());
            lma.push_back(t);
            order[i]=make_pair(lma.size(),"mark");
            i++;
        }
        else if(*it=="unmark"){
            I_unmark* u;
            u->parse(s);
            u->w=&w;
            printf("%s\n",s.c_str());
            lun.push_back(u);
            order[i]=make_pair(lun.size(),"unmark");
            i++;
        }
        else if(*it =="direction"){
            I_direction * d;
            d->parse(s);
            printf("%s\n",s.c_str());
            ldi.push_back(d);
            order[i]=make_pair(ldi.size(),"direction");
            i++;
        }
        else if(*it=="move"){    
            I_move * m;
            m->parse(s);
            printf("%s\n",s.c_str());
            m->w=&w;
            lmo.push_back(m);
            order[i]=make_pair(lmo.size(),"move");
            i++;
        }
        else if(*it=="turn"){
            I_turn* t;
            t->parse(s);
            printf("%s\n",s.c_str());
            ltu.push_back(t);
            order[i]=make_pair(ltu.size(),"turn");
            i++;
        }
        else if(*it== "drop"){
            I_drop* dr;
            dr->parse(s);
            printf("%s\n",s.c_str());
            dr->w=&w;
            ldr.push_back(dr);
            order[i]=make_pair(ldr.size(),"drop");
            i++; 
        }
        else{
            throw Exception("Unspecified command\n");
        }
    }
    printf("well read\n");
    
}

void Program::step(Bug b, World w)
{
    if(!b.is_dead()){
        int rest=b.rested();
        if(rest==1){
            aux::tstate s=b.get_state();
            pair<int,string> aux=order[s.st];// recall first value the position, second value the type of instruction
            if(aux.second=="sense")
            {
                I_sense* in=lse[aux.first];
                in->execute(b);
            }
            if(aux.second=="flip")
            {
                I_flip* in=lfl[aux.first];
                in->execute(b);
            }
            if(aux.second=="pickup")
            {
                I_pickup* in=lpi[aux.first];
                in->execute(b);
            } 
            if(aux.second=="mark")
            {
                I_mark* in=lma[aux.first];
                in->execute(b);
            }
            if(aux.second=="unmark")
            {
                I_unmark* in=lun[aux.first];
                in->execute(b);
            }
            if(aux.second=="direction")
            {
                I_direction* in=ldi[aux.first];
                in->execute(b);
            }
            if(aux.second=="move")
            {
                I_move* in=lmo[aux.first];
                in->execute(b);
            }
            if(aux.second=="turn")
            {
                I_turn* in=ltu[aux.first];
                in->execute(b);
            }
            if(aux.second=="drop")
            {
                I_drop* in=ldr[aux.first];
                in->execute(b);
            }
        }
    }
}