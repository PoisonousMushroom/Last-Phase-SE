CC=g++
CFLAGS = -lcppunit

all: testBug testCell testMarker

testBug:
	$(CC) -o testBug BugTest.cpp ../Bug.cpp BugTestRunner.cpp $(CFLAGS)

testCell:
	$(CC) -o testCell CellTest.cpp ../Cell.cpp ../Bug.cpp CellTestRunner.cpp $(CFLAGS)

testMarker:
	$(CC) -o testMarker MarkerTest.cpp ../Marker.cpp MarkerTestRunner.cpp $(CFLAGS)

clean:
	rm -f testBug testCell testMarker
