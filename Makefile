CFLAGS=-O2 -march=amdfam10
LDFLAGS=

solver: main.o solver.o
	gcc $(CFLAGS) $(LDFLAGS) main.o solver.o -o solver

main.o: main.c bblast.h
	gcc -c $(CFLAGS) main.c

solver.o: solver.c bblast.h
	gcc -c $(CFLAGS) solver.c

clean:
	rm *.o solver
