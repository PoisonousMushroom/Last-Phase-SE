/* 
 * File:   Structs.h
 */

#ifndef STRUCTS_H
#define STRUCTS_H

struct tcolor {
    int color; //red = 0, black = 1
    tcolor() : color(0) {};
    tcolor(int x) : color(x) {};
    tcolor(bool x) {
      if(x)
        color = 1;
      else
        color = 0;
    };
};

struct tdirection {
    /* [0,5] */
    int direction;
    tdirection() : direction(-1) {};
    tdirection(int dir) : direction(dir) {};
};

struct tsensedir {
    /* [0,3] */
    int sensedir;
    tsensedir() : sensedir(-1) {};
    tsensedir(int x) : sensedir(x) {};
};

struct tleftright {
    /* left = 0, right = 1 */
    int leftright;
    tleftright() : leftright(-1) {};
    tleftright(int x) : leftright(x) {};
};

struct tmark {
    /* [0,5] */
    int mark;
    tmark() : mark(-1) {};
    tmark(int x) : mark(x) {};
};

struct tstate {
    int state;
    tstate() : state(-1) {};
    tstate(int st) : state(st) {};
};

struct tcondition {
    int condition;
    tcondition() : condition(-1) {};
    tcondition(int x) : condition(x) {};
};

struct tposition {
    int posX;
    int posY;
    tposition() : posX(-1), posY(-1) {};
    tposition(int x, int y) : posX(x), posY(y) {};
};

#endif

