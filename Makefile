CFLAGS = -O0 -g -Wall -Wextra -ansi -pedantic
# CFLAGS = -O2 -Wall -Wextra -ansi -pedantic -DNDEBUG

default: liblensing.a tests

liblensing.a: Array.o Grid.o Lens.o
	ar rcs liblensing.a Array.o Grid.o Lens.o

Array.o: Array.cpp Array.h
	g++ $(CFLAGS) -c Array.cpp

Grid.o: Grid.cpp Grid.h Array.h
	g++ $(CFLAGS) -c Grid.cpp

Lens.o: Lens.cpp Lens.h
	g++ $(CFLAGS) -c Lens.cpp

tests:
	cd Tests; $(MAKE)

clean:
	rm -f liblensing.a *.o
	cd Tests; $(MAKE) clean;

