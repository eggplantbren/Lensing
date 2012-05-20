# Development
#CFLAGS = -O0 -g -Wall -Wextra -ansi -pedantic

# Optimized
CFLAGS = -O2 -Wall -Wextra -ansi -pedantic -DNDEBUG
LIBS = -ldnest3 -lgsl -lgslcblas -llensing

default:
	# Compile
	g++ $(CFLAGS) -I .. -c TestSIE.cpp
	g++ $(CFLAGS) -I .. -c TestGrid.cpp

	# Link
	g++ -L .. -o TestSIE TestSIE.o $(LIBS)
	g++ -L .. -o TestGrid TestGrid.o $(LIBS)

clean:
	rm -f TestSIE TestGrid *.o

