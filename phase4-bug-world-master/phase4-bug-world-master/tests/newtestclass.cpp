/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newtestclass.cpp
 * Author: adamtouzani
 *
 * Created on Mar 5, 2018, 6:57:38 PM
 */

#include "newtestclass.h"
#include "Cell.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {
}

newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
}

void newtestclass::tearDown() {
}

void newtestclass::testCell() {
    char symb;
    Cell cell(symb);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testGetOccupant() {
    Cell cell;
    Bug result = cell.getOccupant();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testSetOccupant() {
    Bug newBug;
    Cell cell;
    cell.setOccupant(newBug);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testGetFood() {
    Cell cell;
    int result = cell.getFood();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testSetFood() {
    int newFood;
    Cell cell;
    cell.setFood(newFood);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testGetObstructed() {
    Cell cell;
    bool result = cell.getObstructed();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testIsBlackHomeArea() {
    Cell cell;
    bool result = cell.isBlackHomeArea();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testIsRedHomeArea() {
    Cell cell;
    bool result = cell.isRedHomeArea();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

