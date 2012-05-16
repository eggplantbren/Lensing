CFLAGS = -O2 -Wall -Wextra -ansi -pedantic -DNDEBUG

default: Array.o Grid.o

Array.o: Array.cpp Array.h
	g++ $(CFLAGS) -c Array.cpp

Grid.o: Grid.cpp Grid.h Array.h
	g++ $(CFLAGS) -c Grid.cpp

clean:
	rm -f *.o

