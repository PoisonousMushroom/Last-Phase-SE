#include "WorldTest.h"
#include "../World.h"


CPPUNIT_TEST_SUITE_REGISTRATION(WorldTest);

WorldTest::WorldTest() {
}

WorldTest::~WorldTest() {
}

void WorldTest::setUp() {
}

void WorldTest::tearDown() {
}

void WorldTest::testWorld() {
    World world();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void WorldTest::testLoad() {
    std::string filename;
    World world;
    world.load(filename);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void WorldTest::testExecuteCycle() {
    World world;
    world.executeCycle();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void WorldTest::testGetCell() {
    tposition pos;
    World world;
    Cell result = world.getCell(pos);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void WorldTest::testAdjacent() {
    tposition pos;
    tdirection dir;
    World world;
    tposition result = world.adjacent(pos, dir);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void WorldTest::testOtherColor() {
    tcolor color;
    World world;
    tcolor result = world.otherColor(color);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void WorldTest::testWinner() {
    World world;
    tcolor result = world.winner();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void WorldTest::testRedFood() {
    World world;
    int result = world.redFood();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void WorldTest::testBlackFood() {
    World world;
    int result = world.blackFood();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void WorldTest::testThrowError() {
    std::string errMsg;
    World world;
    world.throwError(errMsg);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void WorldTest::testLog() {
    std::string logMsg;
    World world;
    world.log(logMsg);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

