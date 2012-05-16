CFLAGS = -O0 -g -Wall -Wextra -ansi -pedantic

default: Grid

Grid:
	g++ $(CFLAGS) -I.. -c Grid.cpp
	g++ -L.. -o Grid Grid.o -llensing

clean:
	rm -f Grid *.o

