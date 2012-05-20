# Development
#CFLAGS = -O0 -g -Wall -Wextra -ansi -pedantic

# Optimized
CFLAGS = -O2 -Wall -Wextra -ansi -pedantic -DNDEBUG

LIBS = -ldnest3 -lgsl -lgslcblas
SOURCES = Data.cpp Grid.cpp Lens.cpp Lenses/SIE.cpp Source.cpp
OBJECTS = Data.o Grid.o Lens.o SIE.o Source.o

default:
	# Compile all library components
	g++ $(CFLAGS) -c $(SOURCES)

	# Make static library
	ar rcs liblensing.a $(OBJECTS)

	# Build tests
	cd Tests; $(MAKE)

clean:
	rm -f *.o liblensing.a
	cd Tests; $(MAKE) clean;


