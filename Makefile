output: main.o
	gcc main.o -o bin/xdsy


main.o: main.c
	gcc -c main.c

