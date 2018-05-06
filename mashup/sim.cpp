/*
* Simulator for the world
* Main for the bug game
*/
#include <algorithm>
#include "exception.h"
#include <iostream>
#include "../simulator/world.h"
#include "aux.h"
#include "./assembler/assembler.h"


using namespace std;
using namespace aux;


bool check_if_int(string v)
{
    int i=0;
    while(i<v.size())
    {
        if(v[i]<='9'&&v[i]>='0')
        {
            i++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main(int argc, string * argv)
{
    //number of cycles to be run
    int cycles=1000;
    //whether the files for the red and black bugs must be swapped
    bool reverse=false;
    //whether stats must be displayed
    bool stats=false;
    //after how many steps must information be emitted
    int every=1;
    /*
    * log - 0, no information about the state of the 
    *     simulation is displayed
    *     - 1, emit information is selab structure
    *     - 2, emit information is ascii structure
    */
    int log=0;
    //specifies whether to print a short help message
    bool help=false;
    string file_world, red_bug,black_bug;
    //holds the winner 
    tcolor winner; 

    for(int i=0; i<argc; i++)
    {
        if("-n"==argv[i] || "--cycles"==argv[i] )
        {
            i++;
            if(check_if_int(argv[i]))
            {
                cycles=stoi(argv[i]);
            }
            else{
                throw Exception("The number of cycles must be a natural number\n");
            }  
        }
        else if("-x"==argv[i] || "--swap"==argv[i])
        {
            reverse=true;
        }
        else if("-s"==argv[i] || "--stats"==argv[i])
        {
            stats=true;
        }
        else if("-e"==argv[i] || "--every"==argv[i])
        {
            i++;
            if(check_if_int(argv[i]))
            {
                every=stoi(argv[i]);
            }
            else{
                throw Exception("The every field must be a natural number\n");
            }  
        }
        else if("-l"==argv[i] || "--log"==argv[i])
        {
            i++;
            if("selab"==argv[i])
            {
                log=1;
            }
            else if("ascii"==argv[i])
            {
                log=2;
            }
            else
            {
                throw Exception("This is not a valid format for the log \n");
            }
        }
        else if("-h"==argv[i] || "--help"==argv[i])
        {
            if(i!=0)
            {
                throw Exception("You can't call help with other options\n");
            }
            if(argc!=1)
            {
                throw Exception("You can't call help with any other options or filenames\n");
            }
            help=true;
        }
        else if(argc-3==i)
        {
            if(argv[i].find(".world")==string::npos || argv[i].find(".world")!=argv[i].size()-6)
            {
                throw Exception("The command does not have a right structure. Use -h or --help for more details\n");
            }
            else
            {            
                file_world=argv[i];
            }
        }
        else if(argc-2==i)
        {
            if(argv[i].find(".bug")==string::npos || argv[i].find(".bug")!=argv[i].size()-4)
            {
                throw Exception("The command does not have a right structure. Use -h or --help for more details\n");
            }
            else
            {       
                if(reverse==true)
                    black_bug=argv[i];
                else      
                    red_bug=argv[i];
            }   
        }
        else if(argc-1==i)
        {
            if(argv[i].find(".bug")==string::npos || argv[i].find(".bug")!=argv[i].size()-4)
            {
                throw Exception("The command does not have a right structure. Use -h or --help for more details\n");
            }
            else
            {            
                if(reverse==true)
                    red_bug=argv[i];
                else
                    black_bug=argv[i];
            }   
        }
        else
        {
            throw Exception("The command does not have a right structure. Use -h or --help for more details\n");
        }
    }

    if(help==true)
    {
        cout<<"Usage sim\n sim [options] file.world red.bug black.bug"
        "\n\t -n int, --cycles int ; simulate for int cycles"
        "\n\t -x, --swap ; swap the files for red and black bugs"
        "\n\t -s, --stats ; display statistics on the stdout - without this no information will be displayed"
        "\n\t -e int, --every int ; emit information about the state of the simulation at each i cycle"
        "\n\t -l selab|ascii, --log selab|ascii ; emit information in format log or ascii"
        "\n\t -h, --help ;  emit a help message\n ";
    }
    else
    {
        //the assembler conversion of the bug files
        red_bug=convert(red_bug,1);
        black_bug=convert(black_bug,0);

        string s=file_world+" "+red_bug+" "+black_bug;
        World w;
        w.load(s);
        for(int i=0;i<cycles;i++)
        {
            w.execute_cycle();
            if(stats==true && i%every==0)
            {
                winner = w.winner();
                if(log == 0)
                {
                    cout<<"For round "<<i<<"the winners are the ";
                    if(winner.c==0)
                        cout<<"black bugs\n";
                    else
                        cout<<"red bugs\n";
                }
                if(log==1)
                {
                    cout<<"After cycle "<<i<<"\n";
                    cout<<"========== cell ========== ======= bug ======\n"
                    "        b b\n"
                    "        a i                    cbd\n"
                    "pos pos s t  red    black      oii\n"
                    " x   y  e s  marks  marks  id  ktr state rest\n"
                    "=== === = == ====== ====== === === ===== ====\n"
                    "...\n";
                    int bits=0;// ammount of food in cell
                    int id;//bug id
                    int state;//bug state
                    for(int k=0;k<w.get_length();k++)
                    {
                        for(int j=0;j<w.get_width();j++)
                        {
                            tposition p(k,j);
                            Cell* c=w.get_cell(p);
                            if(k<10)
                                cout<<"00"<<k;
                            else if(k<100)
                                    cout<<"0"<<k;
                            else   
                                cout<<k;
                            if(j<10)
                                cout<<" 00"<<j;
                            else if(j<100)
                                cout<<" 0"<<j;
                            else 
                                cout<<" "<<j;
                            if(c->is_black_home_area())
                                cout<<" b ";
                            if(c->is_red_home_area())
                                cout<<" r ";

                            bits=c->get_food();
                            if(bits<10)
                                cout<<"0"<<bits<<" ";
                            else
                                cout<<bits<<" ";
                            //check marks for red
                            for(int ve=5;ve>=0;ve--)
                            {
                                if(c->mark.check_marker(tmark(ve),tcolor(1)))
                                    cout<<ve;
                                else 
                                    cout<<"_";
                            }
                            //check marks for black
                            cout<<" ";
                            for(int ve=5;ve>=0;ve--)
                            {
                                if(c->mark.check_marker(tmark(ve),tcolor(0)))
                                    cout<<ve;
                                else 
                                    cout<<"_";
                            }
                            cout<<" ";
                            if(c->occupied())
                            {
                                Bug* b=c->get_occupant();
                                id=b->get_prog_id();
                                if(id<10)
                                    cout<<"00"<<id<<" ";
                                else if(id<100)
                                    cout<<"0"<<id<<" ";
                                else 
                                    cout<<id<<" ";
                                if(b->get_color().c==0)
                                    cout<<"b";
                                else 
                                    cout<<"r";
                                if(b->get_has_food())
                                    cout<<"X";
                                else    
                                    cout<<"_";
                                cout<<b->get_direction()<<" ";

                            }
                            cout<<"\n";
                        }
                    }
                }
            }
        }
    }
}