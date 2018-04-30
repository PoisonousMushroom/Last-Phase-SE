#ifndef MARKER_H
#define MARKER_H

#include "Structs.h"

class Marker
{
public:

    /*
     * Constructor
     */
    Marker();

    /*
     * Set a marker here.
     * @param mark: Mark to be set
     * @param col: Color of the team
     */
    void set_marker(tmark mark, tcolor col);

    /*
     * Clear the marker set here
     * @param mark: Mark to be cleared
     * @param col: Color of the team
     */
    void clear_marker(tmark mark, tcolor col);

    /*
     * Check for a marker here.
     * @param mark: Mark to be cleared
     * @param col: Color of the team
     * @constraint: mark = 0...5
     */
    bool check_marker(tmark mark, tcolor col);

    /*
     * Check for any marker here.
     * @param col: Color of the team
     * @return bool: whether or not any marker is set.
     */
    bool check_other_marker(tcolor col);

private:

    /*
     * Variable to store information about the marker
     */
    int bits;
};


#endif
