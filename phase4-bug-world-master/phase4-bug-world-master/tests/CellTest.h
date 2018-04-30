#ifndef TESTS_H
#define TESTS_H

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

class Tests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(Tests);

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
    Tests();
    virtual ~Tests();
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

#endif /* TESTS_H */

