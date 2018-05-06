/*
* Simulator for the world
* Main for the bug game
*/
#include <algorithm>
#include "exception.h"
#include <iostream>
#include "../simulator/world.h"
#include "aux.h"


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
        string s=file_world+" "+red_bug+" "+black_bug;
        World w;
        w.load(s);
        for(int i=0;i<cycles;i++)
        {
            w.execute_cycle();
            if(stats==true && i%every==0)
            {
                if(log == 0)
                {
                    w.winner()
                }
            }
        }
    }
}