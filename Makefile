# Development
#CFLAGS = -O0 -g -Wall -Wextra -ansi -pedantic

# Optimized
CFLAGS = -O2 -Wall -Wextra -ansi -pedantic -DNDEBUG

LIBS = -ldnest3 -lgsl -lgslcblas
SOURCES = Data.cpp Image.cpp Lens.cpp MeshGrid.cpp Profile.cpp Lenses/SIE.cpp Sources/Blobby.cpp
OBJECTS = Data.o Image.o Lens.o MeshGrid.o Profile.o SIE.o Blobby.o

default:
	# Compile all library components
	g++ $(CFLAGS) -c $(SOURCES)

	# Make static library
	ar rcs liblensing.a $(OBJECTS)

	# Build tests
	cd Tests; $(MAKE)

clean:
	rm -f *.o liblensing.a *.gch
	cd Tests; $(MAKE) clean;


