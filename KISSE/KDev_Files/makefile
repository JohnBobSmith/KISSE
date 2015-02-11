SRCPATH = ../../src/source/

all: objects
	rm *.o
	
objects: main.o
	g++  main.o -o ./Win32Project4/SeizureTriangles -lstdc++ -march=x86-64 -msse4.1 -lsfml-graphics -lsfml-window -lsfml-system

%.o: $(SRCPATH)/%.cpp
	$(CC) $< -c -o $@ -std=c++11 -lstdc++ -march=x86-64 -msse4.1 -lsfml-graphics -lsfml-window -lsfml-system
	
clean: 
	rm *.o
