# -*- MakeFile -*-

all: main log

main: main.o
	gcc main.o -o run

main.o: main.c
	gcc -c main.c

log: log.o
	gcc log.o

log.o: log.c
	gcc -c log.c

clear:
	rm *.o run
