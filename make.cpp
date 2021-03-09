#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("ERROR, expected more arguments!\n");
        return -1;
    }
    else if (!strcmp(argv[1], "protected")) {

        system("gcc -c -D DEBUG_MODE stack_f.c");
        system("gcc -c main.c\n");
        system("gcc -o main main.o stack_f.o\n");
        //system("./main");

    }
    else if (!strcmp(argv[1], "no_protected")) {

        system("gcc -c stack_f.c\n");
        system("gcc -c main.c\n");
        system("gcc -o main main.o stack_f.o\n");
        //system("./main");

    }
    else {
        printf("ERROR, expected another argument\n");
        return -1;
    }

}