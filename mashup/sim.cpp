/*
* Simulator for the world
* Main for the bug game
*/
#include <algorithm>
#include "exception.h"
#include "marker.h"
#include <iostream>
#include "world.h"
#include "aux.h"
#include "string.h"
#include "assembler.h"



using namespace std;
using namespace aux;


int check_if_int(char* v)
{
    int i=0;
    int x=0;
    while(i<strlen(v))
    {
        if(v[i]<='9'&&v[i]>='0')
        {
            i++;
            x=x*10+v[i]-'0';
        }
        else
        {
            return -100;
        }
    }
    return x;
}

int main(int argc, char** argv)
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

    for(int i=1; i<argc; i++)
    {
        if(strcmp("-n",argv[i])==0 || strcmp("--cycles",argv[i])==0 )
        {
            i++;
            if(check_if_int(argv[i])!=-100)
            {
                cycles=check_if_int(argv[i]);
            }
            else{
                throw Exception("The number of cycles must be a natural number\n");
            }  
        }
        else if(strcmp("-x",argv[i])==0 || strcmp("--swap",argv[i])==0)
        {
            reverse=true;
        }
        else if(strcmp("-s",argv[i])==0 || strcmp("--stats",argv[i])==0)
        {
            stats=true;
        }
        else if(strcmp("-e",argv[i])==0 || strcmp("--every",argv[i])==0)
        {
            i++;
            if(check_if_int(argv[i])!=-100)
            {
                every=check_if_int(argv[i]);
            }
            else{
                throw Exception("The every field must be a natural number\n");
            }  
        }
        else if(strcmp("-l",argv[i])==0 || strcmp("--log",argv[i])==0)
        {
            i++;
            if(strcmp("selab",argv[i])==0)
            {
                log=1;
            }
            else if(strcmp("ascii",argv[i])==0)
            {
                log=2;
            }
            else
            {
                throw Exception("This is not a valid format for the log \n");
            }
        }
        else if(strcmp("-h",argv[i])==0 || strcmp("--help",argv[i])==0)
        {
            if(i!=1)
            {
                throw Exception("You can't call help with other options\n");
            }
            if(argc!=2)
            {
                throw Exception("You can't call help with any other options or filenames\n");
            }
            help=true;
        }
        else if(argc-3==i)
        {
            if(strstr(argv[i],".world")==NULL || strstr(argv[i],".world")!=argv[i]+strlen(argv[i])-6)
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
            if(strstr(argv[i],".bug")==NULL || strstr(argv[i],".bug")!=argv[i]+strlen(argv[i])-4)
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
            if(strstr(argv[i],".bug")==NULL || strstr(argv[i],".bug")!=argv[i]+strlen(argv[i])-4)
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
        red_bug=convert(red_bug.c_str(),1);
        black_bug=convert(black_bug.c_str(),0);

        string s=file_world+" "+red_bug+" "+black_bug;
        World w;
        cout<<"Properly converted from assembler\n";
        cout<<"The string to be loaded "<<s<<"\n";
        w.load(s);
        cout<<"Properly loaded\n";
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
                    cout<<"\n";
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
                                if( c->mark.check_marker(tmark(ve),tcolor(1)))
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
                                id=b->get_progid();
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
                                if(b->get_food())
                                    cout<<"X";
                                else    
                                    cout<<"_";
                                cout<<b->get_direction().d<<" ";

                                state=b->get_state().st;
                                if(state<10)
                                    cout<<"0000"<<state<<" ";
                                else if(state<100)
                                    cout<<"000"<<state<<" ";
                                else if(state<1000)
                                    cout<<"00"<<state<<" ";
                                else
                                    cout<<"0"<<state<<" ";
                                
                                //print rest 0000 if rested 0014 if not
                                if(b->rested())
                                    cout<<"0000";
                                else
                                    cout<<"0001";
                            }
                            cout<<"\n";
                        }
                    }
                    cout<<"For cycle "<<i<<"the winners are the ";
                    if(winner.c==0)
                        cout<<"black bugs\n";
                    else
                        cout<<"red bugs\n";
                    cout<<"\n";
                }
                if(log==2)
                {
                    cout<<"The map initially looked like:\n";
                    w.print_grid();
                    cout<<"The map now looks like this in terms of food:\n";
                    for(int k=0;k<w.get_length();k++)
                    {
                        for(int j=0;k<w.get_width();j++)
                        {
                            Cell* c=w.get_cell(tposition(k,j));
                            if(c->get_char()=='#')
                                cout<<"#"<<" ";
                            else
                                cout<<c->get_food()<<" ";
                        }
                        cout<<endl;
                    }
                    cout<<"For cycle "<<i<<"the winners are the ";
                    if(winner.c==0)
                        cout<<"black bugs\n";
                    else
                        cout<<"red bugs\n";
                    cout<<"\n";
                    cout<<endl;
                }
            }
        }
    }
    return 0;
}