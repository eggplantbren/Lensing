CFLAGS = -O2 -Wall -Wextra -ansi -pedantic

default: Array.o

Array.o: Array.cpp Array.h
	g++ $(CFLAGS) -c Array.cpp

