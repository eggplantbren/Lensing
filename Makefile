CFLAGS = -O0 -g -Wall -Wextra -ansi -pedantic # Development
# CFLAGS = -O2 -Wall -Wextra -ansi -pedantic -DNDEBUG # Optimized

default: liblensing.a tests

liblensing.a: Array.o Grid.o Lens.o SIE.o
	ar rcs liblensing.a Array.o Grid.o Lens.o SIE.o

Array.o: Array.cpp Array.h
	g++ $(CFLAGS) -c Array.cpp

Grid.o: Grid.cpp Grid.h Array.h
	g++ $(CFLAGS) -c Grid.cpp

Lens.o: Lens.cpp Lens.h
	g++ $(CFLAGS) -c Lens.cpp

SIE.o: Lenses/SIE.cpp Lenses/SIE.h Lens.h
	g++ $(CFLAGS) -c Lenses/SIE.cpp

tests: TestGrid TestSIE

TestGrid: Tests/TestGrid.cpp liblensing.a
	g++ $(CFLAGS) -c Tests/TestGrid.cpp
	g++ -o TestGrid TestGrid.o -llensing

TestSIE: Tests/TestSIE.cpp liblensing.a
	g++ $(CFLAGS) -c Tests/TestSIE.cpp
	g++ -o TestSIE TestSIE.o -llensing

clean:
	rm -f liblensing.a *.o Lenses/*.o TestGrid TestSIE


