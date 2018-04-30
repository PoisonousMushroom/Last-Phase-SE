/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   WorldTest.h
 * Author: adamtouzani
 *
 * Created on Mar 5, 2018, 7:00:18 PM
 */

#ifndef WORLDTEST_H
#define WORLDTEST_H

#include <cppunit/extensions/HelperMacros.h>

#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>

#include <cppunit/Test.h>
#include <cppunit/TestFailure.h>
#include <cppunit/portability/Stream.h>

class WorldTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(WorldTest);

    CPPUNIT_TEST(testWorld);
    CPPUNIT_TEST(testLoad);
    CPPUNIT_TEST(testExecuteCycle);
    CPPUNIT_TEST(testGetCell);
    CPPUNIT_TEST(testAdjacent);
    CPPUNIT_TEST(testOtherColor);
    CPPUNIT_TEST(testWinner);
    CPPUNIT_TEST(testRedFood);
    CPPUNIT_TEST(testBlackFood);
    CPPUNIT_TEST(testThrowError);
    CPPUNIT_TEST(testLog);

    CPPUNIT_TEST_SUITE_END();

public:
    WorldTest();
    virtual ~WorldTest();
    void setUp();
    void tearDown();

private:
    void testWorld();
    void testLoad();
    void testExecuteCycle();
    void testGetCell();
    void testAdjacent();
    void testOtherColor();
    void testWinner();
    void testRedFood();
    void testBlackFood();
    void testThrowError();
    void testLog();

};

#endif /* WORLDTEST_H */

