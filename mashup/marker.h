/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef MARKER_H
#define MARKER_H

#include "aux.h"
#ifdef __cplusplus
extern "C" {
#endif
    class Marker{ //TODO have code in the source file instead of the header file
    private:
        unsigned int bits;
    public:
        Marker();        
        void set_marker(aux::tmark mark, aux::tcolor color);
        void clear_marker(aux::tmark mark, aux::tcolor color);
        bool check_marker(aux::tmark mark, aux::tcolor color);
        bool check_other_marker(aux::tcolor color);
    };



#ifdef __cplusplus
}
#endif

#endif /* MARKER_H */
