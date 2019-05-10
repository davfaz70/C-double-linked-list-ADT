CMP = gcc
PROGRAM = vai!


default : link

link: compile
	$(CMP) -o $(PROGRAM) list.o main.o

compile:
	$(CMP) -c list.c main.c list.h

clean:
	@ rm *.o

run:
	 ./$(PROGRAM)
