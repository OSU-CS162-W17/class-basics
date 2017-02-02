# This is a special make rule that allows us to specify one or more targets
# to run whenever the command `make` is run without arguments.  Here, we make
# sure both executables are build when we run `make`.
all: point_stuff student_stuff

point_stuff: point-stuff.cpp point.o
	g++ point-stuff.cpp point.o -o point_stuff

point.o: point.hpp point.cpp
	g++ -c point.cpp

student_stuff: student-stuff.cpp student.o
	g++ student-stuff.cpp student.o -o student_stuff

student.o: student.hpp student.cpp
	g++ -c student.cpp

clean:
	rm -f *.o point_stuff student_stuff
