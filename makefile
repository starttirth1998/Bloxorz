
OPTS =  -lGL -lglfw -ldl -I"irrKlang-64bit-1.5.0/include" -L"/usr/lib" irrKlang-64bit-1.5.0/bin/linux-gcc-64/libIrrKlang.so -pthread

all: sample2D

sample2D: main.o init.o VAO.o create_object.o block.o
	g++ -o sample2D main.o init.o VAO.o create_object.o block.o glad.c $(OPTS)

main.o: main.cpp header.h main.h
	g++ -c main.cpp glad.c $(OPTS)

block.o: block.cpp header.h block.h
	g++ -c block.cpp glad.c $(OPTS)

create_object.o: create_object.cpp header.h create_object.h
	g++ -c create_object.cpp glad.c $(OPTS)

VAO.o: VAO.cpp header.h VAO.h
	g++ -c VAO.cpp glad.c $(OPTS)

init.o: init.cpp header.h init.h
	g++ -c init.cpp glad.c $(OPTS)

clean:
	rm sample2D
