CFLAGS = -O0 -g -Wall -Wextra -ansi -pedantic # Development
# CFLAGS = -O2 -Wall -Wextra -ansi -pedantic -DNDEBUG # Optimized

default: liblensing.a tests

liblensing.a: Data.o Grid.o Lens.o SIE.o Source.o
	ar rcs liblensing.a Data.o Grid.o Lens.o SIE.o Source.o

Data.o: Data.cpp Data.h Array.h ArrayImpl.h
	g++ $(CFLAGS) -c Data.cpp

Grid.o: Grid.cpp Grid.h Array.h ArrayImpl.h
	g++ $(CFLAGS) -c Grid.cpp

Lens.o: Lens.cpp Lens.h Grid.h Array.h ArrayImpl.h
	g++ $(CFLAGS) -c Lens.cpp

SIE.o: Lenses/SIE.cpp Lenses/SIE.h Lens.h
	g++ $(CFLAGS) -c Lenses/SIE.cpp

Source.o: Source.cpp Source.h Grid.h Array.h ArrayImpl.h
	g++ $(CFLAGS) -c Source.cpp

tests: TestGrid TestSIE

TestGrid: Tests/TestGrid.cpp liblensing.a
	g++ $(CFLAGS) -c Tests/TestGrid.cpp
	g++ -o TestGrid TestGrid.o -llensing

TestSIE: Tests/TestSIE.cpp liblensing.a
	g++ $(CFLAGS) -c Tests/TestSIE.cpp
	g++ -o TestSIE TestSIE.o -llensing

clean:
	rm -f liblensing.a *.o Lenses/*.o TestGrid TestSIE

