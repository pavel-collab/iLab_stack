sundbox:
	gcc -o sundbox sundbox.c
all:
	gcc -c stack.c
	gcc -c main.c
	gcc -o stack main.o stack.o