all:
	gcc -c functions.c
	gcc -c stack.c
	gcc -o stack stack.o functions.o