/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#ifndef AUX_H
#define AUX_H

#include "exception.h"
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;
namespace aux{
    struct tcolor{
        int c; //0 or 1 for black or red
        tcolor(int x){
            if(x!=0&&x!=1)
                throw Exception("The color is not in proper boundaries\n");
            c=x;
        };
        tcolor():c(0){};
    };

    struct tdirection{
        int d;
        tdirection(int x){
            if(x<0||x>5)
                throw Exception("The direction is out of boundaries\n");
            d=x;
        };
        tdirection():d(0){};
        tdirection(string s)
        {
            d=0;
            for(int i=0;i<s.size();i++)
            {
                d=d*10+(s[i]-'0');
            }
            if(d<0||d>5)
                throw Exception("The direction is out of boundaries\n");
        }
    };

    struct tsensedir{
        int s;
        tsensedir(){
            s=0;
        }
        tsensedir(int x){
            if(x<0||x>3)
                throw Exception("The sense direction is out of boundaries\n");
            s=x;
        };
        tsensedir(string a){
            std::transform(a.begin(), a.end(), a.begin(), ::tolower);
            if(a=="here")
                s=0;
            else if(a=="ahead")
                s=1;
            else if(a=="leftahead")
                s=2;
            else if(a=="rightahead")
                s=3;
            else
            throw Exception("The sense direction is out of boundaries\n");
        };
    };

    struct tleftright{
        int l;
        tleftright(int x){
            if(x!=0&&x!=1)
                throw Exception("The leftright parameter is out of boundaries\n");
            l=x;
        };
        tleftright(string s)
        {
            std::transform(s.begin(), s.end(), s.begin(), ::tolower);
            if(s=="left")
                l=0;
            else if(s=="right")
                l=1;
            else
                throw Exception("The leftright parameter is out of boundaries\n");
        }
        tleftright(){
            l=0;
        }
    };

    struct tmark{
        int m;
        tmark():m(0){};
        tmark(int x){
            if(x<0||x>5)
                throw Exception("The mark is out of boundaries\n");
            m=x;
        };
    };

    struct tstate{
        int st;
        tstate(int x):st(x){
            if(st<0||st>9999)
                throw Exception("The state is out of boundaries\n");
        };
        tstate():st(0){};
        tstate(string x){
            st=0;
            for(int i=0;i<x.size();i++)
            {
                st=st*10+(x[i]-'0');
            }
            if(st<0||st>9999)
                throw Exception("The state is out of boundaries\n");
        };
    };

    struct tcondition{
        /**/
        int cond;
        tcondition():cond(0){};
        tcondition(int x):cond(x){};
        tcondition(string s)
        {
            std::transform(s.begin(), s.end(), s.begin(), ::tolower);
            if(s=="friend")
                cond=0;
            else if(s=="foe")
                cond=1;
            else if(s=="friendwithfood")
                cond=2;
            else if(s=="foewithfood")
                cond=3;
            else if(s=="food")
                cond=4;
            else if(s=="rock")
                cond=5;
            else if(s=="marker(0)")
                cond=6;
            else if(s=="marker(1)")
                cond=7;
            else if(s=="foemarker")
                cond=8;
            else if(s=="home")
                cond=9;
            else if(s=="foehome")
                cond=10;
            else if(s=="marker(2)")
                cond=11;
            else if(s=="marker(3)")
                cond=12;
            else if(s=="marker(4)")
                cond=13;
            else if(s=="marker(5)")
                cond=14;
            else throw Exception("Unspecified condition\n");
        }
    };

    struct tposition{
        int x;
        int y;
        tposition(int t, int q):x(t),y(q){};
        tposition():x(0),y(0){};
    };
};
#endif /* AUX_H */
