sort: main.o list.o
	gcc -o sort main.o list.o
main.o: main.c list.h
	gcc -c main.c
list.o: list.c
	gcc -c list.c