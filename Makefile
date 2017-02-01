class_basics: class-basics.cpp point.o
	g++ class-basics.cpp point.o -o class_basics

point.o: point.hpp point.cpp
	g++ -c point.cpp

clean:
	rm -f *.o class_basics
