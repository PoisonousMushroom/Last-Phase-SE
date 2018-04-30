/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Tests.cpp
 * Author: adamtouzani
 *
 * Created on Mar 5, 2018, 6:59:22 PM
 */

#include "CellTest.h"
#include "../Cell.h"


CPPUNIT_TEST_SUITE_REGISTRATION(Tests);

Tests::Tests() {
}

Tests::~Tests() {
}

void Tests::setUp() {
}

void Tests::tearDown() {
}

void Tests::testCell() {
    char symb;
    Cell cell(symb);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void Tests::testGetOccupant() {
    Cell cell;
    Bug result = cell.getOccupant();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void Tests::testSetOccupant() {
    Bug newBug;
    Cell cell;
    cell.setOccupant(newBug);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void Tests::testGetFood() {
    Cell cell;
    int result = cell.getFood();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void Tests::testSetFood() {
    int newFood;
    Cell cell;
    cell.setFood(newFood);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void Tests::testGetObstructed() {
    Cell cell;
    bool result = cell.getObstructed();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void Tests::testIsBlackHomeArea() {
    Cell cell;
    bool result = cell.isBlackHomeArea();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void Tests::testIsRedHomeArea() {
    Cell cell;
    bool result = cell.isRedHomeArea();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

