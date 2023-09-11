output: main.o
	gcc main.o -o xdsy


main.o: main.c
	gcc -c main.c

