/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newtestclass.h
 * Author: adamtouzani
 *
 * Created on Mar 5, 2018, 6:57:37 PM
 */

#ifndef NEWTESTCLASS_H
#define NEWTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass);

    CPPUNIT_TEST(testCell);
    CPPUNIT_TEST(testGetOccupant);
    CPPUNIT_TEST(testSetOccupant);
    CPPUNIT_TEST(testGetFood);
    CPPUNIT_TEST(testSetFood);
    CPPUNIT_TEST(testGetObstructed);
    CPPUNIT_TEST(testIsBlackHomeArea);
    CPPUNIT_TEST(testIsRedHomeArea);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass();
    virtual ~newtestclass();
    void setUp();
    void tearDown();

private:
    void testCell();
    void testGetOccupant();
    void testSetOccupant();
    void testGetFood();
    void testSetFood();
    void testGetObstructed();
    void testIsBlackHomeArea();
    void testIsRedHomeArea();

};

#endif /* NEWTESTCLASS_H */

