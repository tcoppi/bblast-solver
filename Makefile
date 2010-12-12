CFLAGS=-g
LDFLAGS= -pthread

solver: main.o solver.o mtwist.o
	gcc $(CFLAGS) $(LDFLAGS) main.o solver.o mtwist.o -o solver

main.o: main.c bblast.h
	gcc -c $(CFLAGS) main.c

solver.o: solver.c bblast.h mtwist.h
	gcc -c $(CFLAGS) solver.c

mtwist.o: mtwist.c mtwist.h
	gcc -c $(CFLAGS) mtwist.c

clean:
	rm *.o solver
